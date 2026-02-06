// dh_aes_demo.c
// Simpel demo: Diffie-Hellman nøgleudveksling + AES-256-CBC kryptering/dekryptering
// Compile: gcc -o dh_aes_demo dh_aes_demo.c -lcrypto
// Kører: ./dh_aes_demo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/err.h>

/* Hjælpefunktioner */
void handle_errors(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    ERR_print_errors_fp(stderr);
    exit(1);
}

/* AES-256-CBC krypteringsfunktion (EVP) */
int aes_256_cbc_encrypt(const unsigned char *plaintext, int plaintext_len,
                        const unsigned char *key, const unsigned char *iv,
                        unsigned char **ciphertext) {
    EVP_CIPHER_CTX *ctx = NULL;
    int len, ciphertext_len;

    *ciphertext = malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
    if (!*ciphertext) return -1;

    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handle_errors("EVP_CIPHER_CTX_new failed");

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handle_errors("EVP_EncryptInit_ex failed");

    if (1 != EVP_EncryptUpdate(ctx, *ciphertext, &len, plaintext, plaintext_len))
        handle_errors("EVP_EncryptUpdate failed");
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, *ciphertext + len, &len))
        handle_errors("EVP_EncryptFinal_ex failed");
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

/* AES-256-CBC dekrypteringsfunktion (EVP) */
int aes_256_cbc_decrypt(const unsigned char *ciphertext, int ciphertext_len,
                        const unsigned char *key, const unsigned char *iv,
                        unsigned char **plaintext) {
    EVP_CIPHER_CTX *ctx = NULL;
    int len, plaintext_len;

    *plaintext = malloc(ciphertext_len + EVP_MAX_BLOCK_LENGTH);
    if (!*plaintext) return -1;

    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handle_errors("EVP_CIPHER_CTX_new failed (dec)");

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handle_errors("EVP_DecryptInit_ex failed (dec)");

    if (1 != EVP_DecryptUpdate(ctx, *plaintext, &len, ciphertext, ciphertext_len))
        handle_errors("EVP_DecryptUpdate failed (dec)");
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, *plaintext + len, &len))
        handle_errors("EVP_DecryptFinal_ex failed (dec)");
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main(void) {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();

    printf("=== DH + AES-256 demo ===\n");

    /* 1) Generer Diffie-Hellman parametre (modul p og generator g)
       Bemærk: generering af store parametre kan være langsomt; til demo bruger vi 2048-bit. */
    int prime_len = 2048;
    DH *dh_params = DH_new();
    if (!dh_params) handle_errors("DH_new failed");

    printf("[*] Generating DH parameters (%d bits) ... (kan tage et par sekunder)\n", prime_len);
    if (1 != DH_generate_parameters_ex(dh_params, prime_len, DH_GENERATOR_2, NULL))
        handle_errors("DH_generate_parameters_ex failed");

    /* 2) Alice genererer sin nøglepair */
    DH *alice = DH_new();
    if (!alice) handle_errors("DH_new alice failed");
    if (1 != DH_set0_pqg(alice,
                         BN_dup(DH_get0_p(dh_params)),
                         NULL,
                         BN_dup(DH_get0_g(dh_params))))
        handle_errors("DH_set0_pqg (alice) failed");
    if (1 != DH_generate_key(alice)) handle_errors("DH_generate_key (alice) failed");

    /* 3) Bob genererer sin nøglepair (samme parametre) */
    DH *bob = DH_new();
    if (!bob) handle_errors("DH_new bob failed");
    if (1 != DH_set0_pqg(bob,
                         BN_dup(DH_get0_p(dh_params)),
                         NULL,
                         BN_dup(DH_get0_g(dh_params))))
        handle_errors("DH_set0_pqg (bob) failed");
    if (1 != DH_generate_key(bob)) handle_errors("DH_generate_key (bob) failed");

    /* 4) Udregn delt hemmelighed */
    const BIGNUM *alice_pub = NULL, *alice_priv = NULL;
    const BIGNUM *bob_pub = NULL, *bob_priv = NULL;
    DH_get0_key(alice, &alice_pub, &alice_priv);
    DH_get0_key(bob, &bob_pub, &bob_priv);

    int secret_size = DH_size(alice);
    unsigned char *secret_alice = malloc(secret_size);
    unsigned char *secret_bob = malloc(secret_size);
    if (!secret_alice || !secret_bob) handle_errors("malloc failed for secrets");

    int secret_len_a = DH_compute_key(secret_alice, bob_pub, alice);
    if (secret_len_a < 0) handle_errors("DH_compute_key (alice) failed");
    int secret_len_b = DH_compute_key(secret_bob, alice_pub, bob);
    if (secret_len_b < 0) handle_errors("DH_compute_key (bob) failed");

    if (secret_len_a != secret_len_b || memcmp(secret_alice, secret_bob, secret_len_a) != 0) {
        fprintf(stderr, "Delte hemmeligheder matcher ikke!\n");
        return 1;
    }
    printf("[+] DH shared secret udledt (%d bytes)\n", secret_len_a);

    /* 5) Afled en AES-256 nøgle fra den delte hemmelighed med SHA-256 (KDF simpel version) */
    unsigned char aes_key[32]; // 256-bit
    if (!SHA256(secret_alice, secret_len_a, aes_key)) handle_errors("SHA256 failed");
    printf("[+] AES-256 nøgle afledt via SHA-256\n");

    /* 6) Krypter en besked med AES-256-CBC */
    const char *msg = "Dette er en testbesked krypteret med AES-256 efter DH nøgleudveksling.";
    int msg_len = strlen(msg);

    unsigned char iv[16];
    if (1 != RAND_bytes(iv, sizeof(iv))) handle_errors("RAND_bytes (IV) failed");

    unsigned char *ciphertext = NULL;
    int ciphertext_len = aes_256_cbc_encrypt((unsigned char*)msg, msg_len, aes_key, iv, &ciphertext);
    if (ciphertext_len < 0) handle_errors("aes_256_cbc_encrypt failed");
    printf("[+] Tekst krypteret (%d bytes)\n", ciphertext_len);

    /* 7) Dekrypter beskeden (brug samme nøgle og IV) */
    unsigned char *decrypted = NULL;
    int decrypted_len = aes_256_cbc_decrypt(ciphertext, ciphertext_len, aes_key, iv, &decrypted);
    if (decrypted_len < 0) handle_errors("aes_256_cbc_decrypt failed");

    /* Null-terminer og udskriv */
    decrypted[decrypted_len] = '\0';
    printf("[+] Dekrypteret tekst: %s\n", decrypted);

    /* Oprydning */
    free(ciphertext);
    free(decrypted);
    free(secret_alice);
    free(secret_bob);
    DH_free(alice);
    DH_free(bob);
    DH_free(dh_params);

    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();

    return 0;
}

/* toy_mceliece.c
   Educational toy McEliece example (binary arithmetic mod 2).
   k = 2 (message length), n = 4 (codeword length).
   Compile: gcc -std=c11 -O2 -o toy_mceliece toy_mceliece.c
   Run: ./toy_mceliece
*/

#include <stdio.h>
#include <stdlib.h>

#define K 2
#define N 4

/* Helper: print vector length n */
void print_vec(const char *label, int v[], int n) {
    printf("%s: [", label);
    for (int i = 0; i < n; ++i) {
        printf("%d", v[i] & 1);
        if (i+1 < n) printf(",");
    }
    printf("]\n");
}

/* Multiply A (r x c) by B (c x t) => out (r x t), all mod 2 */
void mat_mul(int r, int c, int t, const int A[][N], const int B[][N], int out[][N]) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < t; ++j) {
            int s = 0;
            for (int x = 0; x < c; ++x) s ^= (A[i][x] & B[x][j]); // mod2 sum -> XOR of ANDs
            out[i][j] = s & 1;
        }
    }
}

/* Multiply 1 x k vector v by k x n matrix M -> result 1 x n (stored in out[]) */
void vec_mul_mat_k_n(int v[], const int M[K][N], int out[], int k, int n) {
    for (int j = 0; j < n; ++j) {
        int s = 0;
        for (int i = 0; i < k; ++i) s ^= (v[i] & M[i][j]);
        out[j] = s & 1;
    }
}

/* Multiply 1 x k vector by k x 2 (for S which is k x k) -> out len k */
void vec_mul_mat_k_k(int v[], const int M[K][K], int out[]) {
    for (int j = 0; j < K; ++j) {
        int s = 0;
        for (int i = 0; i < K; ++i) s ^= (v[i] & M[i][j]);
        out[j] = s & 1;
    }
}

/* Hamming distance between two length-n vectors */
int hamming_dist(int a[], int b[], int n) {
    int d = 0;
    for (int i = 0; i < n; ++i) if ((a[i] & 1) != (b[i] & 1)) d++;
    return d;
}

/* Apply permutation perm (length n) to vector v -> out.
   perm[j] = index in source that becomes position j in result.
   For example, if perm = {1,3,0,2}, then out[0] = v[1], out[1] = v[3], ... */
void apply_perm(int v[], int out[], int perm[], int n) {
    for (int j = 0; j < n; ++j) out[j] = v[perm[j]] & 1;
}

/* Compute inverse permutation: invperm[perm[j]] = j */
void invert_perm(int perm[], int invperm[], int n) {
    for (int j = 0; j < n; ++j) invperm[perm[j]] = j;
}

/* Invert a k x k matrix over GF(2) using Gauss-Jordan. Input M (k x k), output Inv (k x k). 
   Returns 1 on success, 0 on failure (singular). */
int invert_gf2(const int M[K][K], int Inv[K][K]) {
    int aug[K][2*K];
    // build augmented matrix [M | I]
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) aug[i][j] = M[i][j] & 1;
        for (int j = 0; j < K; ++j) aug[i][K+j] = (i==j) ? 1 : 0;
    }

    // Gauss-Jordan
    for (int col = 0; col < K; ++col) {
        // find pivot row with a 1 in this column
        int pivot = -1;
        for (int r = col; r < K; ++r) if (aug[r][col]) { pivot = r; break; }
        if (pivot == -1) return 0; // singular

        // swap if needed
        if (pivot != col) {
            for (int c = 0; c < 2*K; ++c) {
                int tmp = aug[col][c]; aug[col][c] = aug[pivot][c]; aug[pivot][c] = tmp;
            }
        }

        // eliminate other rows
        for (int r = 0; r < K; ++r) {
            if (r == col) continue;
            if (aug[r][col]) {
                // row r = row r XOR row col
                for (int c = 0; c < 2*K; ++c) aug[r][c] ^= aug[col][c];
            }
        }
    }

    // extract inverse
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            Inv[i][j] = aug[i][K+j] & 1;

    return 1;
}

/* Brute-force decode: given received r (length n), secret G (k x n), max correctable t
   try all 2^k possible messages m', compute c0 = m'*G and pick the m' with smallest hamming distance.
   If distance <= t return that m'; else return best anyway (for demonstration) */
void brute_force_decode(int r[], const int G[K][N], int decoded_m[], int k, int n, int t) {
    int best_m[K]; for (int i=0;i<k;i++) best_m[i]=0;
    int best_d = n+1;
    int maxm = 1 << k;
    int c0[N];
    for (int mval = 0; mval < maxm; ++mval) {
        int m[K];
        for (int i = 0; i < k; ++i) m[i] = (mval >> (k-1-i)) & 1; // big-endian bits
        vec_mul_mat_k_n(m, G, c0, k, n);
        int d = hamming_dist(c0, r, n);
        if (d < best_d) {
            best_d = d;
            for (int i=0;i<k;i++) best_m[i] = m[i];
        }
        if (best_d == 0) break;
    }
    for (int i=0;i<k;i++) decoded_m[i] = best_m[i];
}

/* MAIN: demonstrates toy McEliece flow */
int main(void) {
    /* Secret generator matrix G (2x4) -- same as in our toy example */
    const int G[K][N] = {
        {1,0,1,1},
        {0,1,1,0}
    };

    /* Secret scrambler S (2x2) */
    const int S[K][K] = {
        {1,1},
        {0,1}
    };

    /* Permutation P expressed as perm array:
       earlier we used new column order [2,4,1,3] (1-based)
       zero-based that is [1,3,0,2].
       perm[j] = source index for new column j
    */
    const int perm[N] = {1,3,0,2};
    int invperm[N];
    invert_perm((int*)perm, invperm, N);

    /* Compute SG = S * G (2x4) */
    int SG[K][N];
    // manual multiply since sizes small
    for (int i=0;i<K;i++) for (int j=0;j<N;j++) {
        int s = 0;
        for (int x=0;x<K;x++) s ^= (S[i][x] & G[x][j]);
        SG[i][j] = s & 1;
    }

    /* Compute G' by permuting columns of SG according to perm[]:
       G'[:,j] = SG[:, perm[j]]  */
    int Gp[K][N];
    for (int j=0;j<N;j++) {
        int src = perm[j];
        for (int i=0;i<K;i++) Gp[i][j] = SG[i][src] & 1;
    }

    /* Print matrices */
    printf("Secret generator G:\n");
    for (int i=0;i<K;i++) { print_vec("G row", (int*)G[i], N); }
    printf("\nScrambler S:\n");
    for (int i=0;i<K;i++) { print_vec("S row", (int*)S[i], K); }
    printf("\nSG = S*G:\n");
    for (int i=0;i<K;i++) print_vec("SG row", SG[i], N);

    printf("\nPermutation perm (new col j comes from old index): [");
    for (int j=0;j<N;j++) { printf("%d", perm[j]); if (j+1<N) printf(","); }
    printf("]\n");

    printf("\nPublic key G' (S*G*P):\n");
    for (int i=0;i<K;i++) print_vec("G' row", Gp[i], N);
    printf("\n");

    /* Example message m (length k) */
    int m[K] = {1,0}; /* same as example */
    print_vec("Plaintext m", m, K);

    /* Encrypt: c = m * G' */
    int c[N];
    vec_mul_mat_k_n(m, Gp, c, K, N);
    print_vec("Encoded c = m*G'", c, N);

    /* Add error e (single-bit error at pos 3 for example) */
    int e[N] = {0,0,0,1};
    print_vec("Error e", e, N);

    int cipher[N];
    for (int i=0;i<N;i++) cipher[i] = (c[i] ^ e[i]) & 1;
    print_vec("Ciphertext sent", cipher, N);
    printf("\n--- Now decryption ---\n");

    /* Decryption step 1: undo permutation P (apply inverse perm to ciphertext) */
    int cipher_unperm[N];
    apply_perm(cipher, cipher_unperm, invperm, N); // invperm maps back to original order
    print_vec("After undoing P (perm^-1)", cipher_unperm, N);

    /* Decryption step 2: decode using secret G (brute-force nearest) */
    int decoded_mprime[K];
    int t = 1; // max correctable errors (toy)
    brute_force_decode(cipher_unperm, G, decoded_mprime, K, N, t);
    print_vec("Decoded m' (after decoding)", decoded_mprime, K);

    /* Decryption step 3: undo S: compute S^-1 * m' */
    int Sinv[K][K];
    if (!invert_gf2(S, Sinv)) {
        fprintf(stderr, "Error: S is singular!\n");
        return 1;
    }
    int recovered[K];
    vec_mul_mat_k_k(decoded_mprime, Sinv, recovered);
    print_vec("Recovered plaintext m (after S^-1)", recovered, K);

    /* Show result */
    int ok = 1;
    for (int i=0;i<K;i++) if ((recovered[i] & 1) != (m[i] & 1)) ok = 0;
    printf("\nRecovery %s\n", ok ? "SUCCESS" : "FAIL");

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
    char text[250];
    int keySpaces;

    char gamemode[15];
    char answer[40];

    printf("Welcome to ciphers \n");
    printf("Do you want to encrypt or decrypt something? \n");
    printf("1. encrypter \n");
    printf("2. decrypter \n");
    
    scanf(" %14s", gamemode);
    getchar(); // rydder '\n' fra buffer



    if(strcmp(gamemode, "encrypter") == 0 || 
        strcmp(gamemode, "1") == 0){
    
        printf("Write text for encryptions: \n");
    
    // Læs en linje tekst fra brugeren og gem den i 'text' arrayet
    // sizeof(text) sikrer, at vi ikke overskriver arrayet
    // stdin betyder, at input kommer fra standard input (tastatur)
    //scanf(" %249s", text);
  
    fgets(text, sizeof(text), stdin);

    // fjerner linjeskiftet (\n), som fgets automatisk inkluderer
    // strcspn(text, "\n") finder positionen af '\n' i teksten
    // sætter '\n' til nul-terminator '\0', så strengen slutter korrekt
    text[strcspn(text, "\n")] = 0;

    //Amount of spaces you want to move the key
    printf("Write key: \n");
    scanf("%d", &keySpaces);

    
    //for (int i = 0; i < strlen(tekst); i++) – Gennemløber hvert tegn i teksten.
    //char c = tekst[i]; – Gemmer det aktuelle tegn i en midlertidig variabel for nemheds skyld.
        for (int i = 0; i < strlen(text); i++) {
            char c = text[i];

            // c - 'a' – Konverterer bogstavet til et tal mellem 0–25 (a=0, b=1, ... z=25).
            // + nøgler – Rykker bogstavet frem med nøglen.
            // % 26 – Wraps rundt, så vi ikke går ud over 'z'. Eksempel: 'z' + 3 → 'c'.
            // + 'a' – Konverterer tallet tilbage til ASCII for at få bogstavet igen.
            
            if (c >= 'a' && c <= 'z'){
                text[i] = ((c - 'a' + keySpaces) % 26) + 'a';
            } else if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' + keySpaces) % 26) + 'A';
            } else if (c >= '0' && c <= '9') {
            text[i] = ((c - '0' + keySpaces) % 10) + '0';
            }
        }

        //answer[40] = "The encrypted version";
        strcpy(answer, "The encrypted version");

    } else if (strcmp(gamemode, "decrypter") == 0 || 
        strcmp(gamemode, "2") == 0) {
             printf("Write text for decryptions: \n");
    
    // Læs en linje tekst fra brugeren og gem den i 'text' arrayet
    // sizeof(text) sikrer, at vi ikke overskriver arrayet
    // stdin betyder, at input kommer fra standard input (tastatur)
    fgets(text, sizeof(text),stdin);

    // fjerner linjeskiftet (\n), som fgets automatisk inkluderer
    // strcspn(text, "\n") finder positionen af '\n' i teksten
    // sætter '\n' til nul-terminator '\0', så strengen slutter korrekt
    text[strcspn(text, "\n")] = 0;

    //Amount of spaces you want to move the key
    printf("Write key: \n");
    scanf("%d", &keySpaces);

    
    //for (int i = 0; i < strlen(tekst); i++) – Gennemløber hvert tegn i teksten.
    //char c = tekst[i]; – Gemmer det aktuelle tegn i en midlertidig variabel for nemheds skyld.
        for (int i = 0; i < strlen(text); i++) {
            char c = text[i];

            // c - 'a' – Konverterer bogstavet til et tal mellem 0–25 (a=0, b=1, ... z=25).
            // + nøgler – Rykker bogstavet frem med nøglen.
            // % 26 – Wraps rundt, så vi ikke går ud over 'z'. Eksempel: 'z' + 3 → 'c'.
            // + 'a' – Konverterer tallet tilbage til ASCII for at få bogstavet igen.
            
            if (c >= 'a' && c <= 'z'){
                text[i] = ((c - 'a' - keySpaces + 26) % 26) + 'a';
            } else if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' - keySpaces + 26) % 26) + 'A';
            } else if (c >= '0' && c <= '9') {
            text[i] = ((c - '0' - keySpaces + 10) % 10) + '0';
            }
        }
        //answer[40] = "The decrypted version";
        strcpy(answer, "The decrypted version");

    }

    printf("%s: %s \n", answer, text);

    return 0;

}
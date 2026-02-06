/*
#include <stdio.h>
#include <string.h>
#include <process.h> // Windows-version af exec/fork

int main() {
    char program[50];
    
    printf(
        "Please enter which program you want to run\n"
        "Choose by number or name:\n"
        "1. secondsConverter\n"
        "2. encrypter\n"
    );

    scanf("%49s", program); // læs input, max 49 tegn

    if (strcmp(program, "secondsConverter") == 0 || strcmp(program, "1") == 0) {
        // Kør secondsConverter.exe
        _spawnlp(_P_WAIT, "secondsConverterFinal.exe", "secondsConverterFinal.exe", NULL);
    }else if (strcmp(program, "encrypter") == 0 || strcmp(program, "2") == 0) {
        // Kør encrypter.exe
        _spawnlp(_P_WAIT, "encrypter.exe", "encrypter.exe", NULL);
    }else {
        printf("Unknown program selection.\n");
    }

    return 0;
}

*/

#include <stdio.h>
#include <unistd.h> // Apple-version af exec/fork
#include <string.h>
#include <sys/wait.h> // Husk denne til wait()

int main() {
    char program[20];

    printf("Enter the program you want to run:\n");
    printf("1. secondsConverter\n");
    printf("2. encrypter\n");
    printf("3. rock paper scissor (rps)\n");
    printf("4. vectorCalculator (vector)\n");
    scanf("%s", program);

    if (strcmp(program, "secondsConverter") == 0 || strcmp(program, "1") == 0) {
        pid_t pid = fork(); // opret et nyt process
        if (pid == 0) {
            execl("./secondsConverterFinal", "secondsConverterFinal", NULL);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    } else if (strcmp(program, "encrypter") == 0 || strcmp(program, "2") == 0) {
        pid_t pid = fork();
        if (pid == 0) {
            execl("./encrypter", "encrypter", NULL);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    } else if (strcmp(program, "rps") == 0 ||
               strcmp(program, "3") == 0) {
        pid_t pid = fork();
        if (pid == 0) {
            execl("./rps", "rps", NULL);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    } else if (strcmp(program, "vector") == 0 ||
               strcmp(program, "4") == 0) {
        pid_t pid = fork();
        if (pid == 0) {
            execl("./vectorCalculatorOptimized", "vectorCalculatorOptimized", NULL);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    }

    return 0;
}



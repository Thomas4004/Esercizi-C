#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 3

int isPalindromo(char parola[]);

int main() {
    char parole[N][200];
    
    printf("Inserisci tre parole:\n");
    
    int i;
    for (i = 0; i < N; i++) {
        do {
            printf("Parola %d: ", i + 1);
            fgets(parole[i], 200, stdin);
            parole[i][strcspn(parole[i], "\n")] = '\0';
        } while(strlen(parole[i]) == 0);
    }

    printf("\nLe parole inserite sono:\n");
    for (i = 0; i < N; i++) {
        printf("%s ", parole[i]);
    }

    printf("\n\n");
    for(i = 0; i < N; i++){
        int verifica = isPalindromo(parole[i]);
        if(verifica == 1){
            printf("\nLa parola %s e' palindroma!", parole[i]);
        }else{
            printf("\nLa parola %s non e' palindroma", parole[i]);
        }
    }

    return 0;
}

int isPalindromo(char parola[]) {
    int len = strlen(parola);
    int i;
    int verifica;
    for (i = 0; i < len / 2; i++) {
        if (parola[i] != parola[len - i - 1]) {
            verifica = 0;
            return verifica;
        }
    }
    verifica = 1;
    return verifica;
}
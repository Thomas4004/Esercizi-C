#include <stdio.h>
#include <string.h>

#define N 3

int contaVocali(char parola[]);

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
    for (i = 0; i < N; i++){
        int numVocali = contaVocali(parole[i]);
        printf("\nIl numero di vocali della parola %s e' %d", parole[i], numVocali);
    }

    return 0;
}

int contaVocali(char parola[]) {
    int count = 0;
    int i;
    for (i = 0; parola[i] != '\0'; i++) {
        char c = parola[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}
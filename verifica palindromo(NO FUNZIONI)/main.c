#include <stdio.h>
#include <string.h>

#define N 3

int main(){
    char parole[N][200];
    int i, j;
    printf("Inserisci %d parole\n", N);
    for(i = 0; i<N; i++){
        do{
            printf("\nInserisci la parola %d: ", i+1);
            gets(parole[i]);
        }while(strlen(parole[i]) == 0);
    }

    //verifico se è un palindromo
    printf("\n");
    for(i = 0; i<N; i++){
        int len = strlen(parole[i]);
        int sentinella = 0;
        for (j = 0; j < len / 2; j++) { //scorro la parola solo fino a metà
            if (parole[i][j] != parole[i][len - j - 1]) { //verifico le coppie
                //alla prima esecuzione verificherà la prima e l'ultima lettera, poi la seconda e la penultima, poi la terza e la terz'ultima e così via
                printf("\nLa parola %s non e' un palindromo!", parole[i]);
                sentinella = 1;
                break;
            }
        }
        if(sentinella == 0){
            printf("\nLa parola %s e' un palindromo!", parole[i]);
        }
    }
}
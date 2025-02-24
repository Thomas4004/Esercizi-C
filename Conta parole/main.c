#include <stdio.h>
#include <string.h>

#define N 3

int main() {
    char parole[N][200];
    char parolaConcatenata[999];

    printf("\n\n");
    int i;
    int j;
    for (i = 0; i < N; i++){
        do{
            printf("Inserisci parola %d: ", i + 1);
            //scanf("%s", &parole[i]);
            gets(parole[i]);
            printf("\n");
        }while(strlen(parole[i]) == 0);
    }
    for(i = 0; i< N ; i++){
        printf("\n%s", parole[i]);
    }



    return 0;
}
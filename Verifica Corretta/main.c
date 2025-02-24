#include <stdio.h>
#include <string.h>

#define N 3


/****  TYPE  *********************************/
/****  VARIABILI GLOBALI  ********************/
/****  PROTOTIPI FUNZIONI ********************/

/****  PROGRAMMA PRINCIPALE  *****************/
int main(){
    char parole[N][200]; //il primo parametro indica la dimensione dell'array, il secondo la dimensione delle singole parole
    //ESEMPIO: "Ciao prova", la dimensione dell'array è 2 quindi per una frase del genere bisogna mettere char parole[2][200]
    
    printf("Inserisci tre parole:\n");
	
	int i;
    for (i = 0; i < N; i++) {
    	do{ //
    		printf("Parola %d: ", i + 1);
	        //scanf("%s", parole[i]); //la scanf non è ottima perché prende in ingresso fino al primo spazio
	        //quindi se inserisco "ciao come stai" verrà salvato solo "ciao" perché non prende in ingresso il carattere spazio
	        //inoltre non gestisce le stringhe vuote, quindi se non inserisco niente e premo invio non è possibile fare un controllo su quello che ho inserito
	        fgets(parole[i], 200, stdin); //la fgets invece non considera il carattere spazio
	        //quindi se inserisco "ciao come stai" verrà salvato "ciao come stai"
	        parole[i][strcspn(parole[i], "\n")] = '\0'; //per rimuovere il carattere terminatore "/n" utilizzo strcspn, sostituisco il carattere terminatore con "\0"
	        //così creo una frase
		}while(strlen(parole[i]) == 0);

    }


    printf("\nLe parole inserite sono:\n");
    for (i = 0; i < N; i++) {
        printf("%s ", parole[i]);
    }
    //prendo la parola maggiore e quella minore
    char min[20], max[20]; //definisco le due stringhe 
    strcpy(min, parole[0]); //in entrambe inserisco la prima stringa dell'array di stringhe
    strcpy(max, parole[0]);
    int posizioneMin = 0;
    int posizioneMax = 0;
    for (i = 0; i < N; i++){
    	if(strlen(parole[i]) > strlen(max)){
    		strcpy(max, parole[i]);
    		posizioneMax = i;
		}
		if(strlen(parole[i]) < strlen(min)){
			strcpy(min, parole[i]);
			posizioneMin = i;
		}
	}
	printf("\nLa parole più grande è: %s", max);
	printf("\nLa parole più piccola è %s", min);
	
	//scambio il max con il min
	char appoggio[20];
	char arrayAppoggio[N][20];
	for(i = 0; i < N; i++){
		strcpy(arrayAppoggio[i], parole[i]);
	}
	strcpy(appoggio, arrayAppoggio[posizioneMax]);
	strcpy(arrayAppoggio[posizioneMax], arrayAppoggio[posizioneMin]);
	strcpy(arrayAppoggio[posizioneMin], appoggio);
	//stampo le parole con i max e min invertiti
	printf("\n\nParole invertite:\n");
	for (i = 0; i < N; i++) {
        printf("%s ", arrayAppoggio[i]);
    }
    
    //stampo le parole
	printf("\n\nStampo le parole con i caratteri invertiti: \n"); 
    for(i = 0; i < N; i++){
    	int j;
		int len = strlen(parole[i]);
    	for(j = len - 1; j >= 0; j--){
    		printf("%c ", parole[i][j]);
		}
		printf(" - ");
	}
	
	//provo stampa singola dei caratteri
	printf("\n\nStampo i singoli caratteri:\n");
	for (i = 0; i < N; i++){
		int j;
		int len = strlen(parole[i]);
		for(j = 0; j<len + 1; j++){
			printf("%c ", parole[i][j]);
		}
		printf("\n");
	}	
    printf("\n\n");

    return 0;
}


/****  IMPLEMENTAZIONE FUNZIONI  *************/
//---------------------------------------------
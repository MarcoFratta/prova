#include<stdio.h>
#define numeroNuoveEstratte fDaTrovare + i
#define MAX_FIGURINE 10000

unsigned long long int disposizione(int n, int d) {
	unsigned long long int disp = 1;
	for (int i = 0; i < d; i++) {
		disp = disp * n;
		n--;
	}
	return disp;
}
unsigned long long int fattoriale(unsigned long long int n){
    	if(n < 2 )
        	return 1;
    	return n * fattoriale(n-1);
}
double su(int n , int d){
    	return ((double) disposizione(n , d) / fattoriale(d));
}
void inserisci(char* stringa , int controllo, int* valore){
	do {
		printf(stringa);
		fflush(stdin);
		scanf("%d", valore);
		fflush(stdin);
	} while (*valore > controllo || *valore < 0);
}

int main() {

	const int N_PANINI = 832;

	int fTotali = 0;
	int fTrovate = 0;
	int fPacchetto = 0;
	int fDaTrovare = 0;
	int fMancanti = 0;
	double prob = 0.0;

	printf(" -- NON INSERIRE ALTRO SE NON NUMERI INTERI -- \n\n");
	
	
    	inserisci("Figurine totali: " , MAX_FIGURINE , &fTotali);
	inserisci("Figurine trovate: ", fTotali, &fTrovate);
	inserisci("Figurine per pacchetto: ", fTotali , &fPacchetto);
	inserisci("Figurine da trovare: ", fPacchetto, &fDaTrovare);
	
	fMancanti = fTotali - fTrovate;
	
	unsigned long long int den = su(fTotali , fPacchetto);
	
	// non mi credevate scettici :(
	for(int i = 0 ; i < fPacchetto - fDaTrovare + 1 ; i++){		
		if(fPacchetto == numeroNuoveEstratte)
			prob +=  (double) su(fMancanti,fPacchetto) / (double) den;
		
		else{
		    unsigned long long int a = su(fMancanti , (numeroNuoveEstratte));
		    unsigned long long int b = su(fTrovate , fPacchetto - (numeroNuoveEstratte));
		    unsigned long long int num =  a * b; 
		    prob += (double) num / (double) den;
       		}     
    }

	printf("Probabilita' di trovare almeno %d %s da trovare: %.2f%%", fDaTrovare,fDaTrovare == 1 ? "carta" : "carte" , (prob * 100));
}

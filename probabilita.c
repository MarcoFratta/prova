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

	int fTotali;
	int fTrovate;
	int fPacchetto;
	int fDaTrovare;
	int fMancanti;
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
			
		if(fPacchetto == numeroNuoveEstratte){
			prob += su(fMancanti,fPacchetto) / den;
		}
		else{
			prob += su(fMancanti , numeroNuoveEstratte) * su(fTrovate , fPacchetto - numeroNuoveEstratte);
			prob /= den;
		}		
	}

	printf("Probabilita' di trovare almeno una carta nuova: %.2f%%", prob);
}

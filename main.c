#include<stdio.h>

unsigned long long int disposizione(int n, int d) {
	unsigned long long int disp = 1;
	for (int i = 0; i < d; i++) {
		disp = disp * n;
		n--;
	}
	return disp;
}

int main() {

	int N_PANINI = 832;

	int fTotali;
	int fTrovate;
	int fPacchetto;

	printf(" -- NON INSERIRE ALTRO SE NON NUMERI INTERI -- \n\n");

	//do {
	//	printf("Figurine totali: ");
	//	scanf("%d", &fTotali);
	//	fflush(stdin);
	//} while (fTotali < 0);
	fTotali = N_PANINI;

	do {
		printf("Figurine trovate: ");
		fflush(stdin);
		scanf("%d", &fTrovate);
		fflush(stdin);
	} while (fTrovate > fTotali || fTrovate < 0);

	do {
		printf("Figurine per pacchetto: ");
		scanf("%d", &fPacchetto);
		fflush(stdin);
	} while (fPacchetto > fTotali || fPacchetto < 0);

	unsigned long long int numeratore = disposizione(fTrovate, fPacchetto);
	unsigned long long int denominatore = disposizione(fTotali, fPacchetto);

	double compl = ((double)(numeratore)/(double)(denominatore));
	double prob = (1 - compl) * 100;

	printf("Probabilita' di trovare almeno una carta nuova: %.2f%%", prob);

}
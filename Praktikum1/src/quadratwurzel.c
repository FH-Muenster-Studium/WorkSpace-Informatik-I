#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Diese Funktion berechnet die Quadratwurzel der Zahl, die der
 * Aufrufer übergibt und gibt das Ergebnis an den Aufrufer zurück.
 */
double wurzel(int zahl) {
	return sqrt(zahl);
}

/* Diese Funktion berechnet das Quadrat der Zahl, die der
 * Aufrufer übergibt und gibt das Ergebnis an den Aufrufer zurück.
 */
double quadrat(int zahl) {
	return pow(zahl, 2);
}

/*
 * Diese funktion berechnet die Fläche eines Kreises anhand des Radius (A=πr2)
 */
double kreis_flaeche(int zahl) {
	return M_PI * quadrat(zahl);
}

int main(int argc, char* argv[]) {
	char puffer[32];
	int eingabe;
	double ergebnis;

	/* Hier muss der Benutzer etwas eingeben. */
	puts("Bitte geben Sie eine Zahl ein: ");
	fflush(stdout);
	fgets(puffer, 32, stdin);
	eingabe = atoi(puffer);

	/* Ruf die Funktion 'wurzel' auf und speichere das Ergebnis */
	ergebnis = wurzel(eingabe);
	printf("Die Quadratwurzel der Zahl %d ist %f\n", eingabe, ergebnis);


	/* Ruf die Funktion 'quadrat' auf und speichere das Ergebnis */
	ergebnis = quadrat(eingabe);
	printf("Das Quadrat der Zahl %d ist %f\n", eingabe, ergebnis);

	/* Ausgabe der Tabellenspalten Definitionen  */
	puts("| Radius | Kreisfläche");
	/* Iterieren der einzelnen Rechnungen mit den Wert x > 1 && x < 21*/
	for(int i = 1; i < 21; i++) {
		/* Die Kreisfläche wird anhand des Radius berechnet */
		double f = kreis_flaeche(i);
		/* Ausgabe der ausgerechneten Kreisfläche und des genutzten Radiuses */
		printf("| %d \t | %f \n", i , f);
	}

	return 0;
}

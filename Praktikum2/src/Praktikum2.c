/*
 ============================================================================
 Name        : Praktikum2.c
 Author      : Fabian Terhorst
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define COUNT_1 20
#define COUNT_2 20

void caesar(char *zeichen, int offset);

int main(void) {
	for (int i = 0; i < COUNT_1; i++) {
		/* Es wird überprüft ob der Rest aus der division mit zwei null ergibt,
		 * denn dann handelt es sich um eine Gerade Zahl*/
		/*int div = i/2;
		float div2 = i/2;
		if (div == div2) {
			printf("%d \n", i);
		}*/
		int a = i;
		int b = 2;
		int erg = a / b;
		int erg2 = erg * b;
		int erg3 = a - erg2;
		if (erg3 == 0) {
			printf("%d \n", i);
		}
		/*if (i % 2 == 0) {
			printf("%d \n", i);
		}*/
	}
	
	for (int i = 2; i < COUNT_2; i++) {
		int primzahl = 1;
		for (int j = 2; primzahl == 1 && j < i; j++) {
			if (i != j) {
				primzahl = !!(i % j);
			}
		}
		if (primzahl) {
			printf("%d \n", i);
		}
	}


	char string[100];// = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

	printf("Geben Sie ein paar Wörter ein : ");
	fgets(string, 100, stdin);
	printf("Ihre Eingabe: %s\n",string);

	for (int i=0; i<(sizeof(string)/sizeof(char)); i++)
	{
		caesar(&string[i], 2);
	}

	printf("%s\n\n", string);

	char string2[1000];// = "Ebowifzebk Dirbzhtrkpze! Pfb exybk afb Sbopzeirbppbirkd dbhkxzhq rka ybhljjbk yxia bfk Gly-Xkdbylq slj xjbofhxkfpzebkDbebfjafbkpq.";

	printf("Geben Sie ein paar Wörter ein : ");
	fgets(string2, 1000, stdin);
	printf("Ihre Eingabe: %s\n",string2);


	for (int i=0; i<(sizeof(string2)/sizeof(char)); i++)
	{
		caesar(&string2[i], 3);
	}

	printf("%s\n\n", string2);
	return EXIT_SUCCESS;
}

void caesar(char *zeichen, int offset) {
	if(*zeichen >= 'A' && *zeichen <='Z') {
		if(*zeichen + offset > 'Z') {
			*zeichen= 'A' + offset - ('Z' - *zeichen +1);
		} else {
			*zeichen +=offset;
		}
	} else if(*zeichen>='a' && *zeichen <='z') {
		if(*zeichen + offset >'z') {
			*zeichen= 'a' + offset - ('z' - *zeichen + 1);
		} else {
			*zeichen += offset;
		}
	}
}

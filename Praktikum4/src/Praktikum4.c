/*
 ============================================================================
 Name        : Praktikum4.c
 Author      : Fabian Terhorst
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Praktikum4.h"

void randomize(long size, long values[][KEY_VALUE]) {
	srandom((unsigned) time(NULL));
	for (int i = 0 ; i < size ;i++ ) {
		values[i][0] = i + 1;
		values[i][1] = random() % 1000;
	}
}

void qs(long daten[][KEY_VALUE], long links, long rechts) {
	long i,j;
	long x,y,z;

	i=links; j=rechts;
	x = daten[(links+rechts)/2][1]; // mittleres Element

	do {
		while (daten[i][1]<x && i<rechts) i++; // such Element für "große Klasse"
		while (x<daten[j][1] && j>links) j--;     // such Element für "kleine Klasse"

		if (i<=j) {                                     // vertausche Elemente
			y = daten[i][1];
			z = daten[i][0];
			daten[i][1] = daten[j][1];
			daten[i][0] = daten[j][0];
			daten[j][1] = y;
			daten[j][0] = z;
			i++; j--;
		}
	} while (i<=j);

	if (links<j) qs(daten, links,j);                   // Aufruf für "kleine Klasse"
	if (i<rechts) qs(daten, i, rechts);		  // Aufruf für "große Klasse"
}

void quick_sort(long size, long daten[][KEY_VALUE]) { // Quicksort vorbereiten
	qs(daten, 0, size-1);
}

/*
 * main.c
 *
 *  Created on: 03.01.2017
 *      Author: fabianterhorst
 */

#include "Praktikum5.h"

int main(void) {
	VOCABLE voc;
	initVocable(&voc);
	voc.wordEnglish = "Hello World";
	voc.wordGerman = "Hallo Welt";
	addVocable(&voc);
	VOCABLE voc2;
	initVocable(&voc2);
	voc2.wordEnglish = "Test";
	voc2.wordGerman = "Test";
	addVocable(&voc2);
	VOCABLE voc3;
	initVocable(&voc3);
	voc3.wordEnglish = "Bla";
	voc3.wordGerman = "Bla3";
	addVocable(&voc3);

	printf("%s \n",getFirst()->wordEnglish);
	fflush(stdout);
	printf("%s \n",getFirst()->next->wordEnglish);
	fflush(stdout);
	printf("%s \n",getFirst()->next->next->wordEnglish);
	fflush(stdout);

	removeVocable("Test");

	printf("%s \n",getFirst()->wordEnglish);
	fflush(stdout);
	printf("%s \n",getFirst()->next->wordEnglish);
	fflush(stdout);

	removeVocable("Hello World");

	printf("%s \n",getFirst()->wordEnglish);
	fflush(stdout);

	VOCABLE vocable;
	vocableFromString("to study;studieren", &vocable);

	addVocable(&vocable);

	printf("%s \n",getFirst()->next->wordEnglish);
	fflush(stdout);

	vocablesFromString(vocablesToString());

	return EXIT_SUCCESS;
}

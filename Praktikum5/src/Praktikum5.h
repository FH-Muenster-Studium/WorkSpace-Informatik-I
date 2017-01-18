/*
 * Praktikum5.h
 *
 *  Created on: 03.01.2017
 *      Author: fabianterhorst
 */

#ifndef PRAKTIKUM5_H_
#define PRAKTIKUM5_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Todo: create a Vocable and VocableItem struct
//Todo: the item contains the prev, next ptr and the struct the german and english translation

typedef struct Vocable {
	char *wordEnglish;
	char *wordGerman;
	struct Vocable *prev;
	struct Vocable *next;
} VOCABLE;

VOCABLE* initVocable();

void addVocable(VOCABLE *vocable);

VOCABLE* getFirst();

void vocableFromString(char *string, VOCABLE *vocable, size_t size);

char* vocableToString(VOCABLE *vocable);

char* vocablesToString();

char* vocablesToStringWithNewLines();

/*void vocablesFromString(char *string);*/

void saveVocables(char *filePath);

void loadVocables(char *filePath);

int vocableCount();

VOCABLE* vocableForIndex(int index);

void removeNewLine(char *string);

void removeVocable(char* lang, char *name);

#endif /* PRAKTIKUM5_H_ */

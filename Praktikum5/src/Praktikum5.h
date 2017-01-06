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

typedef struct Vocable {
	char *wordEnglish;
	char *wordGerman;
	struct Vocable *prev;
	struct Vocable *next;
} VOCABLE;

void initVocable(VOCABLE *vocable);

void addVocable(VOCABLE *vocable);

void removeVocable(char *name);

VOCABLE* getFirst();

void vocableFromString(char *string, VOCABLE *vocable);

int split (char *str, char c, char ***arr);

char* vocableToString(VOCABLE *vocable);

char* vocablesToString();

void vocablesFromString(char* string);

void saveVocables(char *filePath);

#endif /* PRAKTIKUM5_H_ */

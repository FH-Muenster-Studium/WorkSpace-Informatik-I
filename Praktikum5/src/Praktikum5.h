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

#define COMMAND_LENGTH 100

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

int vocableCount();

#endif /* PRAKTIKUM5_H_ */

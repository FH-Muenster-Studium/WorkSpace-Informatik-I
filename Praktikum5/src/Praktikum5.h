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
#include <stdbool.h>

//Todo: create a Vocable and VocableItem struct
//Todo: the item contains the prev, next ptr and the struct the german and english translation

typedef struct Vocable {
	char *wordEnglish;
	char *wordGerman;
} VOCABLE;

typedef struct Item {
	void *data;
	struct Item *prev;
	struct Item *next;
} ITEM;

/**
 * allocate vocable
 */
VOCABLE* initVocable();

ITEM *initItem();

/**
 * add vocable
 * @param vocable vocable
 */
void addItem(ITEM *item);

ITEM *getFirst();

/**
 * fill vocable struct with given string
 * @param string string
 * @param vocable vocable struct to fill
 * @param size string size
 */
void vocableFromString(char *string, VOCABLE *vocable, size_t size);

/**
 * create string for vocable
 * @param vocable vocable
 * @return string string english;german
 */
char* vocableToString(VOCABLE *vocable);

/**
 * create an string to write into an file
 */
char* vocablesToStringWithNewLines();

/**
 * save vocables to file path
 * @param filePath filePath
 */
void saveVocables(char *filePath);

/**
 * load vocables from file path
 * @param filePath filePath
 */
void loadVocables(char *filePath);

/**
 * current vocable count
 * @return current vocable count
 *
 */
int vocableCount();

/**
 * get vocable from index
 * @param index index of the vocable
 *
 */
ITEM* itemForIndex(int index);

/*
 * Remove \n from string
 * @param string to remove \n from
 *
 */
void removeNewLine(char *string);

/*
 * Remove vocable from name and lang
 * @param lang en or de
 * @param name name for language
 * @return 1 successfully, 0 not found
 *
 */
int removeVocable(char* lang, char *name);

VOCABLE *vocableForIndex(int index);

VOCABLE *vocableFromItem(ITEM *item);

#endif /* PRAKTIKUM5_H_ */

/*
 ============================================================================
 Name        : Praktikum5.c
 Author      : Fabian Terhorst
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Praktikum5.h"

VOCABLE *start = NULL;

void initVocable(VOCABLE *vocable) {
	vocable->next = NULL;
	vocable->prev = NULL;
}

void addVocable(VOCABLE *vocable) {
	if (start == NULL) {
		start = vocable;
	} else {
		VOCABLE *curr = start;
		do {
			if (curr->next == NULL) {
				curr->next = vocable;
				vocable->prev = curr;
				break;
			} else {
				curr = curr->next;
			}
		} while(1);
	}
}

void removeVocable(char *name) {
	VOCABLE *curr = start;
	while(curr != NULL) {
		if(!strcmp(name, curr->wordEnglish)) {
			//Wenn die erste gelöscht wird wird die 2. zur ersten
			if (curr->prev == NULL) {
				start = curr->next;
			} else {
				VOCABLE *next = curr->next;
				VOCABLE *prev = curr->prev;
				curr->prev->next = next;
				curr->next->prev = prev;
				curr->next = NULL;
				curr->prev = NULL;
				curr = NULL;
				break;
			}
		}
		curr = curr->next;
	}
}

void saveVocables(char *filePath) {

}

char* vocablesToString() {
	VOCABLE *curr = start;
	char* string = "";
	char* oldString= "";
	char* seperator = ",";
	while(curr != NULL) {
		char* vocableString = vocableToString(curr);
		string = malloc(strlen(string) + strlen(seperator) + strlen(vocableString));
		strcat(string, oldString);
		strcat(string, vocableString);
		strcat(string, seperator);
		oldString = string;
		curr = curr->next;
	}
	return string;
}

void vocablesFromString(char* string) {
	char **arr;
	split(string, ',', &arr);
	int count = 0;
	char *curr;
	while((curr = arr[count++]) != NULL && strlen(curr) > 0) {
		VOCABLE voc;
		initVocable(&voc);
		vocableFromString(curr, &voc);
		addVocable(&voc);
	}
}

char* vocableToString(VOCABLE *vocable) {
	char* english = vocable->wordEnglish;
	char* seperator = ";";
	char* german = vocable->wordGerman;
	char* string = malloc(strlen(english) + strlen(seperator) + strlen(german));
	strcpy(string, english);
	strcat(string, seperator);
	strcat(string, german);
	return string;
}

VOCABLE* getFirst() {
	return start;
}

void vocableFromString(char *string, VOCABLE *vocable) {
	char** arr;
	split(string, ';', &arr);
	initVocable(vocable);
	vocable->wordEnglish = arr[0];
	vocable->wordGerman = arr[1];
}

int split (char *str, char c, char ***arr) {
	int count = 1;
	int token_len = 1;
	int i = 0;
	char *p;
	char *t;

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
			count++;
		p++;
	}

	*arr = (char**) malloc(sizeof(char*) * count);
	if (*arr == NULL)
		exit(1);

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
		{
			(*arr)[i] = (char*) malloc( sizeof(char) * token_len );
			if ((*arr)[i] == NULL)
				exit(1);

			token_len = 0;
			i++;
		}
		p++;
		token_len++;
	}
	(*arr)[i] = (char*) malloc( sizeof(char) * token_len );
	if ((*arr)[i] == NULL)
		exit(1);

	i = 0;
	p = str;
	t = ((*arr)[i]);
	while (*p != '\0')
	{
		if (*p != c && *p != '\0')
		{
			*t = *p;
			t++;
		}
		else
		{
			*t = '\0';
			i++;
			t = ((*arr)[i]);
		}
		p++;
	}

	return count;
}

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

VOCABLE* initVocable() {
	VOCABLE* vocable = malloc(sizeof(VOCABLE));
	vocable->next = NULL;
	vocable->prev = NULL;
	return vocable;
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

void removeVocable(char* lang, char *name) {
	VOCABLE *curr = start;
	while(curr != NULL) {
		char* compareName;
		if (!strcmp(lang, "de")) {
			compareName = curr->wordGerman;
		} else if (!strcmp(lang, "en")) {
			compareName = curr->wordEnglish;
		}
		if(!strcmp(name, compareName)) {
			//Wenn die erste gelöscht wird wird die 2. zur ersten
			if (curr->prev == NULL) {
				start = curr->next;
				free(curr);
			} else {
				/*VOCABLE *next = curr->next;
				VOCABLE *prev = curr->prev;
				curr->prev->next = next;
				curr->next->prev = prev;
				curr->next = NULL;
				curr->prev = NULL;*/
				if (curr->next != NULL) {
					curr->next->prev = curr->prev;
				}
				curr->prev->next = curr->next;
				free(curr);
				//curr = NULL;
				break;
			}
		}
		curr = curr->next;
	}
}

void saveVocables(char *filePath) {
	FILE *f;
	if ((f = fopen(filePath, "w+")) != NULL) {
		char* str = vocablesToStringWithNewLines();
		fwrite(str , sizeof(char) , strlen(str) , f);
		fclose(f);
	}
}

void loadVocables(char *filePath) {
	FILE *f;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	if ((f = fopen(filePath, "r")) != NULL) {
		while ((read = getline(&line, &len, f)) != -1) {
			VOCABLE *vocable = initVocable();
			removeNewLine(line);
			vocableFromString(line, vocable, sizeof(line));
			addVocable(vocable);
			printf("Vokabel de: %s en: %s geladen\n", vocable->wordEnglish, vocable->wordGerman);
		}
		fclose(f);
	}
}

char* vocablesToString() {
	VOCABLE *curr = start;
	char *currString = calloc(0, 0);
	char *seperator = ",";
	char *vocableString;
	while(curr != NULL) {
		vocableString = vocableToString(curr);
		currString = realloc(currString, sizeof(currString) + sizeof(vocableString) + sizeof(seperator));
		if (currString == NULL) {
			//return null if length does not fit into heap
			return currString;
		}
		strcat(currString, vocableString);
		curr = curr->next;
		if (curr != NULL) {
			strcat(currString, seperator);
		}
	}
	return currString;
}

char* vocablesToStringWithNewLines() {
	VOCABLE *curr = start;
	char *currString = calloc(0, 0);
	char *seperator = "\n";
	char *vocableString;
	while(curr != NULL) {
		vocableString = vocableToString(curr);
		currString = realloc(currString, sizeof(currString) + sizeof(vocableString) + sizeof(seperator));
		if (currString == NULL) {
			//return null if length does not fit into heap
			return currString;
		}
		strcat(currString, vocableString);
		curr = curr->next;
		if (curr != NULL) {
			strcat(currString, seperator);
		}
	}
	return currString;
}

/*void vocablesFromString(char* string) {
	char **arr;
	split(string, ',', &arr);
	int count = 0;
	char *curr;
	while((curr = arr[count++]) != NULL && strlen(curr) > 0) {
		VOCABLE *voc = initVocable();
		vocableFromString(curr, voc, strlen(curr));
		addVocable(voc);
	}
}*/

char* vocableToString(VOCABLE *vocable) {
	char *english = vocable->wordEnglish;
	char *seperator = ";";
	char *german = vocable->wordGerman;
	char *string = malloc(strlen(english) + strlen(seperator) + strlen(german));
	strcat(string, english);
	strcat(string, seperator);
	strcat(string, german);
	return string;
}

VOCABLE* getFirst() {
	return start;
}

void vocableFromString(char *string, VOCABLE *vocable, size_t size) {
	/*char **arr;
	split(string, ';', &arr);
	char *english = malloc(size);
	char *german = malloc(size);
	memcpy(english, arr[0], size);
	memcpy(german, arr[1], size);
	free(arr);
	vocable->wordEnglish = english;
	vocable->wordGerman = german;*/
	char *english = malloc(size);
	char *german = malloc(size);
	memcpy(english, strtok(string, ";"), size);
	memcpy(german, strtok(NULL, ";"), size);
	vocable->wordEnglish = english;
	vocable->wordGerman = german;
}

int vocableCount() {
	VOCABLE *curr = start;
	int count = 0;
	while(curr != NULL) {
		count++;
		curr = curr->next;
		if (curr == NULL) {
			break;
		}
	}
	return count;
}

VOCABLE* vocableForIndex(int index) {
	VOCABLE *curr = start;
	int count = 0;
	while(curr != NULL) {
		count++;
		if (count == index) {
			return curr;
		}
		curr = curr->next;
		if (curr == NULL) {
			break;
		}
	}
	return NULL;
}

void removeNewLine(char *string) {
	char *pos;
	if ((pos=strchr(string, '\n')) != NULL)
		*pos = '\0';
}

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

ITEM *start = NULL;

ITEM* initItem() {
	ITEM* item = calloc(1, sizeof(ITEM));
	return item;
}

VOCABLE* initVocable() {
	VOCABLE* vocable = calloc(1, sizeof(VOCABLE));
	return vocable;
}

void addItem(ITEM *item) {
	if (start == NULL) {
		start = item;
	} else {
		ITEM *curr = start;
		do {
			if (curr->next == NULL) {
				curr->next = item;
				item->prev = curr;
				break;
			} else {
				curr = curr->next;
			}
		} while(1);
	}
}

int removeVocable(char* lang, char *name) {
	ITEM *curr = start;
	while(curr != NULL) {
		char* compareName;
		VOCABLE *voc = vocableFromItem(curr);
		if (!strcmp(lang, "de")) {
			compareName = voc->wordGerman;
		} else if (!strcmp(lang, "en")) {
			compareName = voc->wordEnglish;
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

				//break;
			}
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void saveVocables(char *filePath) {
	FILE *f;
	if ((f = fopen(filePath, "w+")) != NULL) {
		char* str = vocablesToStringWithNewLines();
		fwrite(str , sizeof(char) , strlen(str) , f);
		free(str);
		fclose(f);
	}
}

void loadVocables(char *filePath) {
	FILE *f = fopen(filePath, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	if(!f) {
		f = fopen(filePath, "wb");
	}
	while ((read = getline(&line, &len, f)) != -1) {
		ITEM *item = initItem();
		VOCABLE *vocable = initVocable();
		item->data = vocable;
		removeNewLine(line);
		vocableFromString(line, vocable, sizeof(line));
		addItem(item);
		printf("Vokabel de: %s en: %s geladen\n", vocable->wordEnglish, vocable->wordGerman);
	}
	free(line);
	fclose(f);
}

char* vocablesToStringWithNewLines() {
	ITEM *curr = start;
	char *currString = calloc(0, 0);
	char *seperator = "\n";
	char *vocableString;
	VOCABLE *voc;
	while(curr != NULL) {
		voc = vocableFromItem(curr);
		vocableString = vocableToString(voc);
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

ITEM* getFirst() {
	return start;
}

void vocableFromString(char *string, VOCABLE *vocable, size_t size) {
	char *english = malloc(size);
	char *german = malloc(size);
	memcpy(english, strtok(string, ";"), size);
	memcpy(german, strtok(NULL, ";"), size);
	vocable->wordEnglish = english;
	vocable->wordGerman = german;
}

int vocableCount() {
	ITEM *curr = start;
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

ITEM* itemForIndex(int index) {
	ITEM *curr = start;
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

VOCABLE *vocableFromItem(ITEM *item) {
	return (VOCABLE*)item->data;
}

VOCABLE *vocableForIndex(int index) {
	return vocableFromItem(itemForIndex(index));
}

void removeNewLine(char *string) {
	char *pos;
	if ((pos=strchr(string, '\n')) != NULL)
		*pos = '\0';
}

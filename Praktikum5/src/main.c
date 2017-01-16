/*
 * main.c
 *
 *  Created on: 03.01.2017
 *      Author: fabianterhorst
 */

#include "Praktikum5.h"

#define COMMAND_LENGTH 100

typedef enum {ADD, REMOVE, SAVE, EXIT, SHOW, UNSET} Command;

#define COMMAND_ADD "add"
#define COMMAND_REMOVE "remove"
#define COMMAND_SAVE "save"
#define COMMAND_EXIT "exit"
#define COMMAND_SHOW "show"

void initRandomize() {
	srandom((unsigned) time(NULL));
}

int randomVocableIndex() {
	int randomInt = random() % vocableCount();
	return ++randomInt;
}

void executeCommand(Command *lastCommand, Command currCommand, char command[COMMAND_LENGTH]) {
	switch(currCommand) {
	case ADD:
		printf("Bitte geben Sie die hinzuzufügende Vocabel in folgender Schreibweise an: \n");
		printf("Englisch;Deutsch\n");
		*lastCommand = currCommand;
		return;
		break;
	case REMOVE:
		printf("Bitte geben Sie die Löschabfrage in folgender Schreibweise an: \n");
		printf("[en(Englisch)/de(Deutsch)];[VokabelName]\n");
		*lastCommand = currCommand;
		return;
		break;
	case SAVE:
		printf("%s\n", vocablesToStringWithNewLines());
		saveVocables("/Users/fabianterhorst/bla.txt");
		break;
	case EXIT:
		exit(1);
		break;
	case SHOW:
		printf("%s\n", vocableForIndex(randomVocableIndex())->wordEnglish);
		break;
	case UNSET:
		switch(*lastCommand) {
		case ADD: {
			VOCABLE *voc = initVocable();
			vocableFromString(command, voc, COMMAND_LENGTH);
			addVocable(voc);
			printf("Vokabel: %s;%s erfolgreich hinzugefügt\n", voc->wordEnglish,  voc->wordGerman);
			break;
		}
		case REMOVE: {
			char **arr;
			split(command, ';', &arr);
			removeVocable(arr[0], arr[1]);
			printf("Vokabel erfolgreich gelöscht\n");
			break;
		}
		case SAVE:
			break;
		case EXIT:
			break;
		case SHOW:
			break;
		case UNSET:
			break;
		}
		break;
	}
	*lastCommand = UNSET;
}

int isCommand(char* command, char string[COMMAND_LENGTH]) {
	return !strcmp(string, command);
}

Command commandFromString(char string[COMMAND_LENGTH]) {
	if (isCommand(string, COMMAND_ADD)) {
		return ADD;
	} else if(isCommand(string, COMMAND_REMOVE)) {
		return REMOVE;
	} else if(isCommand(string, COMMAND_SAVE)) {
		return SAVE;
	} else if(isCommand(string, COMMAND_EXIT)) {
		return EXIT;
	} else if(isCommand(string, COMMAND_SHOW)) {
		return SHOW;
	}
	printf("Ungültiges Command '%s'\n", string);
	return UNSET;
}

void normalizeInput(char* pos, char string[COMMAND_LENGTH]) {
	if ((pos=strchr(string, '\n')) != NULL)
		*pos = '\0';
}

int main(void) {
	initRandomize();
	loadVocables("/Users/fabianterhorst/bla.txt");
	printf("'add' Fügt eine Vokabel hinzu.\n");
	printf("'remove' Löscht eine Vokabel.\n");
	printf("'save' Speichert die Änderungen.\n");
	printf("'exit' Ohne Speichern abbrechen.\n");
	printf("'show' Eine zufällige Vokabel anzeigen.\n");
	char command[COMMAND_LENGTH];
	Command currCommand = UNSET;
	Command lastCommand = UNSET;
	char pos;
	while(1) {
		fgets (command, COMMAND_LENGTH, stdin);
		fflush(stdin);
		normalizeInput(&pos, command);
		if (lastCommand == UNSET) {
			currCommand = commandFromString(command);
		} else {
			currCommand = UNSET;
		}
		executeCommand(&lastCommand, currCommand, command);
		fflush(stdin);
	}
	return EXIT_SUCCESS;
}

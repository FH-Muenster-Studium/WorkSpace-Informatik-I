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
		saveVocables("/Users/fabianterhorst/vocable.txt");
		break;
	case EXIT:
		exit(1);
		break;
	case SHOW: {
		VOCABLE *voc = vocableForIndex(randomVocableIndex());
		if (voc == NULL) {
			printf("Keine Vokabeln vorhanden\n");
			break;
		}
		printf("Übersetzen Sie %s nach Englisch\n", voc->wordGerman);
		fgets (command, COMMAND_LENGTH, stdin);
		removeNewLine(command);
		if (!strcmp(command, voc->wordEnglish)) {
			printf("richtig\n");
		} else {
			printf("falsch, das richtige Wort heißt %s\n", voc->wordEnglish);
		}
		break;
	}
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
			printf("Sind Sie sicher das Sie folgende Vokabel wirklich löschen möchten? %s\n", command);
			char question[COMMAND_LENGTH];
			fgets (question, COMMAND_LENGTH, stdin);
			removeNewLine(question);
			if(strcmp(question, "ja")) {
				printf("Löschen wurde abgebrochen\n");
				break;
			}
			char *lang = malloc(COMMAND_LENGTH);
			char *name = malloc(COMMAND_LENGTH);
			memcpy(lang, strtok(command, ";"), COMMAND_LENGTH);
			memcpy(name, strtok(NULL, ";"), COMMAND_LENGTH);
			if (removeVocable(lang, name)) {
				printf("Vokabel erfolgreich gelöscht %s %s\n", lang, name);
			} else {
				printf("Vokabel konnte nicht gelöscht werden %s %s\n", lang, name);
			}
			free(lang);
			free(name);
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

int main(void) {
	initRandomize();
	loadVocables("/Users/fabianterhorst/vocable.txt");
	printf("'add' Fügt eine Vokabel hinzu.\n");
	printf("'remove' Löscht eine Vokabel.\n");
	printf("'save' Speichert die Änderungen.\n");
	printf("'exit' Ohne Speichern abbrechen.\n");
	printf("'show' Eine zufällige Vokabel anzeigen.\n");
	char command[COMMAND_LENGTH];
	Command currCommand = UNSET;
	Command lastCommand = UNSET;
	while(1) {
		fgets (command, COMMAND_LENGTH, stdin);
		fflush(stdin);
		removeNewLine(command);
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

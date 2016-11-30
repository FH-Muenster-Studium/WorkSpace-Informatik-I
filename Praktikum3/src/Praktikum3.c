/*
 ============================================================================
 Name        : Praktikum3.c
 Author      : Fabian Terhorst
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Praktikum3.h"

int main(void) {
	puts("Aufgabe 1)");
	char string[PUFFER_SIZE];
	int length = sizeof(string) / sizeof(char);
	fillArray(&length, string);
	printf("Geben Sie ein paar Wörter ein : ");
	fflush(stdout);
	fgets(string, PUFFER_SIZE, stdin);
	printf("Ihre Eingabe: %s\n",string);
	int count = 0;
	char string2[PUFFER_SIZE];
	reverseInput(&length, &count, string, string2);
	printf("%s", string2);
	puts("\n\nAufgabe 2)");

	printf("%d", primzahlenBis(10000));

	puts("\n\nAufgabe 3)");

	printf("Geben Sie ein paar Wörter ein : ");
	fflush(stdout);
	fgets(string, PUFFER_SIZE, stdin);
	printf("Ihre Eingabe: %s\n",string);
	length =  sizeof(string) / sizeof(char);
	lowerCharArray(&length, string);
	printf("Ihre Eingabe in klein: %s\n",string);

	char key[KEY_SIZE] = {
			'b', 'j', ',', 'o', 't', 'd','g',//0 - 6
			'l', 'h', 'r', 'k', 'i', 'c', 'x',//7 - 13
			'a', 'm', '.', 'p', 'z', 'y', 'e',//14 - 20
			'v','_', 'q', 'n', 's', '0', '0',//21 - 27
			'0','0', '0', '0', '0', '0', '0',//28 - 34
			'0', '0','0', '0', '0', '0', '0',//35 - 41
			'0', '0', 'w', '0', 'u', '0', '0',//42 - 48
			'0', '0', '0', '0', '0', '0', '0',//49 - 55
			'0', '0', '0', '0', '0', '0', '0',//56 - 62
			'0', '0', '0', '0', '0', '0', '0',//63 - 69
			'0', '0', '0', '0', '0', '0', '0',//70 - 76
			'0', '0', '0', '0', '0', '0', '0',//77 - 83
			'0', '0', '0', '0', '0', '0', '0',//84 - 90
			'0', '0', '0', '0', 'f', '0', '0'//91 - 97
	};

	encryptInput(key, &length, string);

	printf("Ihre Eingabe verschlüsselt: %s\n",string);

	decryptInput(key, &length, string);

	printf("Ihre Eingabe unverschlüsselt: %s\n",string);

	char lights = 0;

	/*
	 * 0 0 0 0 0 0 0 0
	 * Lampe 4 auf 1  ( 2^4 )  + char/string = lights
	 * 0 0 0 0 1 0 0 0
	 * Lampe 7 auf 1 2 ( 2^7 )
	 * 0 1 0 0 1 0 0 0
	 *
	 */

	char eingabe[4] = {0,0,0,0};
	int index = 0;
	int command = 0;
	do {
		printf("Lampe(index)-Command(X/-)");
		fflush(stdout);
		fgets(eingabe, 4, stdin);
		index = (int) eingabe[0] - 48;
		printf("index: %d \n", index);
		command = eingabe[1] == 'x' ? 1 : 0;
		printf("command %d", command);
		lampeSchalten(&lights, &index, &command);
	} while(index >= 0);

	return EXIT_SUCCESS;
}

void lowerCharArray(int *length, char array[]) {
	for (int i = 0; i < *length; i++)
		array[i] = tolower(array[i]);
}

void fillArray(int *length, char array[]) {
	for (int i = 0; i < *length; i++)
		array[i] = 0;
}

void reverseInput(int *length, int *count, char string[], char string2[]) {
	for (int i = *length - 1; i >= 0; i--) {
		char current = string[i];
		if (current == 0) {
			continue;
		}
		string2[*count] = current;
		*count += 1;
	}
}

void encryptInput(char key[], int *length, char input[]) {
	int offset = 'a' - '0';
	for (int i = 0;i < *length; i++) {
		char current = input[i];
		if (current == 0) {
			continue;
		}
		if (current >= 'a' && current <= 'z') {
			int index = current - '0' - offset;
			input[i] = key[index];
		} else if (current == '.' || current == ',' || current == '_') {
			char encrypted = key[(int)current];
			if (encrypted != '0') {
				input[i] = encrypted;
			}
		}
	}
}

void decryptInput(char key[], int *length, char input[]) {
	for (int i = 0;i < *length; i++) {
			char current = input[i];
			if (current == 0) {
				continue;
			}
			for(int j = 0 ;j < KEY_SIZE; j++) {
				char currentKey = key[j];
				if (currentKey == current) {
					if (j > 25) {
						input[i] = j;
					} else {
						input[i] = j + 'a' + '\0';
					}
				}
			}
		}
}

void inBits(char lights) {
	puts("\n");
	for (int i = 7; i >= 0; --i)
	{
		printf("%c", (lights & (1 << i)) ? '1' : '0' );
	}
	puts("\n");
}

int istPrim(int zahl) {
	int primzahl = 1;
	for (int i = 2; primzahl == 1 && i < zahl; i++) {
		if (zahl != i) {
			primzahl = !!(zahl % i);
		}
	}
	return primzahl;
}

int primzahlenBis(int zahl) {
	int count = 0;
	for (int i = 2;i < zahl;i++) {
		if (istPrim(i)) {
			count++;
		}
	}
	return count;
}

void lampeSchalten(char *lights, int *index, int *command) {
	int div = round(pow(2, *index - 1));
	if (*command == 0) {
		div = -div;
	}
	*lights += div;

	inBits(*lights);
}

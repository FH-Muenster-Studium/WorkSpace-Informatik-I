/*
 ============================================================================
 Name        : Praktikum3.c
 Author      : Fabian Terhorst
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


#define PUFFER_SIZE 100

int istPrim(int zahl);

int primzahlenBis(int zahl);

//void encrypt(char old*, char key[]);

int main(void) {
	puts("Aufgabe 1)");
	char string[PUFFER_SIZE];
	int length = sizeof(string) / sizeof(char);
	for (int i = 0; i < length; i++)
		string[i] = 0;
	printf("Geben Sie ein paar Wörter ein : ");
	fflush(stdout);
	fgets(string, 100, stdin);
	printf("Ihre Eingabe: %s\n",string);
	int count = 0;
	char string2[100];
	for (int i = length - 1; i >= 0; i--) {
		char current = string[i];
		/*if (current == '\0') {
			break;
		}*/
		if (current == 0) {
			continue;
		}
		string2[count] = current;
		count++;
		/*if (i - 1 < 0) {
			string2[count] = '0';
		}*/
	}
	for (int i = 0; i < count; i++) {
		char current = string2[i];
		printf("%c", current);
	}
	puts("\n\nAufgabe 2)");

	printf("%d", primzahlenBis(8));

	puts("\n\nAufgabe 3)");

	printf("Geben Sie ein paar Wörter ein : ");
	fflush(stdout);
	fgets(string, 100, stdin);
	printf("Ihre Eingabe: %s\n",string);
	for (int i = 0; i <  sizeof(string) / sizeof(char); i++) {
		string[i] = tolower(string[i]);
	}
	printf("Ihre Eingabe in klein: %s\n",string);

	char key[99] = {
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

	int offset = 'a' - '0';
	for (int i = 0;i < sizeof(string) / sizeof(char); i++) {
		char current = string[i];
		if (current == 0) {
			continue;
		}
		if (current >= 'a' && current <= 'z') {
			int index = current - '0' - offset;
			string[i] = key[index];
		} else if (current == '.' || current == ',' || current == '_') {
			int index = atoi(&current);
			char encrypted = key[index];
			if (encrypted != '0') {
				string[i] = encrypted;
			}
		}
	}

	printf("Ihre Eingabe verschlüsselt: %s\n",string);

	for (int i = 0;i < sizeof(string) / sizeof(char); i++) {
			char current = string[i];
			if (current == 0) {
				continue;
			}
			for(int j = 0 ;j < sizeof(key) / sizeof(char); j++) {
				char currentKey = key[j];
				if (currentKey == current) {
					string[i] = j + 'a' + '\0';
				}
			}
		}

	printf("Ihre Eingabe unverschlüsselt: %s\n",string);

	return EXIT_SUCCESS;
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

/*void encrypt(char old*, char key[]) {
	//*old = 'c';
}*/

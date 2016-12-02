/*
 * main.c
 *
 *  Created on: 02.12.2016
 *      Author: fabianterhorst
 */

#include "Praktikum4.h"

int main(void) {
	//char string[100];
	//fflush(stdout);
	//fgets(string, 100, stdin);
	//printf("%s", string);

	/*FILE *file;
	char * line = NULL;
	if ((file = fopen("/Users/fabianterhorst/bla.txt", "r")) != NULL) {
		size_t len = 0;
		int count = 1;
		while ((getline(&line, &len, file)) != -1) {
			printf("%d. Zeile %s", count, line);
			count++;
		}
	} else {
		printf("nope");
		return EXIT_FAILURE;
	}
	fclose(file);
	if (line)
		free(line);*/

	//int puffer[5][2]={{1, 564}, {2, 123}, {3, 74}, {4, 297}, {5, 846}};

	long values[RANDOM_LENGTH][KEY_VALUE];
	randomize(values);
	for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}
	time_t vorher=time(NULL); // Anzahl Sekunden seit 1.1.1970 0:0
	quick_sort(values);
	time_t nachher=time(NULL); // Anzahl Sekunden seit 1.1.1970 0:0
	fflush(stdout);
	printf("Dauer: %d Sekunden\n", (int)(nachher-vorher));
	for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}



	return EXIT_SUCCESS;
}

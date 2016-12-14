/*
 * main.c
 *
 *  Created on: 02.12.2016
 *      Author: fabianterhorst
 */

#include "Praktikum4.h"

#include "tests.h"

int main(void) {
	//char string[100];
	//fflush(stdout);
	//fgets(string, 100, stdin);
	//strtok(str, "\r\n");
	//printf("%s", string);
	FILE *file;
	char * line = NULL;
	if ((file = fopen("/Users/fabianterhorst/bla.txt", "r"))) {
		size_t len = 0;
		int count = 1;
		while ((getline(&line, &len, file)) != END_READ) {
			printf("%d. Zeile %s", count, line);
			count++;
		}
	} else {
		return EXIT_FAILURE;
	}
	fclose(file);
	if (line)
		free(line);
	printf("\n");

	long values[RANDOM_LENGTH][KEY_VALUE];
	randomize(RANDOM_LENGTH, values);
	/*for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}*/
	struct timeval tv;
	struct timeval tv2;
	gettimeofday(&tv, NULL);
	quick_sort(RANDOM_LENGTH, values);
	fflush(stdout);
	gettimeofday(&tv2, NULL);
	printf("Dauer: %ld µs\n",(long)(tv2.tv_usec-tv.tv_usec));
	/*for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}*/

	run_all_tests();

	return EXIT_SUCCESS;
}

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
	/*for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}*/
	struct timeval tv;
	struct timeval tv2;
	int size;
	for (int i = 1;i < 6;i++) {
		size = (int) round(pow(RANDOM_LENGTH, i));
		long values[size][KEY_VALUE];
		randomize(size, values);
		gettimeofday(&tv, NULL);
		quick_sort(size, values);
		fflush(stdout);
		gettimeofday(&tv2, NULL);
		printf("%d %ld µs\n",size,(long)(tv2.tv_usec-tv.tv_usec));
	}
	/*for (int i = 0;i < RANDOM_LENGTH; i++) {
		printf("index: %ld value: %ld \n", values[i][0], values[i][1]);
	}*/

	run_all_tests();

	return EXIT_SUCCESS;
}

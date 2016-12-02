/*
 * Praktikum4.h
 *
 *  Created on: 02.12.2016
 *      Author: fabianterhorst
 */

#ifndef PRAKTIKUM4_H_
#define PRAKTIKUM4_H_

#define KEY_VALUE 2
#define RANDOM_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * fill a given long array with random values and numerate the indices from 1 to RANDOM_LENGTH
 *
 * @param values the long array to randomize
 */
void randomize(long values[RANDOM_LENGTH][KEY_VALUE]);

/*
 * Diese Funktion sortiert die Daten im Parameter "daten"
 * mit dem Quicksort-Algorithmus. Sie sollte nicht direkt
 * aufgerufen werden, sondern über die Funktion
 * "quick_sort(char *daten)".
 */
void qs(long daten[RANDOM_LENGTH][KEY_VALUE], long links, long rechts);

/**
 * Diese Funktion bereitet den Aufruf der Rekursiven "qs"
 * Funktion vor.
 *
 * Der Parameter "daten" enthält die Daten, die sortiert
 * werden sollen.
 */
void quick_sort(long daten[RANDOM_LENGTH][KEY_VALUE]);

#endif /* PRAKTIKUM4_H_ */

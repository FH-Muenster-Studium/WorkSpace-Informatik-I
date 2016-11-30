/*
 * Praktikum3.h
 *
 *  Created on: 30.11.2016
 *      Author: fabianterhorst
 */

#ifndef PRAKTIKUM3_H_
#define PRAKTIKUM3_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define PUFFER_SIZE 100

#define KEY_SIZE 98

/**
 * reverse a given char input array
 *
 * @param length input length
 * @param count count of valid chars
 * @param input input char array
 * @param reversed reversed array
 */
void reverseInput(int *length, int *count, char input[], char reversed[]);

/**
 * lower a given char array
 *
 * @param length input length
 * @param array char array to lower
 */
void lowerCharArray(int *length, char array[]);

/**
 * fill array
 *
 * @param length array length
 * @param array array to fill
 */
void fillArray(int *length, char array[]);

/**
 * encrypt a given input char array
 *
 * @param key encryption key
 * @param length input length
 * @param input input char array
 *
 */
void encryptInput(char key[], int *length, char input[]);

/**
 * decrypt a given char array
 *
 * @param key then decryption key
 * @param length input length
 * @param input input char array
 *
 */
void decryptInput(char key[], int *length, char input[]);

/**
 * check if the given integer is a prime number
 *
 * @param number number to check
 * @return 1 if prime number and 0 when not
 *
 */
int istPrim(int number);

/**
 * return the prime numbers between 0 and the given number
 *
 * @param number number border to check prime numbers
 * @return the count of prime numbers at the given range
 */
int primzahlenBis(int number);

/**
 * print the given char as a binary
 *
 * @param input input to print as an binary
 */
void inBits(char input);

/**
 * control lights
 *
 * @param lights the current light states
 * @param index the current light index to control
 * @param command the current command to control the light
 */
void lampeSchalten(char *lights, int *index, int *command);

#endif /* PRAKTIKUM3_H_ */

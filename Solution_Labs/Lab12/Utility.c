/*
 * File: Utility.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 10
 * Created: October 30, 2024
 * Last Updated: October 30, 2024
 */

#include "Utility.h"

int get_int() {

	int input = 0;
	scanf("%d", &input);
	clear_buffer();
	return input;
}

char get_char() {

	char input = 0;
	scanf("%c", &input);
	clear_buffer();
	return input;
}

void clear_lines(int n) {

	for (int i = 0; i < n; i++) {
		printf("\033[1A");
		printf("\r\033[K");
	}
}

void clear_buffer() {

	// flushes the standard input
	// (clears the input buffer)
	while ((getchar()) != '\n');
}

int random_range(int min, int max) {

	return (rand() % ((max + 1) - min)) + min;
}
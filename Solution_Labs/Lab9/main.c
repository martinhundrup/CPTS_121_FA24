/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 21, 2024
 * Last Updated: October 29, 2024
 */

#include "Testing.h" // did not includ Lab9.h - why?

void remove_newline(char* str) {

	for (int i = 0; 1; i++) {
		if (str[i] == '\n') str[i] = ' ';
		if (str[i] == '\0') return;
	}
}


int main() {

	printf("lab 9 example solution:\n\n");

	test_string_reverse();
	test_my_strcpy();
	test_my_strcat();
	test_my_strcmp();
	test_my_strlen();

	return 0;
}
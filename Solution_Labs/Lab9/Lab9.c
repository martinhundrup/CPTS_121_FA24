/*
 * File: Lab9.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 21, 2024
 * Last Updated: October 23, 2024
 */

#include "Lab9.h"

char* string_reverse(char* str) {

	// using pointer notation only
	int len = my_strlen(str);
	int j = len - 1;
	for (int i = 0; i < len / 2; i++) {

		char temp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j--) = temp;
	}

	return str;
}

char* my_strcpy(char* destination, const char* source) {

	// what could go wrong in this function? is it safe?

	// loop through source
	int len = my_strlen(source);
	for (int i = 0; i <= len; i++) { // does this copy the NULL character?

		destination[i] = source[i];
	}

	return destination;
}

char* my_strcat(char* destination, const char* source) {

	// what is unsafe about this function?

	// we need both string's lengths
	int d_len = my_strlen(destination);
	int s_len = my_strlen(source);

	for (int i = 0; i < s_len; i++) {

		destination[i + d_len] = source[i];
	}

	return destination;
}

int my_strcmp(const char* s1, const char* s2) {

	int len = my_strlen(s1);
	for (int i = 0; i < len; i++) {

		if (s2[i] == '\0')
			return 1; // RHS is equal to LHS but shorter
		else if (s1[i] < s2[i])
			return -1; // LHS is less than RHS
		else if (s2[i] < s1[i])
			return 1; // RHS is less than LHS
		else if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
			return -1; // LHS is equal to RHS but shorter
	}

	return 0; // they are equal
}

int my_strlen(const char* s) {

	int i = 0;
	for (; s[i] != '\0'; i++);
	return i;
}
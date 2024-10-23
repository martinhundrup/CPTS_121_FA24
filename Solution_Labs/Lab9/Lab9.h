/*
 * File: Lab9.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 20, 2024
 * Last Updated: October 23, 2024
 */

// guard code
#ifndef LAB9_H
#define LAB9_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
	Reverses a string in-place.

	@param the string to reverse

	@param the reversed string
*/
char* string_reverse(char* str);

/*
	Copies all characters from the source into the destination.

	@param the destination for the copied string
	@param the source string that gets copied

	@return the copy of the source string - destination
*/
char* my_strcpy(char* destination, const char* source);

/*
	Appends a string onto the end of another.

	@param the string that gets appended to
	@param the string to copy

	@return the newly appended string - destination
*/
char* my_strcat(char* destination, const char* source);

/*
	Performs a comparison on two strings. Case sensitive.

	@param the LHS string
	@param the RHS string

	@return -1 if LHS has earlier dictionary ordering, 0 if equal, 1 otherwise
*/
int my_strcmp(const char* s1, const char* s2);

/*
	Calculates the length of a string.

	@param the string to find the length of

	@return the length of the string (not including NULL)
*/
int my_strlen(const char* s);

#endif

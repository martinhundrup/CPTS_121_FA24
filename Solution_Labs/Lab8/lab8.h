/*
 * File: lab8.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 8
 * Created: October 14, 2024
 * Last Updated: October 18, 2024
 */

// guard code
#ifndef LAB8_H
#define LAB8_H

#define _CRT_SECURE_NO_WARNINGS

#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma region Task 1

/*
	Stores integers from a file into an array, then reverses the order.
*/
void task_1();

/*
	Reads integer from a file and stores into an array.
	Assumes the buffer has enough room allocated.

	@param a filestream to read from
	@param the integer array to store into

	@return the amount of items read from the file
*/
int fread_int_to_array(FILE* infile, int* buffer);

/*
	Reverses an integer array in-place.

	@param the array to reverse
	@param the amount of items to reverse
*/
void reverse_array(int* array, int num);

/*
	Prints the contents of an integer array to the screen.

	@param the integer array to print
	@param the number of items to print
*/
void print_int_array(int* array, int num);

#pragma endregion

#pragma region Task 2

/*
	Removes white spaces from a character array.
*/
void task_2();

/*
	Removes all whitespace ' ' from an array of characters.
	Moves all non-whitespaces to the left.

	@param the array to remove spaces from
	@param the number of elements to check.

	@return the amount of whitespaces removed.
*/
int remove_whitespace(char* buffer, int num);

/*
	Prints the contents of an character array to the screen.

	@param the character array to print
	@param the number of items to print
*/
void print_char_array(char* array, int num);

#pragma endregion

#pragma region Task 3

/*
	Creates a histogram of randomly generated numbers.
*/
void task_3();

/*
	Generates a random integer between [min, max]

	@param min inclusive
	@param max inclusive

	@return the random value
*/
int generate_int(int min, int max);

#pragma endregion

#pragma region Task 4

/*
	Plays a game of hangman.
*/
void task_4();

/*
	Starts a game of hangman.

	@param the word to guess

	@return if the player won or not
*/
int hangman(char* word);

/*
	Checks if a string contains a character.

	@param the string to check
	@param the character to check for

	@return 1 if true, 0 if false
*/
int str_contains(char* word, char c);

#pragma endregion

#endif

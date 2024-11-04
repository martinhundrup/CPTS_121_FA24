/*
 * File: Utility.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 10
 * Created: October 30, 2024
 * Last Updated: October 30, 2024
 */

#ifndef UTILITY_H
#define UTILITY_H

#define _CRT_SECURE_NO_WARNINGS

 // for colored text
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>	// isdigit()
#include <string.h>	// strtok()

/*
	Gets an integer from the user.

	@return the value entered in stdin
*/
int get_int();

/*
	Gets an character from the user.

	@return the value entered in stdin
*/
char get_char();

/*
	Clears terminal lines.

	@param the number of lines to clear
*/
void clear_lines(int n);

/*
	Clears the stdin buffer.
	source: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
*/
void clear_buffer();

/*
	Generates a random integer between [min, max]

	@param min inclusive
	@param max inclusive

	@return the random value
*/
int random_range(int min, int max);

#endif


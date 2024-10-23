/*
 * File: Testing.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 21, 2024
 * Last Updated: October 23, 2024
 */

// guard code
#ifndef TESTING_H
#define TESTING_H

#define _CRT_SECURE_NO_WARNINGS

#include <string.h> // for testing purposes only
#include "Lab9.h" // need to include other one to test the functions

// for colored text
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

 /*
	 Tests the string_reverse() function and outputs the results.
 */
void test_string_reverse();

/*
	Tests the my_strcpy() function and outputs the results.
*/
void test_my_strcpy();

/*
	Tests the my_strcat() function and outputs the results.
*/
void test_my_strcat();

/*
	Tests the my_strcmp() function and outputs the results.
*/
void test_my_strcmp();

/*
	Tests the my_strlen() function and outputs the results.
*/
void test_my_strlen();

#endif
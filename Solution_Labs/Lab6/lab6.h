/*
 * File: lab6.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 6
 * Created: September 29, 2024
 * Last Updated: October 4, 2024
 */

// guard code
#ifndef LAB6_H
#define LAB6_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>	// for random number generation
#include <time.h>	// for random number generation

#pragma region Task 1

/*
	Determines if the sum of integers read from a file is prime.
*/
void task_1();

/*
	Sums all integers in a file.

	@param the file stream to read from

	@return the sum of the contents
*/
int f_sum_int(FILE* infile);

/*
	Determines if an integer is prime.

	@param the integer to check

	@return 1 if prime, 0 if not
*/
int is_prime(int num);

/*
	Reads an integer number from a file.

	@param the FILE* stream

	@return the next value from the file
*/
int f_read_int(FILE* infile);

/*
	Finds the sum of all digits in an integer.

	@param the integer to sum the digits of

	@return the sum of the digits
*/
int sum_digits(int num);

#pragma endregion

#pragma region Task 2

/*
	Prompts the user for an integer, and finds that factorial.
*/
void task_2();

/*
	Find the factorial of index n.

	@parameter the index to find

	@return the value of its factorial
*/
int factorial(int n);

#pragma endregion

#pragma region Task 3

/*
	Prompts the user for an integer, and finds that fibonacci number.
*/
void task_3();

/*
	Find the fibonacci number of n.

	@parameter the fibonacci to find

	@return the value
*/
int fibonacci(int n);

#pragma endregion

#pragma region Task 4

/*
	Prompts the user to guess a number between -100 and 100 inclusive.
*/
void task_4();

/*
	Generates a random integer between [min, max]

	@param min inclusive
	@param max inclusive

	@return the random value
*/
int generate_int(int min, int max);

#pragma endregion

#endif
/*
 * File: Lab12.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 12
 * Created: November 14, 2024
 * Last Updated: November 14, 2024
 */

// guard code
#ifndef LAB12_H
#define LAB12_H

#define _CRT_SECURE_NO_WARNINGS

#define SIZE 10 // the size of the maze

#include "Utility.h"

#pragma region Task 1

/*
	Performs task 1.
*/
void task_1();

/*
	Recursively recurses a string.

	@param the string to reverse
	@param the end of the string
*/
void rec_string_reverse(char* str, int n);

#pragma endregion

#pragma region Task 2

/*
	Performs task 2.
*/
void task_2();

/*
	Recursively finds the sum of an integer's digits.

	@param the number to process

	@return the sum if its digits
*/
int rec_sum_digits(int num);

#pragma endregion

#pragma region Task 3

/*
	Performs task 3.
*/
void task_3();

/*
	Loads a maze with the contents of a file.

	@param the file to read from
	@param the maze to load into
*/
void load_maze(FILE* infile, char maze[SIZE][SIZE]);

/*
	Prints a maze to the screen.

	@param the maze to display
*/
void print_maze(char maze[SIZE][SIZE]);

/*
	Recursively traverses a maze to find the shortest path.

	@param the maze to traverse
	@param the current row index
	@param the current col index
	@param the current recursive depth of the call
*/
int traverse_maze(char maze[SIZE][SIZE], int row, int col, int n);

#pragma endregion

#pragma region Task 4

/*
	Performs task 4.
*/
void task_4();

#pragma endregion


#endif

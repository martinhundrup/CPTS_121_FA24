/*
 * File: lab5.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 5
 * Created: September 23, 2024
 * Last Updated: September 23, 2024
 */

// guard code
#ifndef LAB5_H
#define LAB5_H

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// function prototypes
#pragma region Task 1

/*
*	Determines the tax bracket for an employee.
*/
void task_1();

/*
*	Reads a double precision number from a file.
* 
*	@param the FILE* stream	
* 
*	@return the next value from the file
*/
double fread_double(FILE* infile);

#pragma endregion

#pragma region Task 2

/*
*	Calculates the average of all numbers in a file.
*/
void task_2();

/*
*	Creates a file with an amount of numbers
* 
*	@param the name of the file to write to
*	@param the number of double precision numbers to write
*/
void create_data_file(char* file_name, int n);

/*
*	Writes a double precision number to a file.
* 
*	@param the FILE* to write to
*	@param the value to write to the file
*/
void fwrite_double(FILE* outfile, double x);

#pragma endregion

#pragma region Task 3

/*
*	Finds the greatest common divisor of two integers.
*/
void task_3();

/*
*	Performs the gcd algorithm to find the gcd of two integers.
* 
*	@param the first integer
*	@param the second integer
*	
*	@return the gcd
*/
int calc_gcd(int num1, int num2);

#pragma endregion

#pragma region Task 4

/*
*	Determines the min and max values from a file.
*/
void task_4();

#pragma endregion

#endif // end guard code
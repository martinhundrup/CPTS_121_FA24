/*
 * File: lab7.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 7
 * Created: October 7, 2024
 * Last Updated: October 11, 2024
 */

 // guard code
#ifndef LAB7_H
#define LAB7_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h> // for ceil()

#pragma region Task 1

/*
	Gets the initals of a user utilizing output parameters.
*/
void task_1();

/*
	Gets the initials of a user.

	@param the buffer for storing the first initial
	@param the buffer for storing the middle initial
	@param the buffer for storing the last initial
*/
void get_initials(char* first, char* middle, char* last);

#pragma endregion

#pragma region Task 2

/*
	Determines internet charges for customers.
*/
void task_2();

/*
	Determines the total charge and average rate for a customer.

	@param the hours of connectivity the user had
	@param the buffer to store the total charge into
	@param the buffer to store the average rate into
*/
void charges(double hours, double* total_charge, double* average_rate);

/*
	Rounds a real number to the hundredths place

	@param the floating point value to round

	@return the rounded value
*/
double round_money(double value);

#pragma endregion

#pragma region Task 3

/*
	Calculates and predicts the revenue Broadway shows will earn.
*/
void task_3();

/*
	Calculates the revenue as a function of time.

	@param the number of years since 1984

	@return the total revenue earned
*/
double revenue(int t);

/*
	Predicts the year in which revenue will first equal or exceed a certain value.

	@param the number of millions of dollars earned

	@return the year that is expected to take place
*/
int predict(double value);

#pragma endregion

#endif

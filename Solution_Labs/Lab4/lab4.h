/*
 * File: lab4.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 4
 * Created: September 16, 2024
 * Last Updated: September 20, 2024
 */

#ifndef LAB4_H
#define LAB4_H

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#pragma region Task 1

 /*
	 Determines a person's coloric intake for a 24-hour span.
 */
void task_1();

/*
	Calculates the basal metabolic rate (BMR) of an individual.
	
	@param the gender of the individual: 0 for man, 1 for woman
	@param the weight of the individual in pounds
	@param the height of the individual in inches
	@param the age of the individual in years.
*/
double calc_bmr(int gender, double weight, double height, double age);

/*
	Calculates the daily calorie intake of an individual.

	@param the activity level of the individual
	@param the BMR of the individual
*/
double calc_calories(int activity, double bmr);

#pragma endregion

#pragma region Task 2

/*
	Determines a baseball player's bonus at the end of a season.
*/
void task_2();

/*
	Gets a character from the user

	@return the character entered
*/
char get_char();

#pragma endregion

#pragma region Task 3

/*
	Reads five numbers from a file and finds the averge, min, and max values.
*/
void task_3();

/*
	Gets the next floating point value from a file stream

	@param a pointer to the file
	@return the floating point value extracted
*/
double fget_double(FILE* infile);

#pragma endregion

#endif
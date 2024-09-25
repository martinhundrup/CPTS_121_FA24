/*
 * File: PA3.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA3
 * Created: August 26, 2024
 * Last Updated: September 22, 2024
 */

#ifndef PA3

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
*	Reads one double precision number from the input file. 
*	Note: You may assume that the file only contains real numbers.
* 
*	@param FILE* infile: pointer to the input file stream
* 
*	@return the next double float found in the file
*/
double read_double(FILE* infile);

/*
*	Reads one integer number from the input file.
*
*	@param FILE* infile: pointer to the input file stream
*
*	@return the next integer found in the file
*/
int read_integer(FILE* infile);

/*
*	Finds the sum of 5 doubles.
*
*	@param double number1: the first number
*	@param double number2: the second number
*	@param double number3: the third number
*	@param double number4: the fourth number
*	@param double number5: the fifth number
*
*	@return the sum of all 5 arguments
*/
double calculate_sum(double number1, double number2, double number3, 
	double number4, double number5);

/*
*	Finds the average of a sum.
*
*	@param double sum: the total sum
*	@param int number: the number of entries that make up the dataset
*
*	@return the mean average of the sum. -1 if number is <= 0
*/
double calculate_mean(double sum, int number);

/*
*	Finds the deviation of a mean.
*
*	@param double number: an entry in the dataset
*	@param double mean: the mean of the dataset
*
*	@return the deviation of the entry
*/
double calculate_deviation(double number, double mean);

/*
*	Finds the variance of an entry.
*
*	@param double deviation1: the deviation of the first entry
*	@param double deviation2: the deviation of the second entry
*	@param double deviation3: the deviation of the third entry
*	@param double deviation4: the deviation of the fourth entry
*	@param double deviation5: the deviation of the fifth entry
*	@param double number: the number of entries in the dataset
*
*	@return the variance of the entry
*/
double calculate_variance(double deviation1, double deviation2,
	double deviation3, double deviation4, double deviation5, int number);

/*
*	Finds the standard deviation of a dataset.
*
*	@param double variance: the variance of the dataset
*
*	@return the standard deviation of a dataset
*/
double calculate_standard_deviation(double variance);

/*
*	Determines the maximum number out of the five input parameters.
*
*	@param double number1: the first entry
*	@param double number2: the second entry
*	@param double number3: the third entry
*	@param double number4: the fourth entry
*	@param double number5: the fifth entry
*
*	@return the value of the maximum valued entry
*/
double find_max(double number1, double number2, double number3,
	double number4, double number5);

/*
*	Determines the minimum number out of the five input parameters.
*
*	@param double number1: the first entry
*	@param double number2: the second entry
*	@param double number3: the third entry
*	@param double number4: the fourth entry
*	@param double number5: the fifth entry
*
*	@return the value of the minimum valued entry
*/
double find_min(double number1, double number2, double number3,
	double number4, double number5);

/*
*	Writes a double precision number (to the hundredths place) to an output file.
*
*	@param FILE* infile: pointer to the input file stream
*	@parame double number: the value to write
*/
void print_double(FILE* outfile, double number);

#endif
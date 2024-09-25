/*
 * File: PA3.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA3
 * Created: August 26, 2024
 * Last Updated: September 23, 2024
 */

#include "PA3.h"

double read_double(FILE* infile) {

	double _x = 0.0;
	fscanf(infile, "%lf", &_x);
	return _x;
}

int read_integer(FILE* infile) {

	int _x = 0;
	fscanf(infile, "%d", &_x);
	return _x;
}

double calculate_sum(double number1, double number2, double number3,
	double number4, double number5) {

	return number1 + number2 + number3 + number4 + number5;
}

double calculate_mean(double sum, int number) {

	if (number == 0) return -1;

	return sum / number;
}

double calculate_deviation(double number, double mean) {

	return number - mean;
}

double calculate_variance(double deviation1, double deviation2,
	double deviation3, double deviation4, double deviation5, int number) {

	return calculate_mean(pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + 
		pow(deviation4, 2) + pow(deviation5, 2), 5);
}

double calculate_standard_deviation(double variance) {

	return sqrt(variance);
}

double find_max(double number1, double number2, double number3,
	double number4, double number5) {

	double max = number1;

	if (number2 > max)
		max = number2;
	if (number3 > max)
		max = number3;
	if (number4 > max)
		max = number4;
	if (number5 > max)
		max = number5;

	return max;
}

double find_min(double number1, double number2, double number3,
	double number4, double number5) {

	double min = number1;

	if (number2 < min)
		min = number2;
	if (number3 < min)
		min = number3;
	if (number4 < min)
		min = number4;
	if (number5 < min)
		min = number5;
	
	return min;
}

void print_double(FILE* outfile, double number) {

	fprintf(outfile, "%.2lf\n", number);
}
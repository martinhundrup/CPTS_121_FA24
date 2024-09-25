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

int main() {

	printf("PA 3 example solution.\n\n");

#pragma region Declare variables

	// GPAs
	double _gpa1 = 0.0, _gpa2 = 0.0, _gpa3 = 0.0,
		_gpa4 = 0.0, _gpa5 = 0.0;

	// class standings
	int _cs1 = 0, _cs2 = 0, _cs3 = 0, _cs4 = 0, _cs5 = 0;

	// ages
	double _age1 = 0.0, _age2 = 0.0, _age3 = 0.0,
		_age4 = 0.0, _age5 = 0.0;

	// sums
	double _gpaSum = 0.0;
	int _csSum = 0;
	double _ageSum = 0.0;

	// means
	double _gpaMean = 0.0;
	double _csMean = 0.0;
	double _ageMean = 0.0;

	// deviations
	double _deviation1 = 0.0, _deviation2 = 0.0, _deviation3 = 0.0,
		_deviation4 = 0.0, _deviation5 = 0.0;
	
	// variance
	double _variance = 0.0;

	// standard deviation
	double _gpaStdDeviation = 0.0;

	// min/max
	double _gpaMin = 0.0;
	double _gpaMax = 0.0;

#pragma endregion

#pragma region Read from file

	FILE* _infile = fopen("input.dat", "r"); // the second param must be a string, not char
	char garbage = '\0';

	// read student 1
	{
		// throw away student ID
		read_double(_infile);

		// keep these
		_gpa1 = read_double(_infile);
		_cs1 = read_integer(_infile);
		_age1 = read_double(_infile);
	}

	// read student 2
	{
		// thow away empty line
		fgetc(_infile);
		// throw away student ID
		read_double(_infile);

		// keep these
		_gpa2 = read_double(_infile);
		_cs2 = read_integer(_infile);
		_age2 = read_double(_infile);
	}

	// read student 3
	{
		// thow away empty line
		fgetc(_infile);
		// throw away student ID
		read_double(_infile);

		// keep these
		_gpa3 = read_double(_infile);
		_cs3 = read_integer(_infile);
		_age3 = read_double(_infile);
	}
	
	// read student 4
	{
		// thow away empty line
		fgetc(_infile);
		// throw away student ID
		read_double(_infile);

		// keep these
		_gpa4 = read_double(_infile);
		_cs4 = read_integer(_infile);
		_age4 = read_double(_infile);
	}

	// read student 5
	{
		// thow away empty line
		fgetc(_infile);
		// throw away student ID
		read_double(_infile);

		// keep these
		_gpa5 = read_double(_infile);
		_cs5 = read_integer(_infile);
		_age5 = read_double(_infile);
	}

	fclose(_infile);

#pragma endregion

#pragma region Calculate results

	_gpaSum = calculate_sum(_gpa1, _gpa2, _gpa3, _gpa4, _gpa5);
	_csSum = calculate_sum(_cs1, _cs2, _cs3, _cs4, _cs5);
	_ageSum = calculate_sum(_age1, _age2, _age3, _age4, _age5);

	_gpaMean = calculate_mean(_gpaSum, 5);
	_csMean = calculate_mean(_csSum, 5);
	_ageMean = calculate_mean(_ageSum, 5);

	_deviation1 = calculate_deviation(_gpa1, _gpaMean);
	_deviation2 = calculate_deviation(_gpa2, _gpaMean);
	_deviation3 = calculate_deviation(_gpa3, _gpaMean);
	_deviation4 = calculate_deviation(_gpa4, _gpaMean);
	_deviation5 = calculate_deviation(_gpa5, _gpaMean);

	_variance = calculate_variance(_deviation1, _deviation2, _deviation3,
		_deviation4, _deviation5, 5);

	_gpaStdDeviation = calculate_standard_deviation(_variance);

	_gpaMin = find_min(_gpa1, _gpa2, _gpa3, _gpa4, _gpa5);
	_gpaMax = find_max(_gpa1, _gpa2, _gpa3, _gpa4, _gpa5);

#pragma endregion

#pragma region Write to file

	FILE* _outfile = fopen("output.dat", "w");

	print_double(_outfile, _gpaMean);
	print_double(_outfile, _csMean);
	print_double(_outfile, _ageMean);
	print_double(_outfile, _gpaStdDeviation);
	print_double(_outfile, _gpaMin);
	print_double(_outfile, _gpaMax);

	fclose(_outfile);

#pragma endregion

	return 0;
}
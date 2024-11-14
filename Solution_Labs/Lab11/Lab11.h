/*
 * File: Lab11.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 11
 * Created: November 14, 2024
 * Last Updated: November 14, 2024
 */

#ifndef LAB11_H
#define LAB11_H

#define _CRT_SECURE_NO_WARNINGS

#define MAX_EMPLOYEES 200

#include <stdio.h>
#include <string.h>

// employee struct definition
typedef struct employee
{
	char name[100];			// employee's name - last, first
	char title;				// title 'B' or 'M'
	double hours_worked;	// total number of hours worked
	double payrate;			// pay rate per hour
	double payment;			// total payment for the pay period – you will compute!
} Employee;


/*
	Performs lab 11.
*/
void lab_11();

/*
	Reads up to 200 records from the input stream and stores into the payroll array.

	@param the payroll input file stream
	@param the payroll array

	@return the total number of records inserted
*/
int read_records(FILE* payroll_input, Employee payroll[MAX_EMPLOYEES]);

/*
	Computes the payments for each employee in the payroll array.

	@param the payroll array.

	@return the total amount paid to all employees
*/
double compute_payments(Employee payroll[MAX_EMPLOYEES], int size);

// finds and returns the min and max payments via pointer

/*
	Finds the min and max payments.

	@param the payroll array
	@param the number of employees to check
	@param the location to store the max payment
	@param the location to store the min payment
*/
void find_extrema(Employee payroll[MAX_EMPLOYEES], int size, double* p_max, double* p_min);

#endif

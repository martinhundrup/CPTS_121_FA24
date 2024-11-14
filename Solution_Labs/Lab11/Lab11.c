/*
 * File: Lab11.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 11
 * Created: November 14, 2024
 * Last Updated: November 14, 2024
 */

#include "Lab11.h"

void lab_11() {

	// the payroll array; may not exceed 200 employees
	Employee payroll[MAX_EMPLOYEES];

	// open payroll.txt for mode read
	FILE* payroll_input = fopen("payroll.txt", "r");

	// read and store values into our array
	// keep track of number of employees inserted
	int num_employees = read_records(payroll_input, payroll);

	// calculate the payment for each employee and store total amount paid
	double total_paid = compute_payments(payroll, num_employees);

	// compute average payment per employee
	double average_paid = total_paid / num_employees;

	// find the min and max payments
	double max_payment = 0.0, min_payment = 0.0;
	find_extrema(payroll, num_employees, &max_payment, &min_payment);

	// open paid.txt for mode write
	FILE* paid_output = fopen("paid.txt", "w");

	// write the total, average, max, and min payments to the output file
	fprintf(paid_output, "total payment: %.2lf\n", total_paid);
	fprintf(paid_output, "avg payment: %.2lf\n", average_paid);
	fprintf(paid_output, "max payment: %.2lf\n", max_payment);
	fprintf(paid_output, "min payment: %.2lf\n", min_payment);


	// close payroll.txt and paid.txt files
	fclose(payroll_input);
	fclose(paid_output);
}

int read_records(FILE* payroll_input, Employee payroll[MAX_EMPLOYEES]){

	// holds the name from the file
	char name_temp[100] = { '\0' };

	int i = 0;
	while (!feof(payroll_input)) {

		// store the name value
		fgets(payroll[i].name, 100, payroll_input);
		//strcpy(payroll[i].name, name_temp);

		// store the title
		fscanf(payroll_input, "%c", &payroll[i].title);

		// store the hours worked
		fscanf(payroll_input, "%lf", &payroll[i].hours_worked);

		// store the pay rate (wage)
		fscanf(payroll_input, "%lf", &payroll[i].payrate);

		// clear newline char
		fgetc(payroll_input);

		i++; // increment our index

		// break out of loop if too many employees are present in the file
		if (i >= MAX_EMPLOYEES) {
			break;
		}
	}

	// return the amount of employees inserted
	return i;
}

double compute_payments(Employee payroll[MAX_EMPLOYEES], int size) {

	double total = 0.0;

	for (int i = 0; i < size; i++) {

		double payment = 0.0; // standard payment
		double overtime = 0.0; // overtime payment


		// determine if this employee worked overtime
		if (payroll[i].hours_worked <= 80) { 
			// no overtime
			payment = payroll[i].hours_worked * payroll[i].payrate;
		}
		else {
			payment = 80 * payroll[i].payrate;

			// determine whether they were a basic or manager
			if (payroll[i].title == 'M') {
				overtime = (payroll[i].hours_worked - 80) * 1.8 * payroll[i].payrate;
			}
			else {
				overtime = (payroll[i].hours_worked - 80) * 1.5 * payroll[i].payrate;
			}
		}

		// set the payment for each employee
		payroll[i].payment = overtime + payment;

		// add their payment to our total sum
		total += overtime + payment;
	}

	return total;
}

void find_extrema(Employee payroll[MAX_EMPLOYEES], int size, double* p_max, double* p_min) {

	// initialize our max and min values
	*p_max = payroll[0].payment;
	*p_min = payroll[0].payment;

	for (int i = 0; i < size; i++) {

		// determine if min
		if (payroll[i].payment > *p_max) {
			*p_max = payroll[i].payment;
		}

		// determine if max
		else if (payroll[i].payment < *p_min) {
			*p_min = payroll[i].payment;
		}
	}
}
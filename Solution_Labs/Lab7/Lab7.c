/*
 * File: lab7.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 7
 * Created: October 7, 2024
 * Last Updated: October 11, 2024
 */

#include "lab7.h"


#pragma region Task 1

void task_1() {

	printf("task 1 example solution:\n");

	char first = '\0', middle = '\0', last = ']0';
	get_initials(&first, &middle, &last);

	printf("entered initials:\n");
	printf("\tfirst: %c\n", first);
	printf("\tmiddle: %c\n", middle);
	printf("\tlast: %c\n", last);	
}

void get_initials(char* first, char* middle, char* last) {

	printf("\nplease enter your first initial: ");
	scanf("%c", first);
	getchar(); // clear newline character

	printf("please enter your middle initial: ");
	scanf("%c", middle);
	getchar(); // clear newline character

	printf("please enter your last initial: ");
	scanf("%c", last);
	getchar(); // clear newline character
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("task 2 example solution:\n");

	// open file streams
	FILE* input_file = fopen("ISP_input.txt", "r");
	FILE* output_file = fopen("ISP_output.txt", "w");

	// get rid of the month and year integers
	int customer_num = 0;
	fscanf(input_file, "%d", &customer_num);
	fscanf(input_file, "%d", &customer_num);

	// calculate each customers data
	double hours = 0.0;
	double total = 0.0;
	double avg = 0.0;
	while (!feof(input_file)) {

		// store data
		fscanf(input_file, "%d", &customer_num);
		fscanf(input_file, "%lf", &hours);

		// calculate the data
		charges(hours, &total, &avg);

		// output data to file and screen
		fprintf(output_file, "customer num: %d, total: %.2lf, avg: %.2lf\n", 
			customer_num, round_money(total), round_money(avg));
		fprintf(stdout, "customer num: %d, total: %.2lf, avg: %.2lf\n", 
			customer_num, round_money(total), round_money(avg));
	}

	// close the file streams
	fclose(input_file);
	fclose(output_file);
}

void charges(double hours, double* total_charge, double* average_rate) {

	// less than or at 10 hours - 7.99 per hours
	if (hours <= 10.0)
		*total_charge = 7.99;
	else // greater than 10 hours
		*total_charge = 7.99 + ((ceil(hours - 10) * 1.99));

	// calc the average rate
	*average_rate = *total_charge / hours;
}

double round_money(double value) {

	return ((int)(value * 100) / (double)100);
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("task 3 example solution:\n");

	int year = predict(1000000); // 1 trillion dollars

	FILE* output = fopen("revenue.txt", "w");

	for (int i = 0; i <= year - 1984; i++) {

		fprintf(output, "year: %d, revenue: %.3lf\n", 1984 + i, revenue(i));
		fprintf(stdout, "year: %d, revenue: %.3lf\n", 1984 + i, revenue(i)); // mimic to screen
	}

	fclose(output);
}

double revenue(int t) {

	// t is years since 1984
	return 203.265 * pow(1.071, t);
}

int predict(double value) {

	int year = 0;
	for (year; revenue(year) < value; year++);

	return year + 1984;
}

#pragma endregion
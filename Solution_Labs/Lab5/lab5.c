/*
 * File: lab5.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 5
 * Created: September 23, 2024
 * Last Updated: September 23, 2024
 */

#include "lab5.h"

#pragma region Task 1

void task_1() {

	printf("Task 1:\n");

	FILE* infile = fopen("task1.txt", "r");

	double sum = 0.0;

	// only read in 4 lines from the file
	for (int i = 0; i < 4; i++) {

		sum += fread_double(infile);
	}

	char symbol = '\0';
	if (sum < 15000) { // low income
		symbol = 'l';
	}
	else if (sum < 200000) { // medium income (WTF)
		symbol = 'm';
	}
	else { // high income
		symbol = 'h';
	}

	fclose(infile);
	printf("tax bracket: %c\n", symbol);
}

double fread_double(FILE* infile) {

	double in = 0.0;
	fscanf(infile, "%lf", &in);

	return in;
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("Task 2:\n");
	char* file_name = "task2.txt";

	// create data file
	create_data_file(file_name, 50000); // as n goes to infinity, avg should approach 113.5
	FILE* infile = fopen(file_name, "r");

	int i = 0;
	double sum = 0.0;
	for (; !feof(infile); i++) { // rolling sum and amount summed

		sum += fread_double(infile);
	}

	fclose(infile);

	// output
	FILE* outfile = fopen("task2_output.txt", "w");
	fwrite_double(outfile, sum / i);
	printf("avg: %lf\n", sum / i);
	fclose(outfile);
}

void create_data_file(char* file_name, int n) {

	srand(time(NULL)); // start random number generation
	FILE* outfile = fopen(file_name, "w");

	for (; n > 0; n--) {

		fwrite_double(outfile, (double)(rand() % 500) / ((rand() % 5) + 1));

		if (n - 1 > 0) fprintf(outfile, "\n");
	}

	fclose(outfile);
}

void fwrite_double(FILE* outfile, double x) {

	fprintf(outfile, "%lf", x);
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("Task 3:\n");

	int num1 = 0, num2 = 0;
	
	// get user input
	printf("enter the first integer: ");
	scanf("%d", &num1);

	printf("enter the second integer: ");
	scanf("%d", &num2);

	printf("the greatest common divisor is: %d\n", calc_gcd(num1, num2));
}

int calc_gcd(int num1, int num2) {

	int r = num1 % num2; // remainder

	while (r != 0) {

		num1 = num2;
		num2 = r;
		r = num1 % num2;
	}

	return num2;
}

#pragma endregion

#pragma region Task 4

void task_4() {

	printf("Task 4:\n");

	// create test input file
	char* file_name = "task4.txt";
	create_data_file(file_name, 50);

	FILE* infile = fopen(file_name, "r");

	double min = INFINITY;
	double max = -INFINITY;

	while (!feof(infile)) {

		double n = fread_double(infile);

		if (n < min) min = n;
		if (n > max) max = n;
	}

	fclose(infile);
	printf("min: %lf\n", min);
	printf("max: %lf\n", max);
}

#pragma endregion

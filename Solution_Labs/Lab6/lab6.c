/*
 * File: lab6.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 6
 * Created: September 29, 2024
 * Last Updated: October 4, 2024
 */

#include "lab6.h"

#pragma region Task 1

void task_1() {

	printf("task 1 example solution:\n");

	FILE* infile = fopen("task1.txt", "r");
	int sum = f_sum_int(infile);
	fclose(infile);
	
	int digit_sum = sum_digits(sum);

	if (is_prime(sum))
		printf("the sum %d is prime\n", sum);
	else
		printf("the sum %d is not prime\n", sum);

	if (is_prime(digit_sum))
		printf("the sum of digits %d is prime\n", digit_sum);
	else
		printf("the sum of digits %d is not prime\n", digit_sum);
}

int f_sum_int(FILE* infile) {

	int sum = 0;

	while (!feof(infile)) {

		sum += f_read_int(infile);
	}

	return sum;
}

int is_prime(int num) {

	for (int i = 2; i < num / 2; i++) {

		if (num % i == 0)
			return 0; // not prime
	}

	return 1;
}

int f_read_int(FILE* infile) {

	int x = 0;
	fscanf(infile, "%d", &x);
	return x;
}

int sum_digits(int num) {

	int sum = 0;
	
	for (; num > 0; num /= 10) {

		sum += num % 10;
	}

	return sum;
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("task 2 example solution:\n");

	int input = -1;

	while (input < 0) {
		printf("please enter the value n to find the factorial of: ");
		input = f_read_int(stdin);
	}

	printf("the factorial of %d is %d\n", input, factorial(input));
}

int factorial(int n) {

	int product = 1;
	for (int i = 1; i <= n; i++) {

		product *= i;
	}

	return product;
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("task 3 example solution:\n");

	int input = -1;

	while (input < 0) {
		printf("please enter the value n to find the fibonacci of: ");
		input = f_read_int(stdin);
	}

	printf("the fibonacci of %d is %d\n", input, fibonacci(input));
}

int fibonacci(int n) {

	// base cases
	if (n == 0) return 0;
	if (n == 1) return 1;

	int a = 1;
	int b = 0;
	int f = 0;

	for (int i = 1; i < n; i++) {
		f = a + b;
		b = a;
		a = f;
	}

	return f;
}

#pragma endregion

#pragma region Task 4

void task_4() {

	srand(time(NULL)); // start random number generation

	int guess = -200;
	int target = generate_int(-100, 100);

	// for checking random number generator
	//for (int i = 0; i < 100000; i++) {
	//	int j = generate_int(-100, 100);
	//	if (j < -100 || j > 100) fprintf(stderr, "error");
	//}

	while (guess != target) {
		
		printf("enter your guess: ");
		guess = f_read_int(stdin);
		if (guess < target && guess >= -100)
			printf("too low!\n");
		else if (guess > target && guess <= 100)
			printf("too high!\n");
	}

	printf("correct! your number was %d\n", target);
}

int generate_int(int min, int max) {

	return (rand() % ((max + 1) - min)) + min;
}

#pragma endregion
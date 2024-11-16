/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 12
 * Created: November 14, 2024
 * Last Updated: November 14, 2024
 */

#include "lab12.h"

int foo(int n) {
	printf("%d\n", n);
	return foo(n + 1);
}

int main() {

	printf("lab 12 example solution.\n");
	//foo(0);

	//task_1();
	//task_2();
	task_3();
	//task_4();

	return 0;
}
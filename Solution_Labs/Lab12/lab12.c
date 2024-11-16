/*
 * File: lab12.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 12
 * Created: November 14, 2024
 * Last Updated: November 14, 2024
 */

#include "lab12.h"

#pragma region Task 1

void task_1() {

	char str[20] = "hello, world!";

	printf("string before reversal: %s\n", str);

	rec_string_reverse(str, strlen(str));

	printf("string after reversal: %s\n", str);
}

void rec_string_reverse(char* str, int n) {

	if (strlen(str) < n--) return; // end of string

	char t = str[0];
	str[0] = str[n];
	str[n] = t;

	// increment str pointer and index
	rec_string_reverse(++str, --n);
}

#pragma endregion

#pragma region Task 2

void task_2() {

	int n = 12345678;
	printf("n: %d\n", n);
	printf("sum of n's digits: %d\n", rec_sum_digits(n));
}

int rec_sum_digits(int num) {

	if (num < 10) return num; // base case

	return num % 10 + rec_sum_digits(num / 10);
}

#pragma endregion

#pragma region Task 3

void task_3() {

	char maze[SIZE][SIZE] = { 0 }; // create and init char 2D array
	FILE* infile = fopen("maze.txt", "r");
	load_maze(infile, maze); // load the maze
	int len = traverse_maze(maze, 1, 0, 0);
	print_maze(maze);
	printf("fastest solution to the maze: %d\n", len);
}

void load_maze(FILE* infile, char maze[SIZE][SIZE]) {

	// traverse matrix
	for (int i = 0; i < SIZE; i++) { // row index

		// get contents of the line
		char buffer[SIZE + 2] = { 0 };
		fgets(buffer, SIZE + 2, infile);

		for (int j = 0; j < SIZE; j++) { // col index

			maze[i][j] = buffer[j];
		}
	}
}

void print_maze(char maze[SIZE][SIZE]) {

	printf("----------------------\n");

	// traverse matrix
	for (int i = 0; i < SIZE; i++) {
		putchar('|');
		for (int j = 0; j < SIZE; j++) {

			if (maze[i][j] == 'o' || maze[i][j] == '-') // ending
				printf(GRN "%c " WHT, maze[i][j]);
			else
				printf("%c ", maze[i][j]);
		}
		putchar('|');
		putchar('\n');
	}
	printf("----------------------\n");
}

int traverse_maze(char maze[SIZE][SIZE], int row, int col, int n) {

	if (n > SIZE + SIZE) return 10000; // reached max limit for recursive depth - destroy path
	if (row < 0 || col >= SIZE || row >= SIZE || col < 0) return 10000; // out of bounds
	if (maze[row][col] == 'x') return 10000; // in a wall or already visited cell
	if (maze[row][col] == 'o') return 0; // found exit

	int up = traverse_maze(maze, row - 1, col, n + 1);
	int down = traverse_maze(maze, row + 1, col, n + 1);
	int left = traverse_maze(maze, row, col - 1, n + 1);
	int right = traverse_maze(maze, row, col + 1, n + 1);

	if (up <= down && up <= left && up <= right && up < 1000)
		return 1 + up;
	else if (down <= left && down <= right && down < 1000)
		return 1 + down;
	else if (left <= right && left < 1000)
		return 1 + left;
	else if (right < 1000)
		return 1 + right;

	return 10000; // no solution
}

#pragma endregion
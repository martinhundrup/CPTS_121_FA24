/*
 * File: lab8.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 8
 * Created: October 14, 2024
 * Last Updated: October 15, 2024
 */

#include "lab8.h"

#pragma region Task 1

void task_1() {

	printf("task 1 example solution:\n");

	FILE* infile = fopen("task1.dat", "r");

	int array[100] = { 0 };

	// read from then close file
	int n = fread_int_to_array(infile, array);
	fclose(infile);

	// display array state
	printf("the array prior to reversing:\n");
	print_int_array(array, n);

	reverse_array(array, n);

	// display array state
	printf("\nthe array after reversing:\n");
	print_int_array(array, n);
}

int fread_int_to_array(FILE* infile, int* buffer) {

	int i = 0; // counting variable

	// no code block needed because i++ increments
	while (fscanf(infile, "%d", &buffer[i++]) != EOF);
	return --i;
}

void reverse_array(int* array, int num) {

	// we only traverse half of the array, why?
	for (int i = 0; i < num / 2; i++) {

		int temp = array[i];
		array[i] = array[num - 1 - i];
		array[num - 1 - i] = temp;
	}
}

void print_int_array(int* array, int num) {

	for (int i = 0; i < num; i++) {
		printf("%d, ", array[i]);
	}

	printf("\n");
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("task 2 example solution:\n");

	char array[100] = "hel lo wo   rld  ! ";

	// display array state
	printf("the array prior to removing whitespace:\n");
	print_char_array(array, 20);

	int n = remove_whitespace(array, 20);

	// display array state
	printf("\nthe array after removing whitespace:\n");
	print_char_array(array, 16);
	printf("\nwhitespaces removed: %d\n", n);
}

int remove_whitespace(char* buffer, int num) {
	
	int count = 0;

	for (int i = 0; i < num; i++) {

		while (buffer[i] == ' ') { // move everything over

			count++;
			for (int j = i; j < num - 1; j++) {

				buffer[j] = buffer[j + 1];				
			}
			num--; // so we don't count or move places beyond num
		}
	}

	return count;
}

void print_char_array(char* array, int num) {

	for (int i = 0; i < num; i++) {
		printf("%c, ", array[i]);
	}

	printf("\n");
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("task 3 example solution:\n");

	// generate array of 20 random integers
	int array[MAX] = { 0 };
	for (int i = 0; i < MAX; i++) {
		array[i] = generate_int(1, 100);
	}

	// create and count histogram array
	int histogram[101] = { 0 };
	for (int i = 0; i < MAX; i++) {
		histogram[array[i]]++;
	}

	// display random array state
	printf("the random array:\n");
	print_int_array(array, MAX);

	// display histogram
	printf("the histogram:\n");
	print_int_array(histogram, 101);
}

int generate_int(int min, int max) {

	return (rand() % ((max + 1) - min)) + min;
}

#pragma endregion

#pragma region Task 4

void task_4() {

	printf("task 4 example solution:\n");

	// create pool of random words
	char words[][15] = { "apple", "banana", "orange", "melon", "grapes", "peach" };

	// choose a random word
	char* word = words[generate_int(0, 5)];

	int result = hangman(word);

	if (result) {
		printf("congratulations, you won!\n");
	}
	else {
		printf("sorry, maybe next time...\n");
	}

	printf("your word: %s\n", word);
}

int hangman(char* word) {

	int length = strlen(word); // string.h library function
	int guesses[256] = { 0 }; // keeps tracks of what characters the user has guessed so far
					          // trades space for time
	char input = '\0';
	int incorrect_guesses = 5; // amount of guesses before the player loses

	while (1) { // game loop

		int has_won = 1; // if the player has won or not

		// print current word thus far to screen:
		printf("incorrect guesses remaining: %d\n", incorrect_guesses);
		printf("your word: ");
		for (int i = 0; i < length; i++) {
			if (guesses[word[i]] > 0) printf("%c", word[i]);
			else {
				has_won = 0;
				printf("*");
			}
		}
		printf("\n\n");
		if (has_won) return 1; // player won
		

		// print guessed letters so far
		printf("your guesses: ");
		for (int i = 0; i < 256; i++) {
			if (guesses[i] > 0) printf("%c, ", i);
		}
		printf("\n\n");

		// get the user's guess this turn
		printf("enter your guess: ");
		scanf("%c", &input);
		getchar(); // clear newline character from input buffer

		if (guesses[input] == 0 && !str_contains(word, input)) { // first time guessing this letter and incorrect

			if (--incorrect_guesses <= 0) {
				return 0; // player lost
			}
		}

		guesses[input]++;
		system("cls");
	}
}

int str_contains(char* word, char c) {

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == c) return 1;
	}

	return 0;
}

#pragma endregion
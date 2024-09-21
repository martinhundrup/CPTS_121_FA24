/*
 * File: lab4.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 4
 * Created: September 16, 2024
 * Last Updated: September 20, 2024
 */

#include "lab4.h"

#pragma region Task 1

void task_1() {

	printf("\nTask 1:\n");

	/*
	*	format of task1.txt
	* 
	*	int gender // 0 for man 1 for woman
	*	double age in years
	*	double weight in pounds
	*	double height in inches
	*	int activity level (lowest 1 - highest 5)
	*/

	FILE* infile = fopen("task1.txt", "r");

	int gender = 0; fscanf(infile, "%d", &gender);
	double age = 0; fscanf(infile, "%lf", &age);
	double weight = 0; fscanf(infile, "%lf", &weight);
	double height = 0; fscanf(infile, "%lf", &height);
	int activity_level = 0; fscanf(infile, "%d", &activity_level);

	double bmr = calc_bmr(gender, weight, height, age);
	double calories = calc_calories(activity_level, bmr);

	if (calories == -1.0) {
		printf("error: invalid activity level.\n");
	}
	else {
		printf("bmr is: %lf\n", bmr);
		printf("calories needed: %lf\n", calories);
	}
}

double calc_bmr(int gender, double weight, double height, double age) {

	if (!gender) { // man
		return 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}

	return 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
}

double calc_calories(int activity, double bmr) {

	switch (activity) {

		case 1: // sedentary
			return bmr * 1.2;
		case 2: // low
			return bmr * 1.375;
		case 3: // moderate
			return bmr * 1.55;
		case 4: // high
			return bmr * 1.725;
		case 5: // extra
			return bmr * 1.9;
		default:
			return -1.0;
	}
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("\nTask 2:\n");
	
	// all star game
	printf("did the player make an all-star game appearance? (y/n): ");
	int all_star = get_char() == 'y';

	get_char(); // clean line
	// regular season mvp
	printf("was the player the regular season mvp? (y/n): ");
	int reg_mvp = get_char() == 'y';

	get_char(); // clean line
	// world series mvp
	printf("was the player the world series mvp? (y/n): ");
	int ws_mvp = get_char() == 'y';

	get_char(); // clean line
	// gold glove
	printf("was the player a gold glove winner? (y/n): ");
	int gold_glove = get_char() == 'y';

	get_char(); // clean line
	// silver slugger
	printf("was the player a silver slugger winner? (y/n): ");
	int silver_slugger = get_char() == 'y';

	get_char(); // clean line
	// home run champ
	printf("was the player the home run champ? (y/n): ");
	int hr_champ = get_char() == 'y';

	get_char(); // clean line
	// batting average
	printf("was the player the batting average champ? (y/n): ");
	int ba_champ = get_char() == 'y';

	double bonus = 0;
	if (all_star) bonus += 25000;
	if (reg_mvp) bonus += 75000;
	if (ws_mvp) bonus += 100000;
	if (gold_glove) bonus += 50000;
	if (silver_slugger) bonus += 35000;
	if (hr_champ) bonus += 25000;
	if (ba_champ) bonus += 25000;

	printf("the player's bonus is: %.2lf\n", bonus);
}

char get_char() {
	char c = '\0';
	scanf("%c", &c);
	return c;
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("\nTask 3:\n");

	FILE* infile = fopen("data.dat", "r");

	double v1 = fget_double(infile);
	double v2 = fget_double(infile);
	double v3 = fget_double(infile);
	double v4 = fget_double(infile);
	double v5 = fget_double(infile);
	fclose(infile);

	double avg = (v1 + v2 + v3 + v4 + v5) / 5.0;

	double max = v1;
	if (v2 > max) max = v2;
	if (v3 > max) max = v3;
	if (v4 > max) max = v4;
	if (v5 > max) max = v5;

	double min = v1;
	if (v2 < min) min = v2;
	if (v3 < min) min = v3;
	if (v4 < min) min = v4;
	if (v5 < min) min = v5;

	int choice = 0;
	printf("which would you like to display?\n");
	printf("1. average\n");
	printf("2. max\n");
	printf("3. min\n");
	printf(": ");
	
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("%lf\n", avg);
			break;
		case 2:
			printf("%lf\n", max);
			break;
		case 3:
			printf("%lf\n", min);
			break;
		default:
			printf("error: invalid\n");
	}
}

double fget_double(FILE* infile) {

	double x = 0;
	fscanf(infile, "%lf", &x);
	return x;
}

#pragma endregion
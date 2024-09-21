#include "functions.h"

int main() {


	FILE* infile = fopen("task1.txt", "r");

	int sex = 0;
	double age = 0.0;
	double weight = 0.0;
	double height = 0.0;
	int activity = 0;

	fscanf(infile, "%d", &sex); // 0 for male, 1 for female
	fscanf(infile, "%lf", &age);
	fscanf(infile, "%lf", &weight);
	fscanf(infile, "%lf", &height);
	fscanf(infile, "%d", &activity);


	double bmr = calc_bmr(sex, weight, height, age);
	double calories = calc_cals(activity, bmr);

	printf("your bmr is: %lf\n", bmr);
	printf("your calories is: %lf\n", calories);


	return 0;
}
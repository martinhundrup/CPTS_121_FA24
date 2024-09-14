/*
 * File: lab3.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 3
 * Created: September 11, 2024
 * Last Updated: September 11, 2024
 */

#include "lab3.h"

#pragma region Task 1

void task_1() {

	printf("\n\nTask 1:\n");

	double _weight = get_weight();
	double _height = get_height();
	double _bmi = calculate_bmi(_weight, _height);

	display_bmi(_bmi);

	// a way to condense this:
	// display_bmi(calculate_bmi(get_weight(), get_height()));	
}

double get_weight() {

	double _weight = 0.0;
	printf("enter your weight in lbs: "); 
	scanf("%lf", &_weight);

	return _weight;
}

double get_height() {

	double _height = 0.0;
	printf("enter your height in feet: "); 
	scanf("%lf", &_height);

	return _height;
}

double convert_feet_to_inches(double height_in_feet) {

	return height_in_feet * 12;
}

double calculate_bmi(double weight_in_pounds, double height_in_feet) {

	return (weight_in_pounds / pow(convert_feet_to_inches(height_in_feet), 2)) * 703;
}

void display_bmi(double bmi) {

	printf("\nyour BMI: %.2lf\n", bmi);

	if (bmi <= 18.0) {
		printf("you are underweight.\n");
	}
	else if ( bmi < 25)
		printf("you are a healthy weight.\n");
	else
		printf("you are overweight.\n");
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("\n\nTask 2:\n");

	double theta = get_theta();
	double distance = get_distance();
	double velocity = get_velocity();
	double time = calc_time(distance, velocity, theta);
	double height = calc_height(velocity, theta, time);

	printf("the projectile's air-time was: %lf\n", time);
	printf("the projectile's height when it hit the target was: %lf\n", height);
}

double get_theta() {

	double theta = 0.0;
	printf("enter the launch angle of the projectile in radians: ");
	scanf("%lf", &theta);

	return theta;
}

double get_distance() {

	double distance = 0.0;
	printf("enter the distance from the target in feet: ");
	scanf("%lf", &distance);

	return distance;
}

double get_velocity() {

	double velocity = 0.0;
	printf("enter the velocity of the projectile in ft/sec: ");
	scanf("%lf", &velocity);

	return velocity;
}

double calc_time(double distance, double velocity, double theta) {

	return distance / (velocity * cos(theta));
}

double calc_height(double velocity, double theta, double time) {

	return velocity * sin(theta) * time - ((G * pow(time, 2)) / 2);
}

#pragma endregion

#pragma region Task 3

void task_3() {

	printf("\n\nTask 2:\n");

	printf("enter the first exam grade: ");
	double exam1 = get_score();
	printf("enter the second exam grade: ");
	double exam2 = get_score();

	printf("enter the first lab grade: ");
	double lab1 = get_score();
	printf("enter the second lab grade: ");
	double lab2 = get_score();

	printf("enter the first project grade: ");
	double project1 = get_score();
	printf("enter the second project grade: ");
	double project2 = get_score();

	double exam_avg = get_average(exam1, exam2);
	double lab_avg = get_average(lab1, lab2);
	double project_avg = get_average(project1, project2);

	printf("the final grade is: %.2lf%%\n", weigh_averages(exam_avg, lab_avg, project_avg));
}

double get_score() {

	double x = 0.0;
	scanf("%lf", &x);

	return x;
}

double get_average(double score1, double score2) {

	return (score1 + score2) / 2;
}

double weigh_averages(double exams, double labs, double projects) {

	return (exams * .6) + (labs * .1) + (projects * .3);
}

#pragma endregion
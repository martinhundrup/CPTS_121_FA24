/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Created: August 26, 2024
 * Last Updated: August 26, 2024
 *
 * Description: This file contains the implementation of lab 2
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {

	printf("Lab 2 example solution.\n\n");

#pragma region Task 1

	printf("Task 1:\n");

	double _x1 = 0.0, _x2 = 0.0, _y1 = 0.0, _y2 = 0.0;

	// Prompt the user for the coordinates of the two points
	printf("enter the x coord of the first point: "); scanf("%lf", &_x1);
	printf("enter the y coord of the first point: "); scanf("%lf", &_y1);
	printf("enter the x coord of the second point: "); scanf("%lf", &_x2);
	printf("enter the y coord of the second point: "); scanf("%lf", &_y2);

	// Compute the slope of the line between those two points
	double _slope = (_y2 - _y1) / (_x2 - _x1);

	// Compute the coordinates of the midpoint of the line segment between the two points
	double _xMid = _x1 + (_x2 - _x1) / 2;
	double _yMid = _y1 + (_y2 - _y1) / 2;

	// Compute the slope of the perpendicular bisector
	double _neg_reciprical = -1 / _slope;

	// Compute the y intercept of the perpendicular bisector
	double _yInt = _yMid - (_neg_reciprical * _xMid);

	// Output the labels of the original two points
	printf("\npoint 1 (x, y): (%.3lf, %.3lf)\n", _x1, _y1);
	printf("point 2 (x, y): (%.3lf, %.3lf)\n", _x2, _y2);

	// Output in y = mx + b format the equation of the perpendicular bisector.
	printf("perpendicular bisector:\n");
	printf("y = %.3lfx + %lf\n", _neg_reciprical, _yInt);

#pragma endregion

#pragma region Task 2

	printf("\n\nTask 2:\n");

	double _weight = 0.0, _height = 0.0, _bmi = 0.0;

	printf("enter your weight in lbs: "); scanf("%lf", &_weight);
	printf("enter your height in feet: "); scanf("%lf", &_height);

	_bmi = (_weight / pow(_height * 12, 2)) * 703;

	printf("\nyour BMI: %.2lf\n", _bmi);

	// optional (you should do this)

	if (_bmi < 18.0)
		printf("you are underweight.\n");
	else if (_bmi < 25)
		printf("you are a healthy weight.\n");
	else
		printf("you are overweight.\n");

#pragma endregion

	return 0;
}
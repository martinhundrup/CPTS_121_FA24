/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Created: August 24, 2024
 * Last Updated: September 11, 2024
 *
 * Description: This file contains the entry point for programming assignment 2 for CPT_S 121
 *				at Washington State University
 */

#include "equations.h"

int main(void) {

	printf("PA 2 example solution.\n\n");

#pragma region Newtons Second Law

	double _mass = 0.0, _acc = 0.0;

	printf("Newton's second Law of Motion:\n");
	printf("force = mass * acceleration\n");
	printf("enter the mass: "); scanf("%lf", &_mass);
	printf("enter the acceleration: "); scanf("%lf", &_acc);
	printf("force = %.2lf\n\n", calculate_newtons_2nd_law(_mass, _acc));

#pragma endregion

#pragma region Volume of Cylinder

	double _radius = 0.0, _height = 0.0;

	printf("Volume of a cylinder:\n");
	printf("volume = PI * radius^2 * height\n");
	printf("enter the radius: "); scanf("%lf", &_radius);
	printf("enter the height: "); scanf("%lf", &_height);
	printf("volume = %.2lf\n\n", calculate_volume_cylinder(_radius, _height)); // alternatively PI * _raduis * _radius * _height

#pragma endregion

#pragma region Character Encoding

	char _plaintext = '\0';
	int _offset = 0;

	printf("Character encoding:\n");
	printf("encoded_character = offset + (plaintext_character - 'a') + 'A'\n");
	printf("enter the offset: "); scanf("%d", &_offset);
	getchar(); // clears the previous newline char
	printf("enter the plaintext character: "); scanf("%c", &_plaintext);
	printf("encoded_character = %c\n\n", perform_character_encoding(_plaintext, _offset));

	// if the plaintext char is lowercase, it is encoded as upercase

#pragma endregion

#pragma region Gravity

	double _mass1 = 0.0, _mass2 = 0.0, _dist = 0.0;

	printf("Gravity:\n");
	printf("force = G * mass1 * mass2 / distance^2\n");
	printf("enter the first mass: "); scanf("%lf", &_mass1);
	printf("enter the second mass: "); scanf("%lf", &_mass2);
	printf("enter the distance: "); scanf("%lf", &_dist);
	printf("force = %.2lf\n\n", calculate_gravity(_mass1, _mass2, _dist));

#pragma endregion

#pragma region Fahrenheit to Celcius

	double _fahrenheit = 0.0;

	printf("Fahrenheit to Celcius:\n");
	printf("celsius = (fahrenheit - 32) / (9 / 5)\n");
	printf("enter the fahrenheit: "); scanf("%lf", &_fahrenheit);
	printf("celsius = %.2lf\n\n", convert_fahrenheit_to_celsius(_fahrenheit));

#pragma endregion

#pragma region Distance

	double _x1 = 0.0, _x2 = 0.0, _y1 = 0.0, _y2 = 0.0;

	printf("Distance between two points:\n");
	printf("distance = square root((x1 - x2)^2 + (y1 - y2)^2)\n");
	printf("enter x1: "); scanf("%lf", &_x1);
	printf("enter x2: "); scanf("%lf", &_x2);
	printf("enter y1: "); scanf("%lf", &_y1);
	printf("enter y2: "); scanf("%lf", &_y2);
	printf("distance = %.2lf\n\n", calculate_distance(_x1, _x2, _y1, _y2));

#pragma endregion

#pragma region General Equation

	double _x = 0.0, _z = 0.0;
	int _a = 0;

	printf("General equation:\n");
	printf("y = (89 / 27)  - z * x + a / (a % 2)\n");
	printf("enter x: "); scanf("%lf", &_x);
	printf("enter z: "); scanf("%lf", &_z);
	printf("enter a: "); scanf("%d", &_a);
	printf("y = %.2lf\n\n", calculate_general_equation(_x, _z, _a));

#pragma endregion

	return 0;
}
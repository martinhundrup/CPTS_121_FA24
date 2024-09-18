/*
 * File: equations.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Created: August 25, 2024
 * Last Updated: September 11, 2024
 *
 * Description: This file contains the function definitions for
 *				programming assignment 2 for CPT_S 121 at Washington State University
 */

#include "equations.h"

double calculate_newtons_2nd_law(double mass, double acceleration) {

	return mass * acceleration;
}

double calculate_volume_cylinder(double radius, double height) {

	return PI * pow(radius, 2) * height;
}

char perform_character_encoding(char plaintext_character, int offset) {

	return offset + (plaintext_character - 'a') + 'A';
}

double calculate_gravity(double mass1, double mass2, double distance) {

	return G * mass1 * mass2 / pow(distance, 2);
}

double convert_fahrenheit_to_celsius(double fahrenheit) {

	return (fahrenheit - 32) / ((double)9 / 5);
}

double calculate_distance(double x1, double x2, double y1, double y2) {

	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double calculate_general_equation(double x, double z, int a) {

	return ((double)89 / 27) - z * x + a / (a % 2);
}
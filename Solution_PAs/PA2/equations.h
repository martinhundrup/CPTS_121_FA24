/*
 * File: equations.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Created: August 25, 2024
 * Last Updated: September 13, 2024
 *
 * Description: This file contains the includes and function prototypes for 
 *				programming assignment 2 for CPT_S 121 at Washington State University
 */

#ifndef PA2
#define PA2

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#define G 0.0000000000667

#include <stdio.h>
#include <math.h>

/*
 *   Calculates the relative force of an object.
 *
 *   @param the mass of the object
 *   @param the acceleration of the object
 *
 *   @return the force of the object
 */
double calculate_newtons_2nd_law(double mass, double acceleration);

/*
 *   Calculates the volume of a cylinder.
 *
 *   @param the radius of the cylinder
 *   @param the height of the cylinder
 *
 *   @return the force of the object
 */
double calculate_volume_cylinder(double radius, double height);

/*
 *   Encodes a character.
 *
 *   @param the character to encode
 *   @param the offset of the encoding
 *
 *   @return the encoded character
 */
char perform_character_encoding(char plaintext_character, int offset);

/*
 *   Calculates the force of gravity between two objects.
 *
 *   @param the mass of the first object
 *   @param the mass of the second object
 *	 @param the distance between the two objects
 *
 *   @return the gravitational force between the two objects
 */
double calculate_gravity(double mass1, double mass2, double distance);

/*
 *   Calculates resistive divider.
 *
 *   @param the temperature in fahrenheit
 *
 *   @return the temperature in celsius
 */
double convert_fahrenheit_to_celsius(double fahrenheit);

/*
 *   Calculates distance between two points.
 *
 *   @param the x coord of the first point
 *   @param the x coord of the second point
 *   @param the y coord of the first point
 *   @param the y coord of the second point
 *
 *   @return the distance between the two points
 */
double calculate_distance(double x1, double x2, double y1, double y2);

/*
 *   Calculates a general equation.
 *
 *   @param the x value
 *   @param the z value
 *   @param the a value. CANNOT BE AN EVEN NUMBER
 *
 *   @return the result
 */
double calculate_general_equation(double x, double z, int a);

#endif
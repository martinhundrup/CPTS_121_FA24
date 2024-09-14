/*
 * File: lab3.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 3
 * Created: September 11, 2024
 * Last Updated: September 11, 2024
 */

#ifndef LAB3_H
#define LAB3_H

#define _CRT_SECURE_NO_WARNINGS
#define G 32.17

#include <stdio.h>
#include <math.h>

#pragma region Task 1

/*
*	Performs task 1.
*/
void task_1();

/*
*	Prompts the user for weight in pounds.
* 
*	@return the weight
*/
double get_weight();

/*
*	Prompts the user for height in feet
* 
*	@return the height
*/
double get_height();

/*
*	Converts the height of the user from feet to inches.
* 
*	@param the height in feet
* 
*	@return the height in inches
*/
double convert_feet_to_inches(double height_in_feet);

/*
*	Evaluates the BMI based on weight and height.
*	
*	@param the weight in pounds
*	@param the height in feet
* 
*	@return the BMI value
*/
double calculate_bmi(double weight_in_pounds, double height_in_feet);

/*
*	Displays the resultant BMI value to the tenths place.
* 
*	@param the BMI to display
*/
void display_bmi(double bmi);

#pragma endregion

#pragma region Task 2

/*
*	Performs task 2.
*/
void task_2();

/*
*	Prompts the user for the angle of elevation.
* 
*	@return the angle of elevation in radians
*/
double get_theta();

/*
*	Prompts the user for the distance to the target.
*
*	@return the distance to the target in feet
*/
double get_distance();

/*
*	Prompts the user for the velocity of the projectile.
*
*	@return the velocity of the projectile in ft/sec
*/
double get_velocity();

/*
*	Calculates the duration of a projectile's flight.
* 
*	@param the distance in feet from the target
*	@param the velocity of the projectile in ft/sec
*	@param the angle of elevation in radians
* 
*	@return the air-time of the projectile
*/
double calc_time(double distance, double velocity, double theta);

/*
*	Calculates the height of a projectile when it reaches its target.
*
*   @param the velocity of the projectile in ft/sec
*	@param the angle of elevation in radians
*	@param the time the projectile was in the air
*
*	@return the height of the projectile in feet
*/
double calc_height(double velocity, double theta, double time);

#pragma endregion

#pragma region Task 3

/*
*	Performs task 3.
*/
void task_3();

/*
*	Gets a floating point number from the user.
*	
*	@return the score
*/
double get_score();

/*
*	Finds the mean of two floating point numbers.
*	
*	@param the value of the first data entry.
*	@param the value of the second data entry.
*	
*	@return the averages of the two entries.
*/
double get_average(double score1, double score2);

/*
*	Weighs the averages of exams, labs, and projects
* 
*	@param the average exam grade
*	@param the average lab grade
*	@param the average project grade
* 
*	@return the final grade of the student
*/
double weigh_averages(double exams, double labs, double projects);

#pragma endregion

#endif
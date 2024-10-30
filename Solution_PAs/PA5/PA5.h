/*
 * File: PA5.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA5 - Yahtzee
 * Created: October 18, 2024
 * Last Updated: October 21, 2024
 */

#ifndef PA5
#define PA5

#define _CRT_SECURE_NO_WARNINGS

#define NUM_DIE 5 // alter for shenanigans

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>	// isdigit()
#include <string.h>	// strtok()

/*
	Entry point of the application.
*/
void start_application();

/*
	Plays a single game of yahtzee.
*/
void play_yahtzee();

/*
	Forces the user to select a part of their scorecard to update.

	@param the player's scorecard
	@param the die array to check
*/
void choose_scorecard(int* scorecard, int* die);

/*
	Handles rerolling the die

	@param the die array to roll
*/
void reroll_die(int* die);

/*
	Prints the game rules of Yahtzee to the screen.
*/
void print_game_rules();

/*
	Simualates rolling an array of 5 dice

	@param the integer array representing the die
*/
void roll_dice(int* dice);

/*
	Gets an integer from the user.

	@return the value entered in stdin
*/
int get_int();

/*
	Gets an character from the user.

	@return the value entered in stdin
*/
char get_char();

/*
	Displays a scorecard to the screen

	@param an int array of length 13 containing the point value for each category. 
	A value of -1 means it has not yet been used.

	@param the player number being displayed
*/
void display_scorecard(int* scorecard, int player);

/*
	Sets all values in a scorecard to -1.

	@param the scorecard to set
*/
void init_scorecard(int* scorecard);

#pragma region Animated Die

/*
	Clears terminal lines.

	@param the number of lines to clear
*/
void clear_lines(int n);

/*
	Prints the dice values to the screen.

	@param the die array to display
*/
void print_die(int* die);

/*
	Clears the terminal of the previous dice roll.
*/
void clear_dice_roll();

/*
	Flashes random dice rolls on the screen to mimic rolling dice.
*/
void animate_roll();

#pragma endregion

#pragma region Checking Scores

/*
	Calculates the sum of certain side of die.

	@param the die array to check
	@param the value to check the frequency of

	@return the total points
*/
int sum_of_n(int* die, int n);

/*
	Determines if a play got a full house or not.

	@param the die array to check

	@return the sum of all die, 0 otherwise
*/
int three_of_a_kind(int* die);

/*
	Determines if a play got a full house or not.

	@param the die array to check

	@return the sum of all die if found, 0 otherwise
*/
int four_of_a_kind(int* die);

/*
	Determines if a play got a full house or not.

	@param the die array to check

	@return 25 if found, 0 otherwise
*/
int full_house(int* die);

/*
	Determines if a play got a small straight or not.

	@param the die array to check

	@return 30 if found, 0 otherwise
*/
int small_straight(int* die);

/*
	Determines if a play got a large straight or not.

	@param the die array to check

	@return 40 if found, 0 otherwise
*/
int large_straight(int* die);

/*
	Determines if a player scored a yahtzee of not.

	@param the die array to check

	@return 50 if yahtzee found, 0 otherwise
*/
int yahtzee(int* die);

/*
	Determines the sum of all faces on all die.

	@param the die array to check

	@return the sum of the die
*/
int chance(int* die);

#pragma endregion

#endif
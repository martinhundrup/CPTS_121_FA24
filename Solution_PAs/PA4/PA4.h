/*
 * File: PA4.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA4 - Craps
 * Created: October 8, 2024
 * Last Updated: October 9, 2024
 */

#ifndef PA4
#define PA4

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma region Required Functions

/*
	Prints out the rules of the game of "craps".
*/
void print_game_rules();

/*
	Prompts the player for an initial bank balance from which wagering will be added or subtracted.

	@param the balance entered by the user. must be positive
*/
double get_bank_balance();

/*
	Prompts the player for a wager on a particular roll.

	@return the wager amount entered by the user. must be positive
*/
double get_wager_amount();

/*
	Determines if the wager is whithin the limits of the player's bank balance.

	@param the wager the player selected
	@param the player's current balance

	@return 0 if invalid wager amount, 1 if it is accepted
*/
int check_wager_amount(double wager, double balance);

/*
	Rolls a die.

	@return a number between [1, 6] inclusive
*/
int roll_die();

/*
	Sums together the values of the two dice.

	@param the value of the first die
	@param the value of the second die.

	@return the sum
*/
int calculate_sum_die(int die1_value, int die2_value);

/*
	Determines the result of the first dice roll.

	@param the sum of the dice

	@return 1 if the player won, 0 if the player loses, and -1 if neither
*/
int is_win_loss_or_point(int sum_dice);

/*
	Determines the result of any successive roll after the first roll.

	@param the sum of the dice
	@param the point value target

	@return 1 if the player won, 0 if the player loses, and -1 if neither
*/
int is_point_loss_or_neither(int sum_dice, int point_value);

/*
	Adjusts the player's bank balance.

	@param the current bank balance of the player
	@param the player's current wager
	@param 0 for subtracting the wager, 1 for adding the wager, something else for no change

	@return the resulting bank balance for the player
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/*
	Displays an appropriate message to the player depending on the state of the game.

	@param the number of rolls taken so far
	@param whether the player has won or not
	@param the starting bank balance
	@param the current bank balance
*/
void chatter_messages(int number_rolls, int win_loss_neither, double
	initial_bank_balance, double current_bank_balance);

#pragma endregion

#pragma region Extra Functions

/*
	Prints the dice values to the screen.

	@param the value of the first die
	@param the value of the second die.
*/
void print_die(int die1_value, int die2_value);

/*
	Clears the terminal of the previous dice roll.
*/
void clear_dice_roll();

/*
	Flashes random dice rolls on the screen to mimic rolling dice.
*/
void animate_roll();

/*
	Main entry-point for playing craps
*/
void start_program();

/*
	Plays a single game of craps
*/
void play_game();

/*
	Handles the logic for all the rolls after the first.

	@param a pointer to the player's bank balance
	@param the player's point target
*/
void secondary_rolls(double* balance, int point);

/*
	Gets an integer from the user.

	@return the value entered in stdin
*/
int get_int();

/*
	Gets an character from the user.

	@return the value entered in stdin
*/
int get_char();

#pragma endregion

#endif
/*
 * File: Lab10.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 10
 * Created: October 30, 2024
 * Last Updated: November 1, 2024
 */

 // guard code
#ifndef LAB10_H
#define LAB910_H

#define _CRT_SECURE_NO_WARNINGS

#define MAX 100 // for task 1
#define SIZE 3	// for tic tac toe

#include "Utility.h"

typedef struct coordinate
{
	int row;
	int column;

} Coordinate;

typedef struct cell
{
	int occupied; // 1 if an X or O is in this cell; 0 otherwise
	char symbol; // X for player 1, O for player 2
	Coordinate location; // represents the position of the cell within the game board

} Cell;

typedef struct game_info
{
	int wins;
	int losses;
	int total_games_played;

} Game_info;

#pragma region Task 1

/*
	Performs task 1.
*/
void task_1();

/*
	Generates a random sentence.

	@param the buffer to store the sentence into
	@param the array of articles
	@param the array of nouns
	@param the array of verbs
	@param the array of prepositions

	@return the generated sentence
*/
char* generate_sentence(char* sentence, char* articles[MAX], char* nouns[MAX], char* verbs[MAX], char* prepositions[MAX]);

#pragma endregion

#pragma region Task 2

/*
	Performs task 2.
*/
void task_2();

/*
	Initializes a Tic Tac Toe game board.

	@param the board to initialize
*/
void initialize_board(struct cell board[SIZE][SIZE]);

/*
	Prompts the user for a coordinate on the board.

	@return the entered coordinates
*/
struct coordinate get_coordinates();

/*
	Checks if a player has won yet.

	@param the board to check

	@return -1 if draw, 0 if game ongoing, 1 if player 1 won, 2 if player 2 won
*/
int check_for_winner(struct cell board[SIZE][SIZE]);

/*
	Prints a Tic Tac Toe board to the screen.

	@param the board to display
*/
void print_board(struct cell board[SIZE][SIZE]);

#pragma endregion

#endif

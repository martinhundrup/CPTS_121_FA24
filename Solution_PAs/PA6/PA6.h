/*
 * File: PA6.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA6 - Battleship
 * Created: October 28, 2024
 * Last Updated: November 5, 2024
 */

#ifndef PA6
#define PA6

#define _CRT_SECURE_NO_WARNINGS

#define HIT '*' // the symbol to display for a hit ship
#define MISS 'm' // the symbol to display for a missed shot
#define WATER '~' // the symbol to display for water
#define SIZE 10 // the amount of columns and rows in the game board
#define CPU_DIFFICULTY 0.250 // the chance for the CPU to get a hit

#include "Utility.h"

enum direction {NORTH, SOUTH, WEST, EAST}; // Represents the direction the ship will face

#pragma region Structs

// Contains all the data related to a ship.
typedef struct ship {

	char symbol; // the symbol to display on the game board to represent this ship
	int size; // the amount of spaces this ship takes up
	const char name[100]; // the name of the ship
}Ship;

// Represents a single cell on the game board.
typedef struct cell {

	struct ship* ship; // pointer to the information about the ship present in this cell. NULL for empty
	int hit; // -1 for miss, 0 for not hit, 1 for hit
}Cell;

// Contains all the statistics for a single player.
typedef struct stats {

	int num_hits;
	int num_misses;
	int total_shots;
	double hit_ratio; // number of hits / total shots
	int won; // 1 for they won, 0 for they lost
}Stats;

// Contains coordinates
typedef struct coordinate {

	int column; // col index (x)
	int row; // row index (y)
}Coordinate;

#pragma endregion

/*
	Entry point for the application.
*/
void start_application();

/*
	Plays a single game of battleship.
*/
void play_battleship();

/*
	Prints the game rules of Battleship to the screen.
*/
void print_game_rules();

/*
	Writes the contents of a stats struct to a file

	@param the filestream to output to
	@param the stat struct to output
*/
void output_stats(FILE* outfile, struct stats* player);

#pragma region Boards

/*
	Prints a friendly gameboard to the screen.

	@param the board to display
*/
void print_self_board(struct cell board[SIZE][SIZE]);

/*
	Prints a opposing gameboard to the screen.

	@param the board to display
*/
void print_opposing_board(struct cell board[SIZE][SIZE]);

/*
	Checks the board position to see if a given ship can fit in a coordinate. Called by place_ship()

	@param the ship to place on the board
	@param the board to place the ship on
	@param the direction to place the ship
	@param the coordinate of the front of the ship

	@return boolean value indicating success; 0 for failiure
*/
int check_ship_position(const struct ship* ship, const struct cell board[SIZE][SIZE], const enum direction direction, const struct coordinate coord);

/*
	Places a ship on the board. Ensures the position is valid before placing.

	@param the ship to place on the board
	@param the board to place the ship on
	@param the direction to place the ship
	@param the coordinate of the front of the ship

	@return boolean value indicating success; 0 for failiure
*/
int place_ship(const struct ship* ship, struct cell board[SIZE][SIZE], const enum direction direction, const struct coordinate coord);

/*
	Randomly places a ship on a board.

	@param the ship to place on the board
	@param the board to place the ship on

	@return boolean value indicating success; 0 for failiure
*/
int place_ship_random(const struct ship* ship, struct cell board[SIZE][SIZE]);

/*
	Prompts the user for location and position of a ship, and places it on the board.

	@param the ship to place on the board
	@param the board to place the ship on

	@return boolean value indicating success; 0 for failiure
*/
int place_ship_manual(const struct ship* ship, struct cell board[SIZE][SIZE]);

/*
	Checks if a ship has been sunk.

	@param the ship to check for
	@param the board to check

	@return 1 if ship was sunk, 0 if it is still afloat.
*/
int is_ship_sunk(const struct ship* ship, const struct cell board[SIZE][SIZE]);

#pragma endregion

#pragma region Utility

/*
	Generates a random direction enum.
*/
enum direction get_random_direction();

/*
	Prompts the user for a coordinate on the board.

	@return the entered coordinates
*/
struct coordinate get_coordinates();

/*
	Prompts the user for a direction

	@param the buffer to store a string representation of the direction into

	@return the entered direction
*/
enum direction get_direction(char* buffer);

/*
	Gets a random coordinate value between [0, SIZE] on both axis.

	@return a new coordinate struct
*/
struct coordinate get_random_coordinates();

#pragma endregion

#pragma region CPU Logic

/*
	Gets the coordinates of the CPU's next shot.

	@param the board the CPU will fire on
	@param the chance for the CPU to hit a ship. -1 for random shot.

	@return the coordinate of the CPU's shot
*/
struct coordinate cpu_get_shot(struct cell board[SIZE][SIZE], double chance);

#pragma endregion

#endif
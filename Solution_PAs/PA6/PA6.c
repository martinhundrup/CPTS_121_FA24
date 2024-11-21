/*
 * File: PA6.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA6 - Battleship
 * Created: October 28, 2024
 * Last Updated: November 5, 2024
 */

#include "PA6.h"

void start_application() {

	// main loop
	while (1) { // use while 'true' for simplicity

		printf("welcome to battleship! please enter one of the following options below:\n");
		printf("\t1. display rules\n");
		printf("\t2. start game\n");
		printf("\t3. exit program\n");

		printf("> ");
		int option = get_int();

		// exit condition
		if (option == 3) return;
		else if (option == 1) {

			system("cls");
			print_game_rules();
			system("pause");
		}
		else if (option == 2) play_battleship();


		system("cls");
	}
}

void play_battleship() {

	system("cls");

#pragma region Set up

	// open log file
	FILE* outfile = fopen("battleship.log", "w");

	// create gameboards
	struct cell board1[SIZE][SIZE] = { { NULL, 0 } }; // or just { 0 }
	struct cell board2[SIZE][SIZE] = { { NULL, 0 } };

	// create stats
	struct stats player1 = { 0 };
	struct stats player2 = { 0 };

	// create ships
	const struct ship carrier = { 'c', 5, "Carrier" };
	const struct ship battleship = { 'b', 4, "Battleship" };
	const struct ship cruiser = { 'r', 3, "Cruiser" };
	const struct ship submarine = { 's', 3, "Submarine" };
	const struct ship destroyer = { 'd', 2, "Destroyer" };

	// set up player's board
	print_self_board(board1);

	while (1) { // loop until valid input

		printf("would you like to place your ships manually (M) or randomly (R)?\n\n");
		printf("> ");

		char input = '\0';
		int success = scanf("%c", &input);
		clear_buffer();

		if (success != 1) { // failed for whatever reason

			printf(RED "error: unknown. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
			continue;
		}
		else if (toupper(input) == 'M') { // place all ships manually

			place_ship_manual(&carrier, board1);
			place_ship_manual(&battleship, board1);
			place_ship_manual(&cruiser, board1);
			place_ship_manual(&submarine, board1);
			place_ship_manual(&destroyer, board1);
			break;
		}
		else if (toupper(input) == 'R') { // place all ships randomly

			place_ship_random(&carrier, board1);
			place_ship_random(&battleship, board1);
			place_ship_random(&cruiser, board1);
			place_ship_random(&submarine, board1);
			place_ship_random(&destroyer, board1);
			break;
		}
		else { // invalid input

			printf(RED "error: invalid input. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
			continue;
		}
	}

	// player board has been sat up

	// set up CPU board
	place_ship_random(&carrier, board2);
	place_ship_random(&battleship, board2);
	place_ship_random(&cruiser, board2);
	place_ship_random(&submarine, board2);
	place_ship_random(&destroyer, board2);

	system("cls");
	print_self_board(board1);
	system("pause");

#pragma endregion

	// set up has finished, we can now begin the game

#pragma region Turns

	// determine which player goes first
	int player = random_range(1, 2);
	int winner = 0; // 1 if player 1 won, 2 if CPU won
	int player1_ship_count = 5;
	int player2_ship_count = 5;

	while (!winner) { // game loop

		system("cls");
		if (player == 1) {
			printf("player 1's turn:\n");
			fprintf(outfile, "player 1's turn:\n");
		}
		else {
			printf("player 2's turn:\n");
			fprintf(outfile, "player 2's turn:\n");
		}

		if (player == 1) { // get user input for firing a shot

			player1.total_shots++;
			struct coordinate coords;

			print_opposing_board(board2);

			// get shot
			while (1) { // loop until not previosuly targeted coord is chosen

				printf("Enter the coordinate you would like to target:\n");
				coords = get_coordinates();

				if (board2[coords.row][coords.column].hit != 0) { // previously targeted
					printf(RED "error: coordinates have already been used. try again.\n" WHT);
					system("pause");
					clear_lines(2);
					continue;
				}
				else { 
					break;
				}
			}

			system("cls");

			// set the cell to hit
			if (board2[coords.row][coords.column].ship == NULL) { // no ship present

				board2[coords.row][coords.column].hit = -1; // miss
				print_opposing_board(board2);
				printf("shot at %d %d - " GRN "miss!\n" WHT, coords.row, coords.column);
				fprintf(outfile, "shot at %d %d - miss!\n", coords.row, coords.column);
				player1.num_misses++;
			}
			else { // ship present

				struct ship* ship = board2[coords.row][coords.column].ship; // save ref to ship
				board2[coords.row][coords.column].hit = 1; // hit
				print_opposing_board(board2);
				printf("shot at %d %d - " RED "hit!\n" WHT, coords.row, coords.column);
				fprintf(outfile, "shot at %d %d - hit!\n", coords.row, coords.column);
				player1.num_hits++;

				// TODO: check for sunk battleship		
				if (is_ship_sunk(ship, board2)) {
					printf(RED "you sunk their %s!\n" WHT, ship->name);
					fprintf(outfile, "PLAYER 1 sunk PLAYER 2's %s!\n", ship->name);
					player2_ship_count--;					
				}
			}
		}
		else { // perform CPU shot

			// get random target and ensure it hasn't been used before:
			struct coordinate coords = cpu_get_shot(board1, CPU_DIFFICULTY);

			// set the cell to hit
			if (board1[coords.row][coords.column].ship == NULL) { // no ship present

				board1[coords.row][coords.column].hit = -1; // miss
				print_self_board(board1);
				printf("shot at %d %d - " GRN "miss!\n" WHT, coords.row, coords.column);
				fprintf(outfile, "shot at %d %d - miss!\n", coords.row, coords.column);
				player2.num_misses++;
			}
			else { // ship present

				struct ship* ship = board1[coords.row][coords.column].ship; // save ref to ship
				board1[coords.row][coords.column].hit = 1; // hit
				print_self_board(board1);
				printf("shot at %d %d - " RED "hit!\n" WHT, coords.row, coords.column);
				fprintf(outfile, "shot at %d %d - hit!\n", coords.row, coords.column);
				player2.num_hits++;

				// TODO: check for sunk battleship		
				if (is_ship_sunk(ship, board1)) {
					printf(RED "they sunk your %s!\n" WHT, ship->name);
					fprintf(outfile, "PLAYER 2 sunk PLAYER 1's %s!\n", ship->name);
					player1_ship_count--;
				}
			}

			player2.total_shots++;
		}

		system("pause");

		// swap players
		if (player == 1) player = 2;
		else player = 1;

		// winner?
		if (player1_ship_count <= 0)
			winner = 2;
		else if (player2_ship_count <= 0)
			winner = 1;
	}

#pragma endregion

	// end of game

	if (winner == 1) {
		player1.won = 1;
		printf(GRN "congratulations, you won!\n" WHT);
	}
	else {
		player2.won = 1;
		printf(RED "sorry, you lost!\n" WHT);
	}

	player1.hit_ratio = (double)player1.num_hits / player1.total_shots;
	player2.hit_ratio = (double)player2.num_hits / player2.total_shots;

	// output stats
	fprintf(outfile, "\nPLAYER 1:\n");
	output_stats(outfile, &player1);
	fprintf(outfile, "\nPLAYER 2:\n");
	output_stats(outfile, &player2);

	// close file
	fclose(outfile);

	system("pause");
}

void print_game_rules() {

	printf("Welcome to Battleship!\n\n");
	printf("Game Rules:\n");
	printf("1. The game is played on two grids, one for each player.\n");
	printf("   - Each grid has coordinates labeled 0-9.\n");
	printf("   - One grid is for placing your ships, and the other is for tracking your hits and misses.\n\n");
	printf("2. Each player has a fleet of ships:\n");
	printf("   - Carrier (5 cells)\n");
	printf("   - Battleship (4 cells)\n");
	printf("   - Cruiser (3 cells)\n");
	printf("   - Submarine (3 cells)\n");
	printf("   - Destroyer (2 cells)\n\n");
	printf("3. Players take turns guessing the location of each other's ships by calling out grid coordinates.\n");
	printf("   - If a ship occupies the coordinate, it is a 'hit'.\n");
	printf("   - Otherwise, it's a 'miss'.\n");
	printf("   - The opponent must announce if it is a hit or a miss.\n\n");
	printf("4. When all cells of a ship are hit, it is considered 'sunk'.\n");
	printf("   - The opponent must announce which ship was sunk.\n\n");
	printf("5. The game ends when one player has sunk all of the opponent's ships.\n");
	printf("6. The first player to sink all of their opponent's ships wins the game!\n\n");
	printf("Good luck, and may the best strategist win!\n");
}

void output_stats(FILE* outfile, struct stats* player) {

	fprintf(outfile, "***** STATS *****\n");
	fprintf(outfile, "NUM HITS: %d\n", player->num_hits);
	fprintf(outfile, "NUM MISSES: %d\n", player->num_misses);
	fprintf(outfile, "NUM SHOTS: %d\n", player->total_shots);
	fprintf(outfile, "HIT RATIO: %.2lf\n", player->hit_ratio);
	if (player->won)
		fprintf(outfile, "PLAYER WON\n");
	else
		fprintf(outfile, "PLAYER LOST\n");
	fprintf(outfile, "*** END STATS ***\n");
}

#pragma region Boards

void print_self_board(struct cell board[SIZE][SIZE]) {

	printf(GRN "YOUR BOARD:\n\n" WHT);

	printf("  ");

	// print header
	for (int i = 0; i < SIZE; i++)
		printf("%d ", i);

	putchar('\n');
	for (int i = 0; i < SIZE; i++) {

		printf("%d ", i); // left side label

		for (int j = 0; j < SIZE; j++) {

			if (board[i][j].hit == 0 && board[i][j].ship != NULL) // ship
				printf("%c ", board[i][j].ship->symbol);
			else if (board[i][j].hit == 1) // hit
				printf(RED "%c " WHT, HIT);
			else if (board[i][j].hit == -1)  // miss
				printf(GRN "%c " WHT, MISS);
			else if (board[i][j].hit == 0 && board[i][j].ship == NULL) // not targeted yet, no ship
				printf(CYN "%c " WHT, WATER);				
		}
		putchar('\n'); // print a newline
	}
}

void print_opposing_board(struct cell board[SIZE][SIZE]) {

	printf(RED "OPPOSING BOARD:\n\n" WHT);
	printf("  ");

	// print header
	for (int i = 0; i < SIZE; i++)
		printf("%d ", i);

	putchar('\n');
	for (int i = 0; i < SIZE; i++) {

		printf("%d ", i); // left side label

		for (int j = 0; j < SIZE; j++) {

			if (board[i][j].hit == 0) // not targeted yet
				printf(CYN "%c " WHT, WATER);
			else if (board[i][j].hit == 1) // hit
				printf(RED "%c " WHT, HIT);
			else  // miss
				printf(GRN "%c " WHT, MISS);
		}
		putchar('\n'); // print a newline
	}
}

int check_ship_position(const struct ship* ship, const struct cell board[SIZE][SIZE], const enum direction direction, const struct coordinate coord) {

	int x = coord.column;
	int y = coord.row;

	if (direction == EAST || direction == WEST) { // checking horizontal

		// check to see if it has enough room
		if (direction == EAST) { // placing EAST

			if (x + ship->size - 1 >= SIZE)
				return 0; // not enough room

			// now check to ensure it won't overlap with another ship
			for (int i = 0; i < ship->size; i++) {
				if (board[y][x + i].ship != NULL)
					return 0; // found another ship
			}
		}
		else { // placing WEST

			if (x - ship->size + 1 < 0)
				return 0; // not enough room

			// now check to ensure it won't overlap with another ship
			for (int i = 0; i < ship->size; i++) {
				if (board[y][x - i].ship != NULL)
					return 0; // found another ship
			}
		}
	}
	else { // checking vertical

		// check to see if it has enough room
		if (direction == SOUTH) { // placing SOUTH

			if (y + ship->size - 1 >= SIZE)
				return 0; // not enough room

			// now check to ensure it won't overlap with another ship
			for (int i = 0; i < ship->size; i++) {
				if (board[y + i][x].ship != NULL)
					return 0; // found another ship
			}
		}
		else { // placing NORTH

			if (y - ship->size + 1 < 0)
				return 0; // not enough room

			// now check to ensure it won't overlap with another ship
			for (int i = 0; i < ship->size; i++) {
				if (board[y - i][x].ship != NULL)
					return 0; // found another ship
			}
		}
	}

	return 1; // it can be placed
}

int place_ship(const struct ship* ship, struct cell board[SIZE][SIZE], const enum direction direction, const struct coordinate coord) {

	int x = coord.column;
	int y = coord.row;

	// I am going to loop through the array first, just reading the values to ensure it is a valid spot
	// I am just reading instead of writing and checking as I write, because it it is invalid, I will have to
	// undo everything I set, and I can't be bothered

	if (check_ship_position(ship, board, direction, coord)) {
		if (direction == EAST) {

			for (int i = 0; i < ship->size; i++) {
				board[y][x + i].ship = ship; // place ship
			}
		}
		else if (direction == WEST) {

			for (int i = 0; i < ship->size; i++) {
				board[y][x - i].ship = ship; // place ship
			}
		}
		else if (direction == NORTH) {

			for (int i = 0; i < ship->size; i++) {
				board[y - i][x].ship = ship; // place ship
			}
		}
		else { // placing SOUTH

			for (int i = 0; i < ship->size; i++) {
				board[y + i][x].ship = ship; // place ship
			}
		}

		return 1; // success!
	}

	return 0; // failiure
}

int place_ship_random(const struct ship* ship, struct cell board[SIZE][SIZE]) {
	
	int success = 0;
	while (!success) { // loop until we find a valid position on the board

		int x = rand() % 10; // random value [0, 9]
		int y = rand() % 10;
		enum direction dir = get_random_direction();
		struct coordinate coord = { x, y };
		success = place_ship(ship, board, dir, coord);
	}

	return success;
}

int place_ship_manual(const struct ship* ship, struct cell board[SIZE][SIZE]) {

	system("cls");
	print_self_board(board);

	int row = 0;
	int col = 0;
	enum direction dir = 0;

	printf("enter the starting point for your %s, size: %d\n", ship->name, ship->size);
	struct coordinate coord = get_coordinates();
	row = coord.row;
	col = coord.column;

	printf("ROW: %d\tCOL: %d\n", row, col);
	char str[100] = { 0 };

	printf("enter the direction point for your %s, size: %d\n", ship->name, ship->size);
	dir = get_direction(str);

	printf("DIR: %s\n", str);

	// check if valid
	if (!place_ship(ship, board, dir, coord)) { // failed, restart ship placement

		printf(RED "error: bad ship placement. please try again.\n" WHT);
		system("pause");
		clear_lines(5);
		return place_ship_manual(ship, board); // rather than looping i'll use recursion
	}
	
	system("cls");
	return 1; // success
}

int is_ship_sunk(const struct ship* ship, const struct cell board[SIZE][SIZE]) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j].ship == ship && !board[i][j].hit)
				return 0; // still afloat
		}
	}

	return 1; // sunk
}

#pragma endregion

#pragma region Utility

enum direction get_random_direction() {

	return (enum direction)rand() % 4; // enums are just named integerss
}

struct coordinate get_coordinates() {

	int row = 0, col = 0;

	while (1) { // loop to get coordinates
		
		printf("format your entry as ROW COL: ex '3 8'\n");
		printf("\n> ");

		int success = scanf("%d %d", &row, &col);
		clear_buffer();

		if (success != 2) { // some form of error
			printf(RED "error: unknown. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
			continue;
		}
		else if (row < 0 || row > SIZE || col < 0 || col > SIZE) {
			printf(RED "error: coordinate out of bounds. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
			continue;
		}
		else {
			break; // valid coords
		}
	}

	struct coordinate coords = { col, row };
	clear_lines(4);
	return coords;
}

enum direction get_direction(char* buffer) {

	enum direction dir = 0;

	while (1) { // loop to get direction

		printf("N for NORTH, S for SOUTH, E for EAST, W for WEST.\n");
		printf("\n> ");

		char c = '\0';
		int success = scanf("%c", &c);
		clear_buffer();

		if (success != 1) { // some form of error
			printf(RED "error: unknown. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
		}
		else if (toupper(c) == 'N') {

			strcpy(buffer, "NORTH");
			dir = NORTH;
			break;
		}
		else if (toupper(c) == 'S') {

			strcpy(buffer, "SOUTH");
			dir = SOUTH;
			break;
		}
		else if (toupper(c) == 'E') {

			strcpy(buffer, "EAST");
			dir = EAST;
			break;
		}
		else if (toupper(c) == 'W') {

			strcpy(buffer, "WEST	");
			dir = WEST;
			break;
		}
		else {
			printf(RED "error: invalid direction. please try again.\n" WHT);
			system("pause");
			clear_lines(5);
		}
	}

	clear_lines(4);
	return dir;
}

struct coordinate get_random_coordinates() {

	int col = random_range(0, 9);
	int row = random_range(0, 9);
	struct coordinate coord = { col, row };
	return coord;
}

#pragma endregion

#pragma region CPU Logic

struct coordinate cpu_get_shot(struct cell board[SIZE][SIZE], double chance) {

	struct coordinate coords = { 0 }; // start with 0 0

	if (random_range(0, 100) / 100.0 < chance) { // garantee hit

		// get random target and ensure it hasn't been used before and has a ship
		do {
			coords = get_random_coordinates();
		} while (board[coords.row][coords.column].hit != 0 || board[coords.row][coords.column].ship == NULL);

		return coords;
	}
	else {

		// get random target and ensure it hasn't been used before:
		do {
			coords = get_random_coordinates();
		} while (board[coords.row][coords.column].hit != 0);

		return coords;
	}
}
#pragma endregion

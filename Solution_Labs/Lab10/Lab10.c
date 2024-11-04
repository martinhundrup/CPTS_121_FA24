/*
 * File: Lab10.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 10
 * Created: October 30, 2024
 * Last Updated: November 1, 2024
 */

#include "Lab10.h"

#pragma region Task 1

void task_1() {

	char* articles[MAX] = { "the ", "a ", "one ", "some ", "any " };
	char* nouns[MAX] = { "boy ", "girl ", "dog ", "town ", "car " };
	char* verbs[MAX] = { "drove ", "jumped ", "ran ", "walked ", "skipped " };
	char* prepositions[MAX] = { "to ", "from ", "over ", "under ", "on " };

	char sentence[MAX] = { '\0' };

	for (int i = 0; i < 20; i++) {
		generate_sentence(sentence, articles, nouns, verbs, prepositions);
		printf("%s\n", sentence);
	}
}

char* generate_sentence(char* sentence, char* articles[MAX], char* nouns[MAX], char* verbs[MAX], char* prepositions[MAX]) {

	// put random article at the beggining
	strcpy(sentence, articles[rand() % 5]);

	// append random noun
	strcat(sentence, nouns[rand() % 5]);

	// append random verb
	strcat(sentence, verbs[rand() % 5]);

	// append random preposition
	strcat(sentence, prepositions[rand() % 5]);

	// append random article
	strcat(sentence, articles[rand() % 5]);

	// append random noun
	strcat(sentence, nouns[rand() % 5]);

	return sentence;
}

#pragma endregion

#pragma region Task 2

void task_2() {

#pragma region Set Up

	// create and init gameboard
	struct cell board[SIZE][SIZE] = { { 0 } }; // or just { 0 }

	// create infos
	struct game_info player1_info = { 0 };
	struct game_info player2_info = { 0 };
	int player = 0;

	// give the user some info
	printf("player 1 is denoted by the symbol 'X'\n");
	printf("player 2 is denoted by the symbol 'O'\n");
	system("pause");
	
	while (1) { // play multiple games

		system("cls");
		initialize_board(board); // reset board each game

		if (rand() % 2 == 0) {
			player = 1;
			printf("player 1 will start\n");
		}
		else {
			player = 2;
			printf("player 2 will start\n");
		}

		system("pause");

#pragma endregion

#pragma region Game Loop

		int winner = 0; // 0 for game not over, 1 for player 1 won, 2 for player 2 won, and -1 for draw

		while (!winner) { // repeat while no one has one

			system("cls");
			print_board(board);

			if (player == 1)
				printf("player 1's turn:\n");
			else
				printf("player 2's turn:\n");

			struct coordinate coords = { 0 };

			// get cell
			while (1) { // loop until not previosuly targeted coord is chosen

				printf("Enter the coordinate you would like to target:\n");
				coords = get_coordinates();

				if (board[coords.row][coords.column].occupied != 0) { // previously targeted
					printf(RED "error: coordinates have already been used. try again.\n" WHT);
					system("pause");
					clear_lines(2);
					continue;
				}
				else {
					break;
				}
			}

			board[coords.row][coords.column].occupied = 1;
			if (player == 1)
				board[coords.row][coords.column].symbol = 'X';
			else
				board[coords.row][coords.column].symbol = 'O';

			winner = check_for_winner(board);

			// swap players
			if (player == 1) player = 2;
			else player = 1;
		}

#pragma endregion

		system("cls");
		print_board(board);

		// game over, which was it?
		if (winner == 1) { // player 1 won

			printf("player 1 won!\n");
			player1_info.wins++;
			player2_info.losses++;
		}
		else if (winner == 2) { // player 2 won

			printf("player 2 won!\n");
			player2_info.wins++;
			player1_info.losses++;
		}
		else { // tie game

			printf("tie game!\n");
		}

		player1_info.total_games_played++;
		player2_info.total_games_played++;

		// ask to play again
		printf("\nplay again? (Y/N)\n> ");
		char ans = getchar();
		clear_buffer();

		if (toupper(ans) != 'Y')
			break;
	}

	system("cls");
	printf("PLAYER 1 STATS:\n");
	printf("WINS: %d\n", player1_info.wins);
	printf("LOSSES: %d\n", player1_info.losses);
	printf("TOTAL GAMES: %d\n\n", player1_info.total_games_played);

	printf("PLAYER 2 STATS:\n");
	printf("WINS: %d\n", player2_info.wins);
	printf("LOSSES: %d\n", player2_info.losses);
	printf("TOTAL GAMES: %d\n\n", player2_info.total_games_played);
}

void initialize_board(struct cell board[SIZE][SIZE]) {

	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {

			board[row][col].occupied = 0;
			board[row][col].symbol = '-';
			struct coordinate coord = { row, col };
			board[row][col].location = coord;
		}
	}
}

struct coordinate get_coordinates() {

	int row = 0, col = 0;

	while (1) { // loop to get coordinates

		printf("format your entry as ROW COL: ex '1 2'\n");
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

	struct coordinate coords = { row, col };
	clear_lines(4);
	return coords;
}

int check_for_winner(struct cell board[SIZE][SIZE]) {

	int x_counter = 0;
	int o_counter = 0;

	// check rows
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {

			if (board[row][col].symbol == 'X') // player 1
				x_counter++;
			else if (board[row][col].symbol == 'O') // player 2
				o_counter++;
		}

		// we have now checked an entire row, lets consult the counter
		if (x_counter >= SIZE)
			return 1; // player 1 won
		else if (o_counter >= SIZE) // player 2 won
			return 2;

		// reset counters to check next row
		x_counter = o_counter = 0;
	}

	x_counter = o_counter = 0;
	// check columns
	for (int col = 0; col < SIZE; col++) {
		for (int row = 0; row < SIZE; row++) {

			if (board[row][col].symbol == 'X') // player 1
				x_counter++;
			else if (board[row][col].symbol == 'O') // player 2
				o_counter++;
		}

		// we have now checked an entire row, lets consult the counter
		if (x_counter >= SIZE)
			return 1; // player 1 won
		else if (o_counter >= SIZE) // player 2 won
			return 2;

		// reset counters to check next column
		x_counter = o_counter = 0;
	}

	x_counter = o_counter = 0;
	// check diagonal (top left to bottom right
	for (int i = 0; i < SIZE; i++) {

		if (board[i][i].symbol == 'X') // player 1
			x_counter++;
		else if (board[i][i].symbol == 'O') // player 2
			o_counter++;
	}

	// we have now checked an entire diagonal, lets consult the counter
	if (x_counter >= SIZE)
		return 1; // player 1 won
	else if (o_counter >= SIZE) // player 2 won
		return 2;

	x_counter = o_counter = 0;
	// check diagonal (top left to bottom right
	for (int i = SIZE - 1; i >= 0; i--) {

		if (board[i][i].symbol == 'X') // player 1
			x_counter++;
		else if (board[i][i].symbol == 'O') // player 2
			o_counter++;
	}

	// we have now checked an entire diagonal, lets consult the counter
	if (x_counter >= SIZE)
		return 1; // player 1 won
	else if (o_counter >= SIZE) // player 2 won
		return 2;

	// check to see if it is a tie game (all cells are occupied)
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (!board[i][j].occupied)
				return 0; // still empty cells
		}
	}

	return -1; // all cells ocupied, tie game
}

void print_board(struct cell board[SIZE][SIZE]) {

	printf("  ");

	// print header
	for (int i = 0; i < SIZE; i++)
		printf("%d ", i);

	putchar('\n');
	for (int i = 0; i < SIZE; i++) {

		printf("%d ", i); // left side label

		for (int j = 0; j < SIZE; j++) {

			printf("%c ", board[i][j].symbol);
		}
		putchar('\n'); // print a newline
	}
}

#pragma endregion
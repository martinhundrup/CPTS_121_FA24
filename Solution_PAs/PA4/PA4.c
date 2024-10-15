/*
 * File: PA4.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA4 - Craps
 * Created: October 8, 2024
 * Last Updated: October 14, 2024
 */

#include "PA4.h"

#pragma region Required Functions

void print_game_rules() {

	printf("the game rules of craps:\n");
	printf("\tA player rolls two dice.Each die has six faces.These faces contain 1, 2, 3, 4, 5, and 6\n");
	printf("\tspots.After the dice have come to rest, the sum of the spots on the two upward\n");
	printf("\tfaces is calculated.If the sum is 7 or 11 on the first throw, the player wins.If the\n");
	printf("\tsum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses(i.e.the \"house\"\n");
	printf("\twins).If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the\n");
	printf("\tplayer's \"point.\" To win, you must continue rolling the dice until you \"make your\n");
	printf("\tpoint.\" The player loses by rolling a 7 before making the point.\n");
}

double get_bank_balance() {

	double balance = 0.0;

	while (balance <= 0.0) { // ensures positive number

		printf("please enter your starting bank balance: ");
		scanf("%lf", &balance);

		if (balance <= 0.0) {

			printf("please enter a value larger than 0\n");
		}
	}

	return balance;
}

double get_wager_amount() {

	double wager = 0.0;

	while (wager <= 0.0) { // ensures positive number

		printf("please enter your wager: ");
		scanf("%lf", &wager);

		if (wager <= 0.0) {

			printf("please enter a value larger than 0\n");
		}
	}

	return wager;
}

int check_wager_amount(double wager, double balance) {

	return wager <= balance;
}

int roll_die() {

	// rand() % n returns [0, n-1], so we add 1 to get [1, n]
	return (rand() % 6) + 1;
}

int calculate_sum_die(int die1_value, int die2_value) {

	return die1_value + die2_value;
}

int is_win_loss_or_point(int sum_dice) {

	if (sum_dice == 7 || sum_dice == 11) return 1; // player won
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) return 0; // player lost
	return -1; // neither
}

int is_point_loss_or_neither(int sum_dice, int point_value) {

	if (sum_dice == point_value) return 1; // player won
	if (sum_dice == 7) return 0; // player lost
	return -1; // neither
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {

	if (add_or_subtract == 0) return bank_balance - wager_amount;
	if (add_or_subtract == 1) return bank_balance + wager_amount;
	return bank_balance;
}

void chatter_messages(int number_rolls, int win_loss_neither, double
	initial_bank_balance, double current_bank_balance) {

}

#pragma endregion

#pragma region Extra Functions

void print_die(int die1_value, int die2_value) {

	/*
		 _________
		|  o   o  | 
		|  o   o  |
		|  o   o  |
		|_________|

		 _________
		|  o   o  | 
		|    o    |
		|  o   o  |
		|_________|

		 _________
		|  o   o  |
		|         |
		|  o   o  |
		|_________|

		 _________
		|  o      |
		|    o    |
		|      o  |
		|_________|

		 _________
		|  o      |
		|         |
		|      o  |
		|_________|

		 _________
		|         |
		|    o    |
		|         |
		|_________|
		
	*/

	// the tops of the die
	printf("\t _________ ");
	printf("\t _________\n");

	// the first row of first die
	if (die1_value >= 4) printf("\t|  o   o  |");
	else if (die1_value > 1) printf("\t|  o      |");
	else printf("\t|         |");

	// the first row of second die
	if (die2_value >= 4) printf("\t|  o   o  |\n");
	else if (die2_value > 1) printf("\t|  o      |\n");
	else printf("\t|         |\n");

	// the second row of first die
	if (die1_value % 2 == 1) printf("\t|    o    |"); // for odd numbers
	else if (die1_value == 6) printf("\t|  o   o  |"); // unique to 6
	else printf("\t|         |"); // 2 and 4

	// the second row of second die
	if (die2_value % 2 == 1) printf("\t|    o    |\n"); // for odd numbers
	else if (die2_value == 6) printf("\t|  o   o  |\n"); // unique to 6
	else printf("\t|         |\n"); // 2 and 4

	// the third row of first die
	if (die1_value >= 4) printf("\t|  o   o  |");
	else if (die1_value > 1) printf("\t|      o  |");
	else printf("\t|         |");

	// the third row of second die
	if (die2_value >= 4) printf("\t|  o   o  |\n");
	else if (die2_value > 1) printf("\t|      o  |\n");
	else printf("\t|         |\n");

	// the last two rows
	printf("\t|_________|");
	printf("\t|_________|\n");
}

void clear_dice_roll() {

	printf("\033[5A");

	for (int i = 0; i < 5; i++) {
		printf("\r\033[K");
		printf("\n");
	}
	printf("\033[5A");
}

void animate_roll() {

	for (int i = 0; i < 6; i++) {

		print_die(roll_die(), roll_die());
		Sleep(100);
		clear_dice_roll();
	}
}

void start_program() {

	// 3 main loops:
	//	the main program loop, which displays the 3 options to the player
	//	the game loop, once they have started a game this repeats until they leave or lose
	//	the round loop, which repeats until they won or lost a round

	// main loop
	while (1) { // use while 'true' for simplicity

		printf("welcome to craps! please enter one of the following options below:\n");
		printf("\t1. start game\n");
		printf("\t2. display rules\n");
		printf("\t3. exit program\n");

		printf("> ");
		int option = get_int();

		// exit condition
		if (option == 3) return;
		else if (option == 2) {

			print_game_rules();
			system("pause");
		}
		else if (option == 1) play_game();

		
		system("cls");
	}
}

void play_game() {

	// start of game, ask for starting balance
	double balance = get_bank_balance();
	double init_balance = balance; // keep track of init balance for chatter

	while (balance > 0) { // keep playing while they have money - round loop

		system("cls");

		// for each round, start with an initial roll
		printf("player balance: %.2lf\n\n", balance);
		printf("first roll!\n");
		int wager = get_wager_amount();

		while (!check_wager_amount(wager, balance)) { // invalid, repeat until valid

			printf("please ensure your wager does not exceed your balance!\n");
			wager = get_wager_amount();
		}

		// we now have a valid wager for the first roll
		printf("rolling the die!\n");
		animate_roll();

		int die1 = roll_die();
		int die2 = roll_die();
		int sum = calculate_sum_die(die1, die2);

		print_die(die1, die2);

		printf("your sum: %d\n", sum);

		int win = is_win_loss_or_point(sum);

		if (win == 1) { // player won

			printf("congratulations! you won!\n");
			printf("your wager has been added to your balance\n");
			balance = adjust_bank_balance(balance, wager, win);
		}
		else if (win == 0) { // player loss
			
			printf("sorry, you lose!\n");
			printf("your wager has been subtracted from your balance\n");
			balance = adjust_bank_balance(balance, wager, win);
		}
		else { // move onto secondary rolls

			// keep rolling until the point or 7
			printf("your point target has been set to %d\n", sum);
			system("pause");
			secondary_rolls(&balance, sum);
		}

		// exit condition if they want to stop before game over
		printf("would you like to keep playing? (y/n)\n> ");
		char response = get_char();

		if (response == 'n') return;
	}
}

void secondary_rolls(double* balance, int point) {

	while (1) { // while true for simplicity

		system("cls");

		// for each round, start with an initial roll
		printf("player balance: %.2lf\n\n", *balance);
		printf("your point target: %d\n", point);
		int wager = get_wager_amount();

		while (!check_wager_amount(wager, *balance)) { // invalid, repeat until valid

			printf("please ensure your wager does not exceed your balance!\n");
			wager = get_wager_amount();
		}

		// we now have a valid wager for the first roll
		printf("rolling the die!\n");
		animate_roll();

		int die1 = roll_die();
		int die2 = roll_die();
		int sum = calculate_sum_die(die1, die2);

		print_die(die1, die2);

		printf("your sum: %d\n", sum);

		int win = is_point_loss_or_neither(sum, point);

		if (win == 1) { // player won

			printf("congratulations! you won!\n");
			printf("your wager has been added to your balance\n");
			*balance = adjust_bank_balance(*balance, wager, win);
			return; // exit
		}
		else if (win == 0) { // player loss

			printf("sorry, you lose!\n");
			printf("your wager has been subtracted from your balance\n");
			*balance = adjust_bank_balance(*balance, wager, win);
			return; // exit
		}
		else printf("keep on rolling!\n");		

		system("pause");
	}
}

int get_int() {

	int input = 0;
	scanf("%d", &input);
	getchar(); // clear the newline char
	return input;
}

int get_char() {

	char input = 0;
	while (getchar() != '\n'); // clear any preceeding newlines
	scanf("%c", &input);
	getchar(); // clear the newline char
	return input;
}

#pragma endregion
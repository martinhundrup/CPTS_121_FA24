/*
 * File: PA5.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: PA5 - Yahtzee
 * Created: October 18, 2024
 * Last Updated: October 21, 2024
 */

#include "PA5.h"

void start_application() {



	// main loop
	while (1) { // use while 'true' for simplicity

		printf("welcome to yahtzee! please enter one of the following options below:\n");
		printf("\t1. display rules\n");
		printf("\t2. start game\n");
		printf("\t3. exit program\n");

		printf("> ");
		int option = get_int();

		// exit condition
		if (option == 3) return;
		else if (option == 1) {

			print_game_rules();
			system("pause");
		}
		else if (option == 2) play_yahtzee();

		system("cls");
	}
}

void play_yahtzee() {

	// variable initializations
	int die[5] = { 0 };
	int scorecard_1[13] = { 0 };
	int scorecard_2[13] = { 0 };
	init_scorecard(scorecard_1);
	init_scorecard(scorecard_2);
	int player_idx = 1; // which player's turn is it?
	int turn_count = 0;

	while (turn_count < 26) { // 13 rolls for each player

		system("cls");

		if (player_idx == 1) display_scorecard(scorecard_1, 1);
		else display_scorecard(scorecard_2, 2);
		system("pause");
		clear_lines(1);

		// intial die roll
		animate_roll(die);
		roll_dice(die);
		print_die(die);

		reroll_die(die);
		
		// ask user which they would like to use the roll for?
		if (player_idx == 1) choose_scorecard(scorecard_1, die);
		else choose_scorecard(scorecard_2, die);

		// reprint with updated score
		system("cls");
		if (player_idx == 1) display_scorecard(scorecard_1, 1);
		else display_scorecard(scorecard_2, 2);
		print_die(die);
		system("pause");
		clear_lines(1);

		// increment turn and flip players
		turn_count++;
		if (player_idx == 1) player_idx = 2;
		else player_idx = 1;
	}

	// end of game - add 35 to each score if the top half is >= 63
	int sum_1 = 0;
	int sum_2 = 0;
	
	for (int i = 0; i < 13; i++) {
		sum_1 += scorecard_1[i];
		if (i == 5 && sum_1 >= 63) sum_1 += 35;
	}

	for (int i = 0; i < 13; i++) {
		sum_2 += scorecard_2[i];
		if (i == 5 && sum_2 >= 63) sum_2 += 35;
	}

	if (sum_1 > sum_2) printf("player 1 wins!\n");
	else if (sum_2 > sum_1) printf("player 2 wins!\n");
	else printf("tie game!\n");
	system("cls");
}

void choose_scorecard(int* scorecard, int* die) {

	int input = 0;
	printf("which section would you like to use these die for?\n");

	while (1) { // loop until valid

		printf("> ");
		input = get_int();

		if (input < 1 || input > 13) { // out of bounds
			printf("please choose a number 1-13.\n");
		}
		else if (scorecard[input - 1] != -1) { // already used
			printf("you have already used that.\n");
		}
		else { // valid
			break;
		}
	}

	input--; // avoid off by one error
	if (input < 6) { // sum of n
		scorecard[input] = sum_of_n(die, input + 1);
	}
	else if (input == 6) { // three of a kind
		scorecard[input] = three_of_a_kind(die);
	}
	else if (input == 7) { // four of a kind
		scorecard[input] = four_of_a_kind(die);
	}
	else if (input == 8) { // full house
		scorecard[input] = full_house(die);
	}
	else if (input == 9) { // small straight
		scorecard[input] = small_straight(die);
	}
	else if (input == 10) { // large straight
		scorecard[input] = large_straight(die);
	}
	else if (input == 11) { // yahtzee
		scorecard[input] = yahtzee(die);
	}
	else { // chance
		scorecard[input] = chance(die);
	}
}

void reroll_die(int* die) {

	int count = 2;
	// ask if they want to re roll die
	while (count-- > 0) {
		printf("would you like to reroll any die? (y/n)\n");
		printf("> ");
		char input = get_char();

		if (input == 'y') { // yes
			clear_lines(2);
			// re roll only certain 
			printf("enter the dice you want to reroll separated by a space\n> ");
			char die_str[40] = { '\0' };
			fgets(die_str, 39, stdin);

			// parse input
			char* first_die = strtok(die_str, " ");
			while (first_die != NULL) {
				int digit_val = first_die[0] - '0';
				if (isdigit(first_die[0]) && digit_val < 6 && digit_val > 0) {
					die[digit_val - 1] = rand() % 6 + 1; // reroll
				}
				first_die = strtok(NULL, " ");
			}

			clear_lines(2);
			clear_dice_roll();

			int temp[NUM_DIE] = { 0 };
			animate_roll(temp);
			print_die(die);
		}
		else {
			clear_lines(2);
			return;
		}
	}
}

void print_game_rules() {

	printf("these are the rules of yahtzee:\n");
}

void roll_dice(int* dice) {

	for (int i = 0; i < NUM_DIE; i++) {

		dice[i] = rand() % 6 + 1;
	}
}

int get_int() {

	int input = 0;
	scanf("%d", &input);
	getchar(); // clear the newline char
	return input;
}

char get_char() {

	char input = 0;
	scanf("%c", &input);
	getchar(); // clear the newline char
	return input;
}

void display_scorecard(int* scorecard, int player) {

	/*
		====================================
			  ** YAHTZEE SCORECARD **        
			       ** PLAYER 1 **
		====================================
		| CATEGORY          |    SCORE     |
		------------------------------------
		| UPPER SECTION     |              |
		------------------------------------
		| Aces (Ones)       |   _________  |
		| Twos              |   _________  |
		| Threes            |   _________  |
		| Fours             |   _________  |
		| Fives             |   _________  |
		| Sixes             |   _________  |
		------------------------------------
		| LOWER SECTION     |              |
		------------------------------------
		| 3 of a Kind       |   _________  |
		| 4 of a Kind       |   _________  |
		| Full House        |   _________  |
		| Small Straight    |   _________  |
		| Large Straight    |   _________  |
		| Yahtzee           |   _________  |
		| Chance            |   _________  |
		------------------------------------
		| TOTAL SCORE       |   _________  |
		====================================
	*/

	printf("\t====================================\n");
	printf("\t|     ** YAHTZEE SCORECARD **      |\n");
	printf("\t|          ** PLAYER %d **          |\n", player);
	printf("\t====================================\n");
	printf("\t| CATEGORY          |    SCORE     |\n");
	printf("\t------------------------------------\n");
	printf("\t|          UPPER SECTION           |\n");
	printf("\t------------------------------------\n");
	if (scorecard[0] < 0) // print empty
		printf("\t|1. Aces            |   _________  |\n");
	else if (scorecard[0] < 10) // 1 digit
		printf("\t|1. Aces            |   ____%d____  |\n", scorecard[0]);
	else // two digits
		printf("\t|1. Aces          |   ___%d____  |\n", scorecard[0]);

	if (scorecard[1] < 0)
		printf("\t|2. Twos            |   _________  |\n");
	else if (scorecard[1] < 10)
		printf("\t|2. Twos            |   ____%d____  |\n", scorecard[1]);
	else
		printf("\t|2. Twos            |   ___%d____  |\n", scorecard[1]);

	if (scorecard[2] < 0)
		printf("\t|3. Threes          |   _________  |\n");
	else if (scorecard[2] < 10)
		printf("\t|3. Threes          |   ____%d____  |\n", scorecard[2]);
	else
		printf("\t|3. Threes          |   ___%d____  |\n", scorecard[2]);

	if (scorecard[3] < 0)
		printf("\t|4. Fours           |   _________  |\n");
	else if (scorecard[3] < 10)
		printf("\t|4. Fours           |   ____%d____  |\n", scorecard[3]);
	else
		printf("\t|4. Fours           |   ___%d____  |\n", scorecard[3]);

	if (scorecard[4] < 0)
		printf("\t|5. Fives           |   _________  |\n");
	else if (scorecard[4] < 10)
		printf("\t|5. Fives           |   ____%d____  |\n", scorecard[4]);
	else
		printf("\t|5. Fives           |   ___%d____  |\n", scorecard[4]);

	if (scorecard[5] < 0)
		printf("\t|6. Sixes           |   _________  |\n");
	else if (scorecard[5] < 10)
		printf("\t|6. Sixes           |   ____%d____  |\n", scorecard[5]);
	else
		printf("\t|6. Sixes           |   ___%d____  |\n", scorecard[5]);

	printf("\t------------------------------------\n");
	printf("\t|          LOWER SECTION           |\n");
	printf("\t------------------------------------\n");

	if (scorecard[6] < 0)
		printf("\t|7. 3 of a Kind     |   _________  |\n");
	else if (scorecard[6] < 10)
		printf("\t|7. 3 of a Kind     |   ____%d____  |\n", scorecard[6]);
	else
		printf("\t|7. 3 of a Kind     |   ___%d____  |\n", scorecard[6]);

	if (scorecard[7] < 0)
		printf("\t|8. 4 of a Kind     |   _________  |\n");
	else if (scorecard[7] < 10)
		printf("\t|8. 4 of a Kind     |   ____%d____  |\n", scorecard[7]);
	else
		printf("\t|8. 4 of a Kind     |   ___%d____  |\n", scorecard[7]);

	if (scorecard[8] < 0)
		printf("\t|9. Full House      |   _________  |\n");
	else if (scorecard[8] < 10)
		printf("\t|9. Full House      |   ____%d____  |\n", scorecard[8]);
	else
		printf("\t|9. Full House      |   ___%d____  |\n", scorecard[8]);

	if (scorecard[9] < 0)
		printf("\t|10. Small Straight |   _________  |\n");
	else if (scorecard[9] < 10)
		printf("\t|10. Small Straight |   ____%d____  |\n", scorecard[9]);
	else
		printf("\t|10. Small Straight |   ___%d____  |\n", scorecard[9]);

	if (scorecard[10] < 0)
		printf("\t|11. Large Straight |   _________  |\n");
	else if (scorecard[10] < 10)
		printf("\t|11. Large Straight |   ____%d____  |\n", scorecard[10]);
	else
		printf("\t|11. Large Straight |   ___%d____  |\n", scorecard[10]);

	if (scorecard[11] < 0)
		printf("\t|12. Yahtzee        |   _________  |\n");
	else if (scorecard[11] < 10)
		printf("\t|12. Yahtzee        |   ____%d____  |\n", scorecard[11]);
	else
		printf("\t|12. Yahtzee        |   ___%d____  |\n", scorecard[11]);

	if (scorecard[12] < 0)
		printf("\t|13. Chance         |   _________  |\n");
	else if (scorecard[12] < 10)
		printf("\t|13. Chance         |   ____%d____  |\n", scorecard[12]);
	else
		printf("\t|13. Chance         |   ___%d____  |\n", scorecard[12]);

	// find total sum
	int sum = 0;
	for (int i = 0; i < 13; i++) {
		if (scorecard[i] >= 0)
			sum += scorecard[i];
	}

	printf("\t------------------------------------\n");
	if (sum < 10)
		printf("\t| TOTAL SCORE       |   ____%d____  |\n", sum);  // 1 digit
	else if (sum < 100)
		printf("\t| TOTAL SCORE       |   ___%d____  |\n", sum);   // 2 digits
	else
		printf("\t| TOTAL SCORE       |   __%d____  |\n", sum);    // 3 digits
	printf("\t====================================\n");
}

void init_scorecard(int* scorecard) {

	for (int i = 0; i < 13; i++) {
		scorecard[i] = -1;
	}
}

#pragma region Animated Dice

void clear_lines(int n) {	

	for (int i = 0; i < n; i++) {
		printf("\033[1A");
		printf("\r\033[K");
	}	
}

void print_die(int* die) {

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
	for (int i = 0; i < NUM_DIE; i++) {
		printf("\t _________ ");
	}
	printf("\n");

	// the first row of die
	for (int i = 0; i < NUM_DIE; i++) {
		if (die[i] >= 4) printf("\t|  o   o  |");
		else if (die[i] > 1) printf("\t|  o      |");
		else printf("\t|         |");
	}
	printf("\n");


	// the second row of die
	for (int i = 0; i < NUM_DIE; i++) {
		if (die[i] % 2 == 1) printf("\t|    o    |"); // for odd numbers
		else if (die[i] == 6) printf("\t|  o   o  |"); // unique to 6
		else printf("\t|         |"); // 2 and 4
	}
	printf("\n");

	// the third row of die
	for (int i = 0; i < NUM_DIE; i++) {
		if (die[i] >= 4) printf("\t|  o   o  |");
		else if (die[i] > 1) printf("\t|      o  |");
		else printf("\t|         |");
	}
	printf("\n");


	// the the bottoms
	for (int i = 0; i < NUM_DIE; i++) {
		printf("\t|_________|");
	}
	printf("\n");
}

void clear_dice_roll() {

	clear_lines(5);
}

void animate_roll(int* die) {

	for (int i = 0; i < 6; i++) {

		roll_dice(die);
		print_die(die);
		Sleep(100);
		clear_dice_roll();
	}
}

#pragma endregion

#pragma region Checking Scores

int sum_of_n(int* die, int n) {

	int sum = 0;
	for (int i = 0; i < NUM_DIE; i++) {
		if (die[i] == n)
			sum += n;
	}

	return sum;
}

int three_of_a_kind(int* die) {

	int histogram[7] = { 0 };
	for (int i = 0; i < NUM_DIE; i++) {
		histogram[die[i]]++;
	}

	for (int i = 0; i < 7; i++) {
		if (histogram[i] >= 3)
			return chance(die);
	}

	return 0;
}

int four_of_a_kind(int* die) {

	int histogram[7] = { 0 };
	for (int i = 0; i < NUM_DIE; i++) {
		histogram[die[i]]++;
	}

	for (int i = 0; i < 7; i++) {
		if (histogram[i] >= 4)
			return chance(die);
	}

	return 0;
}

int full_house(int* die) {

	int histogram[7] = { 0 };
	for (int i = 0; i < NUM_DIE; i++) {
		histogram[die[i]]++;
	}

	int marker1 = 0;
	int marker2 = 0;
	for (int i = 0; i < 7; i++) {
		if (histogram[i] == 3)
			marker1 = 1;
		if (histogram[i] == 2)
			marker2 = 1;
	}

	if (marker1 && marker2) return 25;

	return 0;
}

int small_straight(int* die) {

	int histogram[7] = { 0 };
	for (int i = 0; i < NUM_DIE; i++)
		histogram[die[i]]++;

	int marker = 0;
	for (int i = 1; i < 7; i++) {
		if (histogram[i] >= 1)
			marker++;
		else if (histogram[i] == 0 && marker < 4)
			marker = 0;
	}

	if (marker >= 4) return 40;

	return 0;
}

int large_straight(int* die) {

	int histogram[7] = { 0 };
	for (int i = 0; i < NUM_DIE; i++)
		histogram[die[i]]++;

	int marker = 0;
	for (int i = 1; i < 7; i++) {
		if (histogram[i] >= 1)
			marker++;
		else if (histogram[i] == 0 && marker < 5)
			marker = 0;
	}

	if (marker >= 5) return 40;

	return 0;
}

int yahtzee(int* die) {

	// work harder not smarter
	if (die[0] == die[1] && die[0] == die[2] && die[0] == die[3] && die[0] == die[4]) {
		return 50;
	}

	return 0;
}

int chance(int* die) {

	int sum = 0;
	for (int i = 0; i < NUM_DIE; i++) {
		sum += die[i];
	}

	return sum;
}

#pragma endregion
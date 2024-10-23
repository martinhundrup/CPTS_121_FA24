/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 21, 2024
 * Last Updated: October 23, 2024
 */

#include "Testing.h" // did not includ Lab9.h - why?

int main() {

	printf("lab 9 example solution:\n\n");

	test_string_reverse();
	test_my_strcpy();
	test_my_strcat();
	test_my_strcmp();
	test_my_strlen();

	// funny
	//FILE* test = fopen("main.c", "w");
	//fprintf(test, "#include <stdio.h>\n\n");
	//fprintf(test, "int main() {\n\n");
	//fprintf(test, "\tprintf(\"hello, world!\");\n");
	//fprintf(test, "\treturn 0;\n");
	//fprintf(test, "}\n");
	//fclose(test);

	// funny 2
	FILE* test = fopen("main.c", "r");
	char contents[100][100] = { "" };
	int i = 0;
	while (!feof(test)) {
		fgets(contents[i], 99, test);
		printf("%s", contents[i]);
		i++;
	}

	fclose(test);

	test = fopen("main.c", "a");
	for (int j = 0; j < i; j++) {
		fprintf(test, "%s", contents[j]);
	}
	fclose(test);

	return 0;
}
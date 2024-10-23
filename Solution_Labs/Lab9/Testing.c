/*
 * File: Testing.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 9
 * Created: October 21, 2024
 * Last Updated: October 23, 2024
 */

#include "Testing.h" // did not includ Lab9.h - why?

void test_string_reverse() {


	char str[100] = "hello, world!";
	char expected[100] = "!dlrow ,olleh";

	string_reverse(str);

	int result = strcmp(str, expected); // should be 0

	printf("***** START OF TEST STRING REVERSE *****\n\n");
	printf("EXPECTED: %s\n", expected);
	printf("ACTUAL: %s\n", str);

	if (result == 0)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	printf("***** END OF TEST STRING REVERSE *****\n\n");
}

void test_my_strcpy() {

	// strings to copy from
	char str1[100] = "hello, world!";
	char str2[100] = "hello, world!";

	// strings to write over
	char dest1[100] = "write over me!";
	char dest2[100] = "write over me!";

	// perform the two copies
	my_strcpy(dest1, str1);
	strcpy(dest2, str2);

	int result = strcmp(dest1, dest2); // should be 0

	printf("***** START OF TEST STRCPY *****\n\n");
	printf("EXPECTED: %s\n", dest2);
	printf("ACTUAL: %s\n", dest1);

	if (result == 0)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	printf("***** END OF TEST STRCPY *****\n\n");
}

void test_my_strcat() {

	// strings to copy from
	char str1[100] = "hello, world!";
	char str2[100] = "hello, world!";

	// strings to append to
	char dest1[100] = "write next to me!";
	char dest2[100] = "write next to me!";

	// perform the two copies
	my_strcat(dest1, str1);
	strcat(dest2, str2);

	int result = strcmp(dest1, dest2); // should be 0

	printf("***** START OF TEST STRCAT *****\n\n");
	printf("EXPECTED: %s\n", dest2);
	printf("ACTUAL: %s\n", dest1);
		
	if (result == 0)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	printf("***** END OF TEST STRCAT *****\n\n");
}

void test_my_strcmp() {

	// a couple scenarios
	// 1. the strings are equal
	// 2. one string is longer than the other, but otherwise equal
	// 3. the strings are not equal

	// strings to test
	char str1[100] = "hello, world!";
	char str2[100] = "hello, world! goodbye!";
	char str3[100] = "apples and oranges";
	char str4[100] = "hello, world!";

	printf("***** START OF TEST STRCMP *****\n\n");

	// case 1
	int expected = strcmp(str1, str4);
	int actual = my_strcmp(str1, str4);
	printf("EXPECTED: %d\n", expected);
	printf("ACTUAL: %d\n", actual);

	if (expected == actual)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	// case 2
	expected = strcmp(str1, str2);
	actual = my_strcmp(str1, str2);
	printf("EXPECTED: %d\n", expected);
	printf("ACTUAL: %d\n", actual);

	if (expected == actual)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	// case 3
	expected = strcmp(str1, str3);
	actual = my_strcmp(str1, str3);
	printf("EXPECTED: %d\n", expected);
	printf("ACTUAL: %d\n", actual);

	if (expected == actual)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	printf("***** END OF TEST STRCMP *****\n\n");

}

void test_my_strlen() {

	char* str = "hello, world!";
	int expected = strlen(str);
	int actual = my_strlen(str);

	printf("***** START OF TEST STRLEN *****\n\n");
	printf("EXPECTED: %d\n", expected);
	printf("ACTUAL: %d\n", actual);

	if (expected == actual)
		printf("RESULT: " GRN "PASSED\n\n" WHT);
	else
		printf("RESULT: " RED "FAILED\n\n" WHT);

	printf("***** END OF TEST STRLEN *****\n\n");
}
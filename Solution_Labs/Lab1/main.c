/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 1
 * Created: August 23, 2024
 * Last Updated: August 30, 2024
 *
 * Description: This file contains the implementation of lab 1
 */

#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
#define PI 3.141592

#include <stdio.h>	// necessary to use printf () and scanf ()
#include <math.h> // necessary for pow ()

int main() {  // the starting point for all C programs

	printf("Lab 1 example solution.\n\n");

	#pragma region TASK 1

	printf("Hello World, I am in CptS 121!\n\n");

	#pragma endregion	

	#pragma region TASK 2

	// we need to request memory for 
	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory 
										  // blocks for integers and sets them to 0's

	double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for 
													 // numbers with high precision (floating-point)
	
	printf("Enter two integer values: "); // prompt/ask the user
	scanf(" %d%d", &number1_int, &number2_int); // read the integers typed through the 
											   // keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: "); // prompt/ask the user
	scanf(" %lf%lf", &number1_float, &number2_float); // read the integers typed through 
													 // the keyboard - %lf is for "long float", i.e. 
													 // double precision numbers
													 
	// place all code for the subtasks/operations below here

	/*
	* Add number1_int and number2_int together and print the result as an 
	* integer value
	*/
	printf("number1_int + number2_int = : %d\n", number1_int + number2_int);

	/*
	* Subtract number1_float from number2_float and print the result as a 
	* floating-point value
	*/
	printf("number1_float - number2_float = : %lf\n", number1_float - number2_float);

	/*
	* Multiply number1_int by number1_float and print the result as an integer 
	* value
	*/
	printf("number1_int * number1_float = : %lf\n", number1_int * number1_float);

	/*
	* Divide number1_int by number2_int and print the result as an integer 
	* and a floating-point value (Ask yourself: What happens when you divide 
	* and integer by and integer? Does the result change because you print it 
	* as a floating-point number?)	
	*/
	printf("number1_int / number2_int as integer = : %d\n", number1_int / number2_int);
	printf("number1_int / number2_int as float = : %lf\n", (float)(number1_int / number2_int));

	/*
	* Divide number1_int by number2_float and print the result as an integer 
	* and a floating-point value (Ask yourself: How does this compare to the 
	* previous operations? We are now dealing with mixed data types.)
	*/
	printf("number1_int / number2_float as integer = : %d\n", (int)(number1_int / number2_float));
	printf("number1_int / number2_float as float = : %lf\n", number1_int / number2_float);

	/*
	* Explicitly cast number1_int as a floating-point value and divide by 
	* number2_int. Print the result as a floating-point value.
	*/
	printf("(float)number1_int / number2_int as float = : %lf\n", (float)number1_int / number2_int);

	/*
	* Try to mod number1_float by number2_float. Does the program compile? 
	* If not, fix it so that it does.
	*/
	printf("number1_float mod number2_float = : %d\n", (int)number1_float % (int)number2_float);

	/*
	* Determine if number1_int and number2_int are even or odd. Print 0 if 
	* even and 1 if odd. You may not use “if” statements. Use the mod 
	* operator instead
	*/
	printf("is number1_int even of odd: %s\n", number1_int % 2 == 0 ? "even" : "odd");
	printf("is number2_int even of odd: %s\n", number2_int % 2 == 0 ? "even" : "odd");


	/*
	* Write a program that prompts the user for inputs into Ohm’s Law and 
	* determines the voltage. Print the voltage value. Ohm's Law: V = IR, where V is 
	* the voltage, I is the current, and R is the resistance of the circuit (all values 
	* are integers).
	*/
	int _I = 0, _R = 0;
	printf("\n\nOhm's Law: V = IR\n");
	printf("enter an integer value for I: ");
	scanf(" %d", &_I);
	printf("enter an integer value for R: ");
	scanf(" %d", &_R);
	printf("V = %d\n", _I * _R);

	/*
	* Write a program that prompts the user for inputs into Joule’s Law and 
	* determines the power. Print the power value. Joule's Law: P = (V^2) / R, where 
	* P is the power, V is the voltage, and R is the resistance of the circuit (all values 
	* are integers). Do we have loss of precision? What kind of division is being 
	* performed?
	*/
	int _V = 0;
	printf("\n\nJoule's Law: P = (V^2) / R\n");
	printf("enter an integer value for V: ");
	scanf(" %d", &_V);
	printf("enter an integer value for R: ");
	scanf(" %d", &_R);
	printf("P = %lf\n", pow(_V, 2) / _R);

	/*
	* Write a program that prompts the user for inputs into the third order 
	* polynomial equation provided and determines the y value. Print the y value. 
	* The third order polynomial equation is: y = 3 * ax3 + (1/4) * bx2 + 10 * cx + (-5) * 
	* d (x, y, a, b, c, and d are integer numbers). Be careful here! What is (1 / 4) as 
	* an integer result? We do not want integer division in this case! How do we fix 
	* it? Do we ultimately have loss of precision?
	*/
	int _a = 0, _b = 0, _c = 0, _d = 0, _x = 0;
	printf("\n\nPolynomial: y = 3 * ax^3 + (1/4) * bx^2 + 10 * cx + (-5) * d\n");
	printf("enter an integer value for a: ");
	scanf(" %d", &_a);
	printf("enter an integer value for b: ");
	scanf(" %d", &_b);
	printf("enter an integer value for c: ");
	scanf(" %d", &_c);
	printf("enter an integer value for d: ");
	scanf(" %d", &_d);
	printf("enter an integer value for x: ");
	scanf(" %d", &_x);
	printf("y = %lf\n", 3 * pow(_a * _x, 3) + ((float)1 / 4) * pow(_b * _x, 2) + 10 * (_c * _x) + (-5) * _d);

	/*
	* Write a program that prompts the user for inputs into the circumference of 
	* circle equation provided and determines the circumference value. Print the 
	* circumference value. Circumference of a circle: circumference = 2 * PI * radius 
	* (circumference and radius are floating-point numbers; PI should be defined as 
	* a constant floating-point number and should not be entered by the user).
	*/
	double _r = 0;
	printf("\n\nCircumference: c = 2 * PI * radius\n");
	printf("enter an integer value for the radius: ");
	scanf(" %lf", &_r);
	printf("c = %lf\n", 2 * PI * _r);

	#pragma endregion 
	

	return 0; // return a success status (value 0) indicating the program worked fine
}
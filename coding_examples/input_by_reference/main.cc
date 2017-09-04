/**
 * Author: Judson James
 * Since: 09-03-2017
 * Version: 1.0
 * Purpose: Introduction to how to accept user input in C++,
 * 					pass by reference, and how to utilize functions outside of main.
*///----------------------------------------------------------------------------

// Include Statements
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Prototypes (or Forward Declarations)
// These are used in order to tell the C++ compiler that there are functions
// present within the file other than the main function. These are normally
// present within a "header (.h)" file in order to specify access to the 
// functions, along with the include statements and any private classes.
// For Homework 2, everything should be in the main.cc (or main.cpp) so 
// you have to explicitly state the functions as so.
void GetInput (string&, int&);
string GetReversedString (string);
string GetSortedString (string);

/**
 * Main Function
 * Asks for a users' name, favorite number, reversed name, and lexigraphically
 * sorted name by calling three separate functions.
**///---------------------------------------------------------------------------
int main (int argc, char** argv) {
	int fav_number(0);
	string name("");
	string reversed_name("");
	string sorted_name("");

	GetInput (name, fav_number);
	cout << "Your name is \"" << name << "\" and your favorite number is "
			 << fav_number << endl;

	reversed_name = GetReversedString (name);
	cout << "Your name reversed is \"" << reversed_name << "\"" << endl;
	
	sorted_name = GetSortedString (name);
	cout << "Your name sorted in lexagraphical order is \"" << sorted_name
			 << "\"" << endl;

	return 0;
}

/**
 * Function: void GetInput (string& name, int& fav_number) 
 * Purpose: Utilizes pass by reference so that we can collect data from
 * 		standard input without returning variables, instead reassigning the
 *		value at the memory address.
 * Parameters: Pointers to the local string and integer values in main
 * Returns: nothing (passed by reference, not by value)
 *
**/
void GetInput (string& name, int& fav_number) {
	cout << "Hello, please enter your name, a space, and your favorite number"
			 << endl;
	cin >> name;
	cin >> fav_number;
}

/**
 * Function: string GetReversedString (string);
 * Purpose: Reverses the provided string of characters by going through half
 * 		of the array of characters and swapping the first and last one, then each
 * 		is incremented and decremented, respectfully. Notes have been added for
 * 		warnings of memory leaks and such.
 * Parameters: name
 * Returns: reversed string
**///---------------------------------------------------------------------------
string GetReversedString (string name) {
	int name_length = name.length();
	char swap_char = ' ';

	// Keep in mind that arrays do not have bounds checking in C++,
	// you can cause memory leaks (memory that is lost from the OS) if you 
	// accidentally beyond the bounds of the array.
	for (int i = 0; i < name_length/2; ++i) {
		swap_char = name.at(i);
		name.at(i) = name.at(name_length-i-1);
		name.at(name_length-i-1) = swap_char;
	}

	return name;
}

/**
 * Function: string GetSortedString (string);
 * Purpose: Using the ASCII Values of the characters in the string, the program
 * 		will go through the string and sort them using bubble sort. This will not
 *		correctly sort mixed case strings, since upper and lower cased letters
 *		have different ASCII assignments.
 * Parameters: the name gathered from GetInput
 * Returns: the lexographically sorted string
**///---------------------------------------------------------------------------
string GetSortedString (string name) {
	bool has_swapped = true;
	char swap_char = ' ';

	while (has_swapped == true) {
		has_swapped = false; // Assuming it's finished, until proven unsorted.

		for (int i = 0; i < name.length()-1; ++i) {
			if (i != name.length()-1 && name.at(i) > name.at(i+1)) {
				swap_char = name.at(i);
				name.at(i) = name.at(i+1);
				name.at(i+1) = swap_char;
				has_swapped = true;
			}
		}
	}

	return name;
}

// end of main.cc

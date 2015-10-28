/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			10/28/2015
EXERCISE:		C++ Practice
SPECIFICATION:	Get a user name and age, then print it back to them.
-------------------------------------------------------------------------*/

#include <iostream> // used to print to screen
#include <sstream> // used to get strings

void main()
{
	int age = 0; // variable to store user's age
	std::string name = ""; // variable to store user's name

	std::cout << "Welcome to Hello World on C++" << std::endl;

	std::cout << "Please enter your first name: ";
	getline(std::cin, name);
	std::cout << "Please enter your age: ";
	std::cin >> age;

	std::cout << "Hey " << name << ", hope " << age << " is a good year!";

	getchar(); // holds command prompt open
	getchar(); // holds command prompt open
}
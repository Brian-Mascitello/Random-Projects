/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			10/28/2015
EXERCISE:		C++ Practice
SPECIFICATION:	Translate newtoncube to C++.
-------------------------------------------------------------------------*/

#include <iostream> // used to print to screen

void main()
{
	double a, b, c, d, x0;
	double epsilon = DBL_EPSILON; // Machine epsilon in C++

	std::cout << "Machine epsilon set as: " << epsilon << std::endl;

	std::cout << "f(x) = ax^3 + bx^2 + cx + d" << std::endl; // Prints what the equation looks like.

	std::cout << "Please enter the value of a: ";
	std::cin >> a;
	std::cout << "Please enter the value of b: ";
	std::cin >> b;
	std::cout << "Please enter the value of c: ";
	std::cin >> c;
	std::cout << "Please enter the value of d: ";
	std::cin >> d;
	std::cout << "Please enter your guess of the root: ";
	std::cin >> x0;

	double change = 0;
	double residual = 0;
	double x = x0;
	double xprevious = 0;
	int k = 0;

	while (k < 20 && std::abs(a*pow(x, 3) + b*pow(x, 2) + c*x + d) >
		epsilon*std::abs(a*pow(x0, 3) + pow(x0, 2) + c*x0 + d))
	{
		k++;
		xprevious = x;
		x -= (a*pow(x, 3) + b*pow(x, 2) + c*x + d) / (3 * a*pow(x, 2) + 2 * b*x + c);
		change = std::abs(x - xprevious);
		residual = a*pow(x, 3) + b*pow(x, 2) + c*x + d;
		printf("Iteration: %2d, Root: %10f, Change: %10f, Residual: %10f\n", k, x, change, residual);
	}

	std::cout << "Root at " << x;

	getchar(); // holds command prompt open
	getchar(); // holds command prompt open
}
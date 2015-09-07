#pragma once

// HEADER GUARDS
#ifndef HEADER_H
#define HEADER_H

// INCLUDES
#include <algorithm>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

// MACROS
#define deck_size 52
#define hand_size 5
#define maximum_bet 10000
#define minimum_bet 5
#define number_of_suits 4
#define one_hundred 100
#define one_thousand 1000
#define values_per_suit 13
#undef max

// CONSTANTS
bool initial = true;
const char* suit_names[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const char* suit_symbols[] = { "\x05", "\x04", "\x03", "\x06" };
int current_bet = one_hundred;
int total_credits = one_thousand;
enum suit { Clubs, Diamonds, Hearts, Spades };

// FORWARD DECLARATIONS
void clearScreen();
void flush();
void printChar(short x, short y, char c);

// HEADER FUNCTIONS
void clearScreen()
{
	short x, y;

	for (x = 80; x >= 0; x--)
	{
		for (y = 30; y >= 0; y--)
		{
			printChar(x, y, ' ');
		}
	}
}

void flushBuffer()
{
	int clear = getchar();

	while (clear != '\n' && clear != EOF)
	{
		clear = getchar();
	}

	getchar(); // Left intentionally so the user can see output before screen erased.
}

void printChar(short x, short y, char c)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%c", c);
}

#endif
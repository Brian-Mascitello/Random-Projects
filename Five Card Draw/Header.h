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
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <windows.h>

// MACROS
#define DECK_SIZE 52
#define HAND_SIZE 5
#define HIGH_SCORES "FCD_HighScores.dat"
#define MAX_DATE_LENGTH 16
#define MAX_INITIALS_LENGTH 3
#define MAX_SCORE_LENGTH 10
#define MAX_WIN_LENGTH 16
#define MAXIMUM_BET 10000
#define MINIMUM_BET 5
#define NUMBER_OF_SUITS 4
#define ONE_HUNDRED 100
#define ONE_THOUSAND 1000
#define VALUES_PER_SUIT 13
#undef max

// CONSTANTS
bool initial = true;
const char* suit_names[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const char* suit_symbols[] = { "\x05", "\x04", "\x03", "\x06" };
int current_bet = ONE_HUNDRED;
int total_credits = ONE_THOUSAND;
enum suit { Clubs, Diamonds, Hearts, Spades };

// FORWARD DECLARATIONS
void clearScreen();
void flush();
void printChar(short x, short y, char c);

// HEADER FUNCTIONS
void clearScreen()
{
	short x, y;

	for (y = 30; y >= 0; y--)
	{
		for (x = 80; x >= 0; x--)
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
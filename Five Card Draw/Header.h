#pragma once
// HEADER GUARDS
#ifndef DADCARDHEADER_H
#define DADCARDHEADER_H

// C WARNINGS
#pragma warning(disable: 4996)

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
#define one_thousand 1000
#define maximum_bet 10000
#define minimum_bet 5
#define number_of_suits 4
#define values_per_suit 13
#undef max

// CONSTANTS
bool initial = true;
const char* suit_names[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const char* suit_symbols[] = { "\x05", "\x04", "\x03", "\x06" };
int current_bet = 100;
int total_credits = one_thousand;
enum suit { Clubs, Diamonds, Hearts, Spades };

// FORWARD DECLARATIONS
void clear_screen();
void flush();
void print_char(short x, short y, char c);
void print_string(short x, short y, const char* str);

// HEADER FUNCTIONS
void clear_screen()
{
	short x, y;

	for (x = 80; x >= 0; x--)
	{
		for (y = 30; y >= 0; y--)
		{
			print_char(x, y, ' ');
		}
	}
}

void flush()
{
	int clear = getchar();

	while (clear != '\n' && clear != EOF)
	{
		clear = getchar();
	}
}

void print_char(short x, short y, char c)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%c", c);
}

void print_string(short x, short y, const char* str)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%s", str);
}

#endif
/*
Auto Neopoint Bank Calculator C++
Remake of AutoNPBank.java
Made by Brian Mascitello
Date: 11/4/2013
*/

#include <iostream>
#include <stdio.h>

char CommaAdder(int NumberFormat);

double daily, decimal_rate, rate, interest;

int balance, daily_interest, next_neopoint_day, yearly_interest;

using namespace std;

void Account();

int main()
{
	cout << "Auto Neopoint Bank Calculator C++" << endl;
	cout << "Enter your current balance: \t";
	cin >> balance;

	Account();

	decimal_rate = (rate / 100);
	interest = (balance * decimal_rate);
	daily = ceil(interest / 365);

	yearly_interest = (int)floor(interest);
	daily_interest = (int)ceil(interest / 365);
	next_neopoint_day = ceil(((daily / decimal_rate) * 365) - balance);
	
	cout << "\nCurrent Balance: \t " << balance << " NP";
	cout << "\nInterest Rate: \t \t " << rate << "% per year";
	cout << "\nYearly Interest: \t " << yearly_interest << " NP";
	cout << "\n\nDaily Interest: \t " << daily_interest << " NP";
	cout << "\nNext Neopoint/Day: \t " << next_neopoint_day << " NP\n";

	getchar();
	getchar();
}

char CommaAdder(int NumberFormat)
{

	return 'a';
}

void Account()
{
	if ( 0 <= balance && balance < 1000 )
	{
		cout << ( "\nAccount Type: \t \t Junior Saver" );
		rate = 4.5;
	}

	if ( 1000 <= balance && balance < 2500 )
	{
		cout << ( "\nAccount Type: \t \t Neopian Student" );
		rate = 5.5;
	}

	if ( 2500 <= balance && balance < 5000 )
	{
		cout << ( "\nAccount Type: \t \t Bronze Saver" );
		rate = 6.0;
	}

	if ( 5000 <= balance && balance < 10000 )
	{
		cout << ( "\nAccount Type: \t \t Silver Saver" );
		rate = 6.5;
	}

	if ( 10000 <= balance && balance < 25000 )
	{
		cout << ( "\nAccount Type: \t \t Super Gold Plus" );
		rate = 7.0;
	}

	if ( 25000 <= balance && balance < 50000 )
	{
		cout << ( "\nAccount Type: \t \t Platinum Extra" );
		rate = 7.5;
	}

	if ( 50000 <= balance && balance < 75000 )
	{
		cout << ( "\nAccount Type: \t \t Double Platinum" );
		rate = 8.0;
	}

	if ( 75000 <= balance && balance < 100000 )
	{
		cout << ( "\nAccount Type: \t \t Triple Platinum" );
		rate = 8.5;
	}

	if ( 100000 <= balance && balance < 250000 )
	{
		cout << ( "\nAccount Type: \t \t Diamond Deposit" );
		rate = 9.0;
	}

	if ( 250000 <= balance && balance < 500000 )
	{
		cout << ( "\nAccount Type: \t \t Diamond Deposit Plus" );
		rate = 9.5;
	}

	if ( 500000 <= balance && balance < 1000000 )
	{
		cout << ( "\nAccount Type: \t \t Diamond Deposit Gold" );
		rate = 10.0;
	}

	if ( 1000000 <= balance && balance < 2000000 )
	{
		cout << ( "\nAccount Type: \t \t Millionaire Platinum" );
		rate = 10.5;
	}

	if ( 2000000 <= balance && balance < 5000000 )
	{
		cout << ( "\nAccount Type: \t \t Millionaire Double Platinum" );
		rate = 11.0;
	}

	if ( 5000000 <= balance && balance < 7500000 )
	{
		cout << ( "\nAccount Type: \t \t Millionaire Mega-Platinum" );
		rate = 11.5;
	}

	if ( 7500000 <= balance && balance < 10000000 )
	{
		cout << ( "\nAccount Type: \t \t Neopian Mega-Riches" );
		rate = 12.0;
	}

	if ( 10000000 <= balance && balance < 2147483647 )
	{
		cout << ( "\nAccount Type: \t \t Ultimate Riches!" );
		rate = 12.5;
	}
}

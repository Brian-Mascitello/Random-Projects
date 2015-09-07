/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			9/3/2015
EXERCISE:		C++ Practice
SPECIFICATION:	This program simulates a poker variant known
	as "Five Card Draw".
-------------------------------------------------------------------------*/

// INCLUDES
#include "header.h"

struct Card
{
	// Creates a Card structure that knows if it has been dealt yet or not,
	// as well as the value and suit of the of the card.

	bool dealt;
	int card_value;
	suit suit_letter;
};

Card Deck[deck_size]; // 52 cards in a deck, no jokers! Filled with buildDeck();
Card PlayerHand[hand_size]; // Players can have up to 5 cards at a time.

char last_char = ' '; // Used to prevent re-entering play mode after escaping on continue screen.

using namespace std;

// All functions are void, mainly used for displaying information.
void branching(char char_user_input);
void buildDeck();
void changeBet();
void changeCards();
void continuePrompt();
void cleanReset();
void dealHand();
void discardCard(int position);
void howToPlay();
void mainMenu();
void printHand();
void printPrizes();
void printRules();
void purchaseCredits();
void resetDeck();
void runGame();
void sortHand();
void winningConditions();

void main()
{
	// This function will create the deck of cards, set the console backround to white,
	// and display the main menu, which the user will directly interact with.

	buildDeck();

	system("Color F0"); // Sets background color to white.

	mainMenu();
}

void branching(char char_user_input)
{
	// This is the main menu selection function. It takes the char value from mainMenu()
	// and uses it in a switch statement to enter the next appropriate function.

	char char_branching_input = ' ';

	switch (char_user_input)
	{
		case 'b':
			purchaseCredits();
			break;

		case 'c':
			changeBet();
			break;

		case 'h':
			howToPlay();
			break;

		case 'l':
			printPrizes();
			break;

		case 'p':
			if (total_credits < minimum_bet)
			{
				clear_screen();
				cout << "\n You do not have enough credits to continue!\n";
				purchaseCredits();
			}
			else if (current_bet > total_credits)
			{
				cout << "\n You cannot bet that much.";
				cout << "\n Please change your current bet.\n";
			}
			else
			{
				flush();
				do
				{
					runGame();
				} while ((current_bet <= total_credits) && (total_credits >= minimum_bet) && (last_char != 'q'));

				if ((current_bet > total_credits) || (total_credits < minimum_bet)) {
					mainMenu();
				}
			}
			break;

		case 'q':
			break;

		case 's':
			printRules();
			break;

		default:
			cout << "\n\n Branching invalid input. \n";
	}
}

void buildDeck()
{
	// Creates the standard deck of 52 cards, the values are from 2-14 with the Ace = 14.

	int suit_index, value_index;

	for (suit_index = 0; suit_index < number_of_suits; suit_index++)
	{
		for (value_index = 0; value_index < values_per_suit; value_index++)
		{
			if (suit_index == 0)
			{
				Deck[suit_index + value_index].suit_letter = Clubs;
				Deck[suit_index + value_index].card_value = (value_index + 2);
				Deck[suit_index + value_index].dealt = false;
			}

			if (suit_index == 1)
			{
				Deck[12 + suit_index + value_index].suit_letter = Diamonds;
				Deck[12 + suit_index + value_index].card_value = (value_index + 2);
				Deck[12 + suit_index + value_index].dealt = false;
			}

			if (suit_index == 2)
			{
				Deck[24 + suit_index + value_index].suit_letter = Hearts;
				Deck[24 + suit_index + value_index].card_value = (value_index + 2);
				Deck[24 + suit_index + value_index].dealt = false;
			}

			if (suit_index == 3)
			{
				Deck[36 + suit_index + value_index].suit_letter = Spades;
				Deck[36 + suit_index + value_index].card_value = (value_index + 2);
				Deck[36 + suit_index + value_index].dealt = false;
			}
		}
	}
}

void changeBet()
{
	// Takes a user integer and judges whether or not it can be a new bet.
	// The rules state it must be greater than 5 and less than 10,000.

	int changeBet;

	cout << "\n Total Credits: " << total_credits << endl;
	cout << "\n What would you like your bet to be? ---> ";
	cin >> changeBet;

	if (changeBet < minimum_bet)
	{
		cout << "\n You must bet at least " << minimum_bet << " credits.\n";
	}
	else if (changeBet > total_credits)
	{
		cout << "\n You do not have enough credits.\n";
	}
	else if (changeBet > maximum_bet)
	{
		cout << "\n You cannot bet more than " << maximum_bet << " credits.\n";
	}
	else
	{
		current_bet = changeBet;
		cout << "\n Current bet successfully changed to " << current_bet << ".\n";
	}

	cleanReset();
}

void changeCards()
{
	// Swaps the user's original cards with new ones from the deck.

	int discard_digit, int_user_input;
	string truncated_user_string = "";
	string string_user_input = "";

	cout << "\n\n\n\n\n\n Enter the numbers to discard ---> ";
	getline(cin, string_user_input);
	truncated_user_string = string_user_input.substr(0, 5);
	stringstream convert(truncated_user_string);

	if (convert >> int_user_input)
	{
		while (int_user_input > 0)
		{
			discard_digit = int_user_input % 10;

			if (discard_digit == 1 || discard_digit == 2 ||
				discard_digit == 3 || discard_digit == 4 ||
				discard_digit == 5)
			{
				discardCard(discard_digit - 1);
			}

			int_user_input /= 10;
		}
	}
	else
	{
		cout << "\nInvalid integer, please try again.\n";
	}

	int_user_input = 0;
	string_user_input = "";
}

void cleanReset()
{
	// Waits for the user to enter something, then returns to the main menu.

	cout << "\n\n Press enter to continue ---> ";
	flush();
	getchar(); // Left intentionally so the user can see output before screen erased.
	clear_screen();
	mainMenu();
}

void continuePrompt()
{
	// If the user hits enter it continues gameplay, otherwise it will escape to the main menu.

	char continue_if_newline;

	cout << "\n Press enter to continue ---> ";
	continue_if_newline = getchar();

	clear_screen();

	if (continue_if_newline != '\n')
	{
		last_char = 'q';
		mainMenu();
	}
}

void dealHand()
{
	// Deals the player a hand with 5 unique cards. If the card has already been drawn,
	// it will change the random number sequence and search for a new, undrawn card.

	int hand_index, random_number;

	for (hand_index = 0; hand_index < hand_size; hand_index++)
	{
		random_number = (rand() % deck_size);

		if (Deck[random_number].dealt == false)
		{
			PlayerHand[hand_index].card_value = Deck[random_number].card_value;
			PlayerHand[hand_index].suit_letter = Deck[random_number].suit_letter;
			Deck[random_number].dealt = true;
		}
		else
		{
			do
			{
				srand(unsigned(time(NULL)));
				random_number = (rand() % deck_size);
			} while (Deck[random_number].dealt == true);

			PlayerHand[hand_index].card_value = Deck[random_number].card_value;
			PlayerHand[hand_index].suit_letter = Deck[random_number].suit_letter;
			Deck[random_number].dealt = true;
		}
	}
	total_credits -= current_bet;
}

void discardCard(int position)
{
	// Discards the card located at a provided integer position from the user.
	// This will dig for an undrawn card, and double check to make sure it is unique.

	int double_check, random_number_1, random_number_2;

	random_number_1 = (rand() % deck_size);

	if (Deck[random_number_1].dealt == false)
	{
		PlayerHand[position].card_value = Deck[random_number_1].card_value;
		PlayerHand[position].suit_letter = Deck[random_number_1].suit_letter;
		Deck[random_number_1].dealt = true;
	}
	else
	{
		do
		{
			srand(unsigned(time(NULL)));
			random_number_2 = (rand() % deck_size);
		} while (Deck[random_number_2].dealt == true);

		for (double_check = 0; double_check < hand_size; double_check++)
		{
			if (PlayerHand[double_check].card_value == Deck[random_number_2].card_value &&
				PlayerHand[double_check].suit_letter == Deck[random_number_2].suit_letter)
			{
				discardCard(position);
			}
		}

		PlayerHand[position].card_value = Deck[random_number_2].card_value;
		PlayerHand[position].suit_letter = Deck[random_number_2].suit_letter;
		Deck[random_number_2].dealt = true;
	}
}

void howToPlay()
{
	// Displays the guide to the user.

	cout << "\n How to Play";
	cout << "\n -----------";
	cout << "\n After selecting play from the menu you will be dealt five cards.";
	cout << "\n Enter the numbers that correspond with the cards in your hand";
	cout << "\n that you would like to draw, and you will be dealt new cards based";
	cout << "\n on what you entered. If you have a winning hand, you will earn credits.";
	cout << "\n If you lose, your bet will be subtracted from your total credits.";
	cout << "\n After each hand is played, you will be returned to the main menu.";
	cout << "\n Good luck and have fun!!!";
	cleanReset();
}

void mainMenu()
{
	// Displays the main menu to the user, prompts the user to select an option by
	// typing a character.

	char char_user_input = ' ';
	last_char = ' ';

	cout << "\n Welcome to Brian's Five Card Draw!!!";
	cout << "\n\n -------------\t\tTotal Credits: " << total_credits;
	cout << "\n   Main Menu";
	cout << "\n -------------\t\t  Current Bet: " << current_bet << endl;
	cout << "\n P) Play 5 Card Draw";
	cout << "\n B) Buy More Credits";
	cout << "\n C) Change Current Bet";
	cout << "\n L) List the Prizes";
	cout << "\n H) How to Play";
	cout << "\n S) Show the Rules";
	cout << "\n Q) Quit";
	cout << "\n\n Please enter a choice ---> ";

	cin >> char_user_input;
	char_user_input = tolower(char_user_input);
	last_char = char_user_input;

	if (char_user_input != 'q') {
		clear_screen();
		srand(unsigned(time(NULL)));
		branching(char_user_input);
	}
}

void printHand()
{
	// Display's the user's hand on the screen. Changes the title text to blue if the hand is fresh.
	// Also converts the higher card values to text so the user can read them appropriately.

	int print_index;

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	if (initial)
	{
		SetConsoleTextAttribute(screen, 249);

		cout << "\n ------------\t\tTotal Credits: " << total_credits;
		cout << "\n   New Hand";
		cout << "\n ------------\t\t  Current Bet: " << current_bet << endl;

		SetConsoleTextAttribute(screen, 240);
	}
	else
	{
		cout << "\n --------------------\tTotal Credits: " << total_credits;
		cout << "\n   After Discarding";
		cout << "\n --------------------\t  Current Bet: " << current_bet << endl;
	}

	initial = !initial;

	for (print_index = 0; print_index < hand_size; print_index++)
	{
		if (suit_names[PlayerHand[print_index].suit_letter] == "Diamonds" || suit_names[PlayerHand[print_index].suit_letter] == "Hearts")
		{
			SetConsoleTextAttribute(screen, 252);
		}

		if (PlayerHand[print_index].card_value == 10)
			cout << "\n " << print_index + 1 << ")  10 " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		else if (PlayerHand[print_index].card_value == 11)
			cout << "\n " << print_index + 1 << ")  J  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		else if (PlayerHand[print_index].card_value == 12)
			cout << "\n " << print_index + 1 << ")  Q  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		else if (PlayerHand[print_index].card_value == 13)
			cout << "\n " << print_index + 1 << ")  K  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		else if (PlayerHand[print_index].card_value == 14)
			cout << "\n " << print_index + 1 << ")  A  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		else
			cout << "\n " << print_index + 1 << ")  " << PlayerHand[print_index].card_value << "  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << endl;
		if (print_index == 4)
			cout << "\n";

		SetConsoleTextAttribute(screen, 240);
	}
}

void printPrizes()
{
	// Displays the prize tiers for the user.

	cout << "\n Prize Pool";
	cout << "\n ----------";
	cout << "\n Winning name: Multiple of amount bet\n";
	cout << "\n Royal flush:\t  5000";
	cout << "\n Straight flush:  500";
	cout << "\n Four of a kind:  150";
	cout << "\n Full house:\t  75";
	cout << "\n Flush:\t\t  50";
	cout << "\n Straight:\t  20";
	cout << "\n Three of a kind: 5";
	cout << "\n Two pair:\t  2";
	cout << "\n Jacks or better: 1";
	cleanReset();
}

void printRules()
{
	// Displays the rules set to the user.

	cout << "\n Rules";
	cout << "\n -----";
	cout << "\n The minimum bet is " << minimum_bet << " credits.";
	cout << "\n The maximum bet is " << maximum_bet << " credits.";
	cout << "\n\n If your credit balance falls below the minimum bet, ";
	cout << "\n you must add more to continue playing.\n";
	cleanReset();
}

void purchaseCredits()
{
	// Allows the user to buy more credits if they have fallen under 1000.

	int add_credits;

	if (total_credits >= 1000)
	{
		cout << "\n You may only add to your balance if you are below " << one_thousand << " credits.\n";
	}
	else
	{
		cout << "\n You may currently add up to " << one_thousand - total_credits << " credits.";
		cout << "\n\n How many credits would you like to buy? ---> ";
		cin >> add_credits;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n User input not an integer.";
		}
		else
		{
			if (add_credits < (minimum_bet - total_credits))
			{
				cout << "\n You must buy enough credits to play at least once!";
			}
			else if (add_credits >(one_thousand - total_credits))
			{
				cout << "\n You may only buy up to " << one_thousand << " credits." << endl;
			}
			else
			{
				total_credits += add_credits;
			}
		}
	}
	cleanReset();
}


void resetDeck()
{
	// Sets all the cards in the deck to undrawn, so the next hand can be completely unique and include
	// cards from previous plays, but ensure enough cards to redraw if desired.

	int reset_index;

	for (reset_index = 0; reset_index < deck_size; reset_index++)
	{
		Deck[reset_index].dealt = false;
	}
}

void runGame()
{
	// Combines multiple functions to properly display the gameplay to the user.

	dealHand();
	printHand();
	changeCards();
	clear_screen();
	printHand();
	sortHand();
	winningConditions();
	resetDeck();
	continuePrompt();
}

void sortHand()
{
	// This is called after the redrawn hand is displayed. It uses Selection Sort to organize
	// the player's hand values in ascending order so it is easier to calculate the winning conditions.

	int current_index, smallest_index, start_index;

	for (start_index = 0; start_index < hand_size; start_index++)
	{
		smallest_index = start_index;

		for (current_index = start_index + 1; current_index < hand_size; current_index++)
		{
			if (PlayerHand[current_index].card_value < PlayerHand[smallest_index].card_value)
				smallest_index = current_index;
		}

		swap(PlayerHand[start_index].card_value, PlayerHand[smallest_index].card_value);
		swap(PlayerHand[start_index].suit_letter, PlayerHand[smallest_index].suit_letter);
	}
}

void winningConditions()
{
	// Checks the sorted player hand for winning scenarios, as soon as one is found, it awards
	// that as a prize. The better prizes are checked first at the top of this function.

	if (PlayerHand[0].card_value == 10 &&
		PlayerHand[1].card_value == 11 &&
		PlayerHand[2].card_value == 12 &&
		PlayerHand[3].card_value == 13 &&
		PlayerHand[4].card_value == 14 &&
		(PlayerHand[0].suit_letter == PlayerHand[1].suit_letter) &&
		(PlayerHand[1].suit_letter == PlayerHand[2].suit_letter) &&
		(PlayerHand[2].suit_letter == PlayerHand[3].suit_letter) &&
		(PlayerHand[3].suit_letter == PlayerHand[4].suit_letter))
	{
		cout << "\n CONGRATULATIONS ROYAL FLUSH!!";
		cout << "\n ---You win 5000x your bet!---";
		cout << "\n\n Won this hand: " << 5000 * current_bet <<endl;
		total_credits += (5000 * current_bet);
	}
	else if (((PlayerHand[0].card_value == 2 &&
		PlayerHand[1].card_value == 3 &&
		PlayerHand[2].card_value == 4 &&
		PlayerHand[3].card_value == 5 &&
		PlayerHand[4].card_value == 14) &&
		((PlayerHand[0].suit_letter == PlayerHand[1].suit_letter) &&
			(PlayerHand[1].suit_letter == PlayerHand[2].suit_letter) &&
			(PlayerHand[2].suit_letter == PlayerHand[3].suit_letter) &&
			(PlayerHand[3].suit_letter == PlayerHand[4].suit_letter))) ||
		((PlayerHand[0].card_value == (PlayerHand[1].card_value - 1) &&
			(PlayerHand[1].card_value == (PlayerHand[2].card_value - 1)) &&
			(PlayerHand[2].card_value == (PlayerHand[3].card_value - 1)) &&
			(PlayerHand[3].card_value == (PlayerHand[4].card_value - 1)) &&
			(PlayerHand[0].suit_letter == PlayerHand[1].suit_letter) &&
			(PlayerHand[1].suit_letter == PlayerHand[2].suit_letter) &&
			(PlayerHand[2].suit_letter == PlayerHand[3].suit_letter) &&
			(PlayerHand[3].suit_letter == PlayerHand[4].suit_letter))))
	{
		cout << "\n CONGRATULATIONS STRAIGHT FLUSH!";
		cout << "\n ----You win 500x your bet!----";
		cout << "\n\n Won this hand: " << 500 * current_bet << endl;
		total_credits += (500 * current_bet);
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value &&
		PlayerHand[1].card_value == PlayerHand[2].card_value &&
		PlayerHand[2].card_value == PlayerHand[3].card_value) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value &&
			PlayerHand[2].card_value == PlayerHand[3].card_value &&
			PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS FOUR OF A KIND!";
		cout << "\n ----You win 150x your bet!!----";
		cout << "\n\n Won this hand: " << 150 * current_bet << endl;
		total_credits += (150 * current_bet);
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value &&
		PlayerHand[2].card_value == PlayerHand[3].card_value &&
		PlayerHand[3].card_value == PlayerHand[4].card_value) ||
		(PlayerHand[0].card_value == PlayerHand[1].card_value &&
			PlayerHand[1].card_value == PlayerHand[2].card_value &&
			PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS FULL HOUSE!";
		cout << "\n ---You win 75x your bet!---";
		cout << "\n\n Won this hand: " << 75 * current_bet << endl;
		total_credits += (75 * current_bet);
	}
	else if ((PlayerHand[0].suit_letter == PlayerHand[1].suit_letter) &&
		(PlayerHand[1].suit_letter == PlayerHand[2].suit_letter) &&
		(PlayerHand[2].suit_letter == PlayerHand[3].suit_letter) &&
		(PlayerHand[3].suit_letter == PlayerHand[4].suit_letter))
	{
		cout << "\n CONGRATULATIONS FLUSH!!";
		cout << "\n -You win 50x your bet!-";
		cout << "\n\n Won this hand: " << 50 * current_bet << endl;
		total_credits += (50 * current_bet);
	}
	else if ((PlayerHand[0].card_value == 2 &&
		PlayerHand[1].card_value == 3 &&
		PlayerHand[2].card_value == 4 &&
		PlayerHand[3].card_value == 5 &&
		PlayerHand[4].card_value == 14) ||
		((PlayerHand[0].card_value == (PlayerHand[1].card_value - 1)) &&
			(PlayerHand[1].card_value == (PlayerHand[2].card_value - 1)) &&
			(PlayerHand[2].card_value == (PlayerHand[3].card_value - 1)) &&
			(PlayerHand[3].card_value == (PlayerHand[4].card_value - 1))))
	{
		cout << "\n CONGRATULATIONS STRAIGHT!";
		cout << "\n --You win 20x your bet!--";
		cout << "\n\n Won this hand: " << 20 * current_bet << endl;
		total_credits += (20 * current_bet);
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[1].card_value == PlayerHand[2].card_value) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value && PlayerHand[2].card_value == PlayerHand[3].card_value) ||
		(PlayerHand[2].card_value == PlayerHand[3].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS THREE OF A KIND!";
		cout << "\n ------You win 5x your bet!------";
		cout << "\n\n Won this hand: " << 5 * current_bet << endl;
		total_credits += (5 * current_bet);
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[2].card_value == PlayerHand[3].card_value) ||
		(PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS TWO PAIR";
		cout << "\n --You win 2x your bet!--";
		cout << "\n\n Won this hand: " << 2 * current_bet << endl;
		total_credits += (2 * current_bet);
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[0].card_value > 10) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value && PlayerHand[1].card_value > 10) ||
		(PlayerHand[2].card_value == PlayerHand[3].card_value && PlayerHand[2].card_value > 10) ||
		(PlayerHand[3].card_value == PlayerHand[4].card_value && PlayerHand[3].card_value > 10))
	{
		cout << "\n CONGRATULATIONS JACKS OR BETTER!";
		cout << "\n ------You win 1x your bet!------";
		cout << "\n\n Won this hand: " << current_bet << endl;
		total_credits += current_bet;
	}
	else
	{
		cout << "\n\n\n\n\n";
	}
}
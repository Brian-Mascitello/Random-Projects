/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			9/28/2015
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

class Record
{
	// Creates a Record structure that is used for saving and loading high
	// scores from a data file.

	public:
		Record();
		Record(time_t input_date, std::string input_initials, int input_score, int input_win);

		time_t getDate();
		std::string getInitials();
		int getScore();
		int getWin();

		void setDate(time_t input_date);
		void setInitials(std::string input_initials);
		void setScore(int input_score);
		void setWin(int input_win);

		Record* nextRecordNode;

	private:
		char initials[MAX_INITIALS_LENGTH];
		int score;
		int win;
		time_t date;

} *headRecordNode = NULL;

Record::Record()
{

}

Record::Record(time_t input_date, std::string input_initials, int input_score, int input_win)
{
	date = input_date;
	std::strcpy(initials, input_initials.c_str());
	score = input_score;
	win = input_win;
}

time_t Record::getDate()
{
	return date;
}

std::string Record::getInitials()
{
	return initials;
}

int Record::getScore()
{
	return score;
}

int Record::getWin()
{
	return win;
}

void Record::setDate(time_t input_date)
{
	date = input_date;
}

void Record::setInitials(std::string input_initials)
{
	std::strcpy(initials, input_initials.c_str());
}

void Record::setScore(int input_score)
{
	score = input_score;
}

void Record::setWin(int input_win)
{
	win = input_win;
}

Card Deck[DECK_SIZE]; // 52 cards in a deck, no jokers! Filled with buildDeck();
Card PlayerHand[HAND_SIZE]; // Players can have up to 5 cards at a time.

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); // Used to change font colors.

char last_char = ' '; // Used to prevent re-entering play mode after escaping on continue screen.
int biggest_win = 0;
int max_credits = ONE_THOUSAND;

using namespace std;

// FORWARD DECLARATIONS
void branchingMenu(char char_user_input);
void buildDeck();
void changeBet();
void changeCards();
void cleanReset();
void continuePrompt();
void createHighScoresList(time_t input_date, string input_initials, int input_score, int input_win);
void dealHand();
void discardCard(int position);
void freePointer(Record* node);
string getInitialsFromUser();
void highScoresAdd();
void highScoresLoad();
void highScoresSave();
void highScoresView();
void mainMenu();
string orderPrizes(int tier);
void printHand();
void printHowToPlay();
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

	highScoresLoad(); // Loads a linked list of high scores.

	buildDeck(); // Constructs a standard deck of 52 cards.

	system("Color F0"); // Sets background color to white.

	mainMenu(); // Displays the main menu where the game is controlled in.

	highScoresAdd(); // After quitting the game, prompts the user for initials to add their score.

	highScoresSave(); // Saves their score to the linked list file.

	freePointer(headRecordNode); // Frees the linked list from memory space.
}

void branchingMenu(char char_user_input)
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
			printHowToPlay();
			break;

		case 'l':
			printPrizes();
			break;

		case 'p':
			if (total_credits < MINIMUM_BET)
			{
				clearScreen();
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
				do
				{
					runGame();
				} while ((current_bet <= total_credits) && (total_credits >= MINIMUM_BET) && (last_char != 'q'));

				if ((current_bet > total_credits) || (total_credits < MINIMUM_BET)) {
					mainMenu();
				}
			}
			break;

		case 'q':
			break;

		case 's':
			printRules();
			break;

		case 'v':
			highScoresView();
			break;

		default:
			cout << "\n\n Branching invalid input. \n";
	}
}

void buildDeck()
{
	// Creates the standard deck of 52 cards, the values are from 2-14 with the Ace = 14.

	int suit_index, value_index;

	for (suit_index = 0; suit_index < NUMBER_OF_SUITS; suit_index++)
	{
		for (value_index = 0; value_index < VALUES_PER_SUIT; value_index++)
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

	if (changeBet < MINIMUM_BET)
	{
		cout << "\n You must bet at least " << MINIMUM_BET << " credits.";
	}
	else if (changeBet > total_credits)
	{
		cout << "\n You do not have enough credits to bet " << changeBet << ".";
	}
	else if (changeBet > MAXIMUM_BET)
	{
		cout << "\n You cannot bet more than " << MAXIMUM_BET << " credits.";
	}
	else
	{
		current_bet = changeBet;
		cout << "\n Current bet successfully changed to " << current_bet << ".";
	}

	cleanReset();
}

void changeCards()
{
	// Swaps the user's original cards with new ones from the deck.

	int discard_digit, int_user_input;
	string truncated_user_string = "";
	string string_user_input = "";

	SetConsoleTextAttribute(screen, 249);
	cout << "\n\n\n\n\n\n Enter the numbers to discard ---> ";
	SetConsoleTextAttribute(screen, 240);

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
	flushBuffer();
	clearScreen();
	mainMenu();
}

void continuePrompt()
{
	// If the user hits enter it continues gameplay, otherwise it will escape to the main menu.

	char continue_if_newline;

	cout << "\n Press enter to continue ---> ";
	continue_if_newline = getchar();

	clearScreen();

	if (continue_if_newline != '\n')
	{
		last_char = 'q';
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		mainMenu();
	}
}

void createHighScoresList(time_t input_date, string input_initials, int input_score, int input_win)
{
	// Helper function which takes the data from highScoresLoad() and inserts it into a linked list.

	Record *newRecordNode;
	newRecordNode = new Record(input_date, input_initials, input_score, input_win);

	if (newRecordNode == NULL)
	{
		cout << "Out of Memory\n";
	}
	else
	{
		if (headRecordNode == NULL)
		{
			headRecordNode = newRecordNode;
		}
		else
		{
			Record *currentHubNode = headRecordNode;
			Record *trailHubNode = NULL;

			while (currentHubNode != NULL)
			{
				if (newRecordNode->getScore() > currentHubNode->getScore())
				{
					break;
				}
				else
				{
					trailHubNode = currentHubNode;
					currentHubNode = currentHubNode->nextRecordNode;
				}
			}

			if (currentHubNode == headRecordNode)
			{
				newRecordNode->nextRecordNode = headRecordNode;
				headRecordNode = newRecordNode;
			}
			else
			{
				newRecordNode->nextRecordNode = currentHubNode;
				trailHubNode->nextRecordNode = newRecordNode;
			}
		}
	}
}

void dealHand()
{
	// Deals the player a hand with 5 unique cards. If the card has already been drawn,
	// it will change the random number sequence and search for a new, undrawn card.

	int hand_index, random_number;

	for (hand_index = 0; hand_index < HAND_SIZE; hand_index++)
	{
		random_number = (rand() % DECK_SIZE);

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
				random_number = (rand() % DECK_SIZE);
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

	random_number_1 = (rand() % DECK_SIZE);

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
			random_number_2 = (rand() % DECK_SIZE);
		} while (Deck[random_number_2].dealt == true);

		for (double_check = 0; double_check < HAND_SIZE; double_check++)
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

void freePointer(Record* node)
{
	// Frees the pointer from memory space.

	if (node != NULL)
	{
		freePointer(node->nextRecordNode);
		free(node);
	}
}

string getInitialsFromUser()
{
	// Retrieves the user's initials, converts to uppercase, and returns a string of length 3.

	clearScreen();

	string initials = "";

	cout << "\n Please enter your initials ---> ";
	cin >> initials;

	initials = initials.substr(0, 3);
	initials.resize(3, ' ');

	transform(initials.begin(), initials.end(), initials.begin(), ::toupper);

	return initials;
}

void highScoresAdd()
{
	// Adds the user's current score and data to the high scores linked list.

	string name = getInitialsFromUser();
	time_t now = time(0);

	Record *add_pointer;
	Record *search_pointer = headRecordNode;
	Record **trail_pointer = &headRecordNode;

	add_pointer = (Record *) malloc (sizeof(Record));
	add_pointer->setDate(now);
	add_pointer->setInitials(name);
	add_pointer->setScore(max_credits);
	add_pointer->setWin(biggest_win);

	if (add_pointer == NULL)
	{
		cout << "\n Out of memory! \n";
	}
	else
	{
		if (search_pointer == NULL)
		{
			add_pointer->nextRecordNode = headRecordNode;
			headRecordNode = add_pointer;
		}
		else
		{
			while (search_pointer != NULL && search_pointer->getScore() >= add_pointer->getScore())
			{
				trail_pointer = &search_pointer->nextRecordNode;
				search_pointer = search_pointer->nextRecordNode;
			}

			*trail_pointer = add_pointer;
			add_pointer->nextRecordNode = search_pointer;
		}
	}
}

void highScoresLoad()
{
	// Extracts the data from the high scores save file and puts it into a linked list.

	int score = 0;
	int win = 0;
	string initials = "";
	string date_string = "";
	string score_string = "";
	string win_string = "";
	time_t date = 0;

	ifstream highScoresLoad(HIGH_SCORES);

	if (highScoresLoad.is_open())
	{
		string line;
		while (getline(highScoresLoad, line))
		{
			istringstream parsed(line);

			getline(parsed, date_string, ',');
			istringstream(date_string) >> date;

			getline(parsed, initials, ',');

			getline(parsed, score_string, ',');
			istringstream(score_string) >> score;

			getline(parsed, win_string, ',');
			istringstream(win_string) >> win;

			createHighScoresList(date, initials, score, win);
		}
		highScoresLoad.close();
	}
}

void highScoresSave()
{
	// Saves the high scores to the file.

	FILE *fileName;
	Record *node;

	char *date_converted = new char[10];
	char *initials_converted = new char[MAX_INITIALS_LENGTH];
	char *score_converted = new char[MAX_SCORE_LENGTH];
	char *win_converted = new char[1];
	
	int score_holder = 0;
	int win_holder = 0;
	std::string string_holder = "";
	time_t date_holder = 0;

	fileName = fopen(HIGH_SCORES, "wb");

	if (fileName != NULL)
	{
		node = headRecordNode;
		while (node != NULL)
		{
			date_holder = node->getDate();
			string_holder = std::to_string(date_holder);
			std::strcpy(date_converted, string_holder.c_str());
			fwrite(date_converted, 10, 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			string_holder = node->getInitials();
			std::strcpy(initials_converted, string_holder.c_str());
			fwrite(initials_converted, MAX_INITIALS_LENGTH, 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			score_holder = node->getScore();
			string_holder = std::to_string(score_holder);
			std::strcpy(score_converted, string_holder.c_str());
			fwrite(score_converted, MAX_SCORE_LENGTH, 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			win_holder = node->getWin();
			string_holder = std::to_string(win_holder);
			std::strcpy(win_converted, string_holder.c_str());
			fwrite(win_converted, 1, 1, fileName);

			node = node->nextRecordNode;
			fwrite("\n", sizeof('\n'), 1, fileName);
		}
	}
	else
	{
		cout << "\n ERROR: Could not open file for saving data ! \n";
	}
}

void highScoresView()
{
	// Displays a list of the high scores for the user.

	int counter = 1;
	Record *view_pointer = headRecordNode;
	
	if (view_pointer == NULL)
	{
		cout << "\n No Records Found.";
	}
	else
	{
		cout << "\n              High Scores!!!!";
		cout << "\n -----------------------------------------";
		cout << "\n\n Rank) Initials | Score | Best Hand | Date\n";

		while (view_pointer && counter < 16)
		{
			if (counter < 4)
			{
				SetConsoleTextAttribute(screen, 224);
			}
			else if (counter < 7)
			{
				SetConsoleTextAttribute(screen, 112);
			}
			else if (counter < 10)
			{
				SetConsoleTextAttribute(screen, 96);
			}
			else
			{
				SetConsoleTextAttribute(screen, 240);
			}

			if (counter < 10)
			{
				cout << "\n  " << counter << ") ";
			}
			else
			{
				cout << "\n " << counter << ") ";
			}

			cout << view_pointer->getInitials() << " | ";
			cout << std::setw(MAX_SCORE_LENGTH) << view_pointer->getScore() << " | ";
			cout << std::setw(MAX_WIN_LENGTH) << orderPrizes(view_pointer->getWin()) << " | ";
			
			time_t date_node = view_pointer->getDate();
			tm convert_date = *localtime(&date_node);

			if (convert_date.tm_mon < 9)
			{
				cout << " " << convert_date.tm_mon + 1 << "/" << convert_date.tm_mday << "/" << convert_date.tm_year + 1900;
			}
			else
			{
				cout << convert_date.tm_mon + 1 << "/" << convert_date.tm_mday << "/" << convert_date.tm_year + 1900;
			}
			
			view_pointer = view_pointer->nextRecordNode;
			counter++;
		}

		SetConsoleTextAttribute(screen, 240);
	}

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
	cout << "\n V) View the High Scores";
	cout << "\n Q) Quit";
	cout << "\n\n Please enter a choice ---> ";

	cin >> char_user_input;
	char_user_input = tolower(char_user_input);
	last_char = char_user_input;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	clearScreen();
	
	if (char_user_input == 'b' || char_user_input == 'c' || char_user_input == 'h' ||
		char_user_input == 'l' || char_user_input == 'p' || char_user_input == 's' ||
		char_user_input == 'v') {
		srand(unsigned(time(NULL)));
		branchingMenu(char_user_input);
	}
	else if (char_user_input == 'q') {

	}
	else {
		cout << "\n Please enter a letter corresponding to a menu option.\n";
		mainMenu();
	}
}

string orderPrizes(int tier)
{
	switch (tier)
	{
		case 9:
			return "Royal flush";
			break;
		case 8:
			return "Straight flush";
			break;
		case 7:
			return "Four of a kind";
			break;
		case 6:
			return "Full house";
			break;
		case 5:
			return "Flush";
			break;
		case 4:
			return "Straight";
			break;
		case 3:
			return "Three of a kind";
			break;
		case 2:
			return "Two pair";
			break;
		case 1:
			return "Jacks or better";
			break;
		default:
			return "Nothing";
			break;
	}
}

void printHand()
{
	// Display's the user's hand on the screen. Changes the title text to blue if the hand is fresh.
	// Also converts the higher card values to text so the user can read them appropriately.

	int print_index;

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

	for (print_index = 0; print_index < HAND_SIZE; print_index++)
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

void printHowToPlay()
{
	// Displays the guide to the user.

	cout << "\n How to Play";
	cout << "\n -----------";
	cout << "\n\n After selecting play from the menu you will be dealt five cards.";
	cout << "\n Enter the numbers that correspond with the cards in your hand";
	cout << "\n that you would like to draw, and you will be dealt new cards based";
	cout << "\n on what you entered. If you have a winning hand, you will earn credits.";
	cout << "\n If you lose, your bet will be subtracted from your total credits.";
	cout << "\n After each hand is played, you will be returned to the main menu.";
	cout << "\n\n Good luck and have fun!!!";
	cleanReset();
}

void printPrizes()
{
	// Displays the prize tiers for the user.

	cout << "\n Prize Pool";
	cout << "\n ----------";
	cout << "\n\n Winning name: Multiple of amount bet\n";
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
	cout << "\n\n The minimum bet is " << MINIMUM_BET << " credits.";
	cout << "\n The maximum bet is " << MAXIMUM_BET << " credits.";
	cout << "\n\n If your credit balance falls below the minimum bet, ";
	cout << "\n you must add more to continue playing.";
	cleanReset();
}

void purchaseCredits()
{
	// Allows the user to buy more credits if they have fallen under 1000.

	int add_credits;

	if (total_credits >= 1000)
	{
		cout << "\n You may only add to your balance if you are below " << ONE_THOUSAND << " credits.";
	}
	else
	{
		cout << "\n You may currently add up to " << ONE_THOUSAND - total_credits << " credits.";
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
			if (add_credits < 1)
			{
				cout << "\n You may only add a positive credit amount.";
			}
			else if (add_credits < (MINIMUM_BET - total_credits))
			{
				cout << "\n You must buy enough credits to play at least once!";
			}
			else if (add_credits > (ONE_THOUSAND - total_credits))
			{
				cout << "\n You may only buy up to " << ONE_THOUSAND << " credits.";
			}
			else
			{
				total_credits += add_credits;
				cout << "\n Total credits is now " << total_credits << ".";
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

	for (reset_index = 0; reset_index < DECK_SIZE; reset_index++)
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
	clearScreen();
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

	for (start_index = 0; start_index < HAND_SIZE; start_index++)
	{
		smallest_index = start_index;

		for (current_index = start_index + 1; current_index < HAND_SIZE; current_index++)
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

		if (biggest_win < 9)
		{
			biggest_win = 9;
		}
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

		if (biggest_win < 8)
		{
			biggest_win = 8;
		}
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

		if (biggest_win < 7)
		{
			biggest_win = 7;
		}
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

		if (biggest_win < 6)
		{
			biggest_win = 6;
		}
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
		
		if (biggest_win < 5)
		{
			biggest_win = 5;
		}
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

		if (biggest_win < 4)
		{
			biggest_win = 4;
		}
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[1].card_value == PlayerHand[2].card_value) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value && PlayerHand[2].card_value == PlayerHand[3].card_value) ||
		(PlayerHand[2].card_value == PlayerHand[3].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS THREE OF A KIND!";
		cout << "\n ------You win 5x your bet!------";
		cout << "\n\n Won this hand: " << 5 * current_bet << endl;
		total_credits += (5 * current_bet);

		if (biggest_win < 3)
		{
			biggest_win = 3;
		}
	}
	else if ((PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[2].card_value == PlayerHand[3].card_value) ||
		(PlayerHand[0].card_value == PlayerHand[1].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value) ||
		(PlayerHand[1].card_value == PlayerHand[2].card_value && PlayerHand[3].card_value == PlayerHand[4].card_value))
	{
		cout << "\n CONGRATULATIONS TWO PAIR";
		cout << "\n --You win 2x your bet!--";
		cout << "\n\n Won this hand: " << 2 * current_bet << endl;
		total_credits += (2 * current_bet);

		if (biggest_win < 2)
		{
			biggest_win = 2;
		}
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

		if (biggest_win < 1)
		{
			biggest_win = 1;
		}
	}
	else
	{
		cout << "\n\n\n\n\n";
	}

	if (total_credits > max_credits)
	{
		max_credits = total_credits;
	}
}
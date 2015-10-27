/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			10/25/2015
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
	Record(int in_cheat, int in_score, int in_win,
		std::string in_initials, time_t in_date);
	~Record();

	int getCheat();
	int getScore();
	int getWin();
	std::string getInitials();
	time_t getDate();

	void setCheat(int input_cheat);
	void setScore(int input_score);
	void setWin(int input_win);
	void setInitials(std::string input_initials);
	void setDate(time_t input_date);

	Record* nextRecordNode;

private:

	char initials[MAX_INITIALS_LENGTH]; // stored as char array rather than string for writing to file.
	int cheat;
	int score;
	int win;
	time_t date;

} *headRecordNode = NULL;

Record::Record()
{

}

Record::Record(int in_cheat, int in_score, int in_win,
	std::string in_initials, time_t in_date)
{
	cheat = in_cheat;
	score = in_score;
	win = in_win;
	std::strcpy(initials, in_initials.c_str());
	date = in_date;
}

Record::~Record()
{

}

int Record::getCheat()
{
	return cheat;
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

void Record::setCheat(int input_cheat)
{
	cheat = input_cheat;
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
int cheater = 0;
int biggest_win = 0;
int max_credits = ONE_THOUSAND;

// FORWARD DECLARATIONS
void branchingMenu(char char_user_input);
void buildDeck();
void changeBet();
void changeCards();
void cheatCode();
void cleanReset();
void continuePrompt();
void dealHand();
void discardCard(int position);
void freePointer(Record* node);
std::string getInitialsFromUser();
void highScoresAdd();
void highScoresAddPreset(int cheat, int score, int win, std::string initials, time_t date);
void highScoresBuilder();
void highScoresCreateList(int in_cheat, int in_score, int in_win, std::string in_initials, time_t in_date);
void highScoresLoad();
void highScoresPrintDate(Record* pointer);
void highScoresSave();
void highScoresView();
void mainMenu();
std::string orderPrizes(int tier);
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
			std::cout << "\n You do not have enough credits to continue!\n";
			purchaseCredits();
		}
		else if (current_bet > total_credits)
		{
			std::cout << "\n You cannot bet that much.";
			std::cout << "\n Please change your current bet.\n";
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
		std::cout << "\n\n Branching invalid input. \n";
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

	std::cout << "\n Total Credits: " << total_credits;
	std::cout << "\n\n What would you like your bet to be? ---> ";
	std::cin >> changeBet;

	if (changeBet < MINIMUM_BET)
	{
		std::cout << "\n You must bet at least " << MINIMUM_BET << " credits.";
	}
	else if (changeBet > total_credits)
	{
		std::cout << "\n You do not have enough credits to bet " << changeBet << ".";
	}
	else if (changeBet > MAXIMUM_BET)
	{
		std::cout << "\n You cannot bet more than " << MAXIMUM_BET << " credits.";
	}
	else
	{
		current_bet = changeBet;
		std::cout << "\n Current bet successfully changed to " << current_bet << ".";
	}

	cleanReset();
}

void changeCards()
{
	// Swaps the user's original cards with new ones from the deck.

	int discard_digit, int_user_input;
	std::string truncated_user_string = "";
	std::string string_user_input = "";

	SetConsoleTextAttribute(screen, 249);
	std::cout << "\n\n\n\n\n\n Enter the numbers to discard ---> ";
	SetConsoleTextAttribute(screen, 240);

	getline(std::cin, string_user_input);
	truncated_user_string = string_user_input.substr(0, 5);
	std::stringstream convert(truncated_user_string);

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
		std::cout << "\nInvalid integer, please try again.\n";
	}

	int_user_input = 0;
	string_user_input = "";
}

void cheatCode()
{
	// If the cheat code is entered, give the user one million credits.
	// Shows "Cheats enabled" on high scores list when saved.

	cheater = 1;

	if (max_credits < ONE_MILLION)
	{
		max_credits = ONE_MILLION;
	}

	if (total_credits < ONE_MILLION)
	{
		total_credits = ONE_MILLION;
	}

	std::cout << "\n Secret Cheat Screen";
	std::cout << "\n -------------------";
	std::cout << "\n\n Total Credits set to 1,000,000!";

	cleanReset();
}

void cleanReset()
{
	// Waits for the user to enter something, then returns to the main menu.

	std::cout << "\n\n Press enter to continue ---> ";
	flushBuffer();
	clearScreen();
	mainMenu();
}

void continuePrompt()
{
	// If the user hits enter it continues gameplay, otherwise it will escape to the main menu.

	char continue_if_newline;

	std::cout << "\n Press enter to continue ---> ";
	continue_if_newline = getchar();

	clearScreen();

	if (continue_if_newline != '\n')
	{
		last_char = 'q';
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mainMenu();
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

std::string getInitialsFromUser()
{
	// Retrieves the user's initials, converts to uppercase, and returns a string of length 3.

	clearScreen();

	std::string initials = "";

	std::cout << "\n Please enter your initials ---> ";
	std::cin >> initials;

	initials = initials.substr(0, 3);
	initials.resize(3, ' ');

	transform(initials.begin(), initials.end(), initials.begin(), ::toupper);

	return initials;
}

void highScoresAdd()
{
	// Adds the user's current score and data to the high scores linked list.

	std::string name = getInitialsFromUser();
	time_t now = time(0);

	Record *add_pointer;
	Record *search_pointer = headRecordNode;
	Record **trail_pointer = &headRecordNode;

	add_pointer = (Record *)malloc(sizeof(Record));
	add_pointer->setCheat(cheater);
	add_pointer->setDate(now);
	add_pointer->setInitials(name);
	add_pointer->setScore(max_credits);
	add_pointer->setWin(biggest_win);

	if (add_pointer == NULL)
	{
		std::cout << "\n Out of memory! \n";
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

void highScoresAddPreset(int cheat, int score, int win, std::string initials, time_t date)
{
	// Similar to highScoresAdd() but constructs a high score list if there
	// is no file detected with data I manually placed into the game.

	Record *add_pointer;
	Record *search_pointer = headRecordNode;
	Record **trail_pointer = &headRecordNode;

	add_pointer = (Record *)malloc(sizeof(Record));
	add_pointer->setCheat(cheat);
	add_pointer->setDate(date);
	add_pointer->setInitials(initials);
	add_pointer->setScore(score);
	add_pointer->setWin(win);

	if (add_pointer == NULL)
	{
		std::cout << "\n Out of memory! \n";
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

void highScoresBuilder()
{
	// Builds a Linked List of High Scores if one does not already exist.
	// Lowest score first for fastest building.

	highScoresAddPreset(0, 1000, 0, "ASU", 1416000000);
	highScoresAddPreset(0, 1250, 1, "ODA", 1418000000);
	highScoresAddPreset(0, 1500, 1, "NDS", 1420000000);
	highScoresAddPreset(0, 2000, 1, "ADA", 1422000000);
	highScoresAddPreset(0, 2500, 2, "MYD", 1424000000);
	highScoresAddPreset(0, 3000, 2, "FOR", 1426000000);
	highScoresAddPreset(0, 3500, 2, "LLO", 1428000000);
	highScoresAddPreset(0, 4000, 3, "ITE", 1430000000);
	highScoresAddPreset(0, 4500, 3, "ASC", 1432000000);
	highScoresAddPreset(0, 5000, 4, "ANM", 1434000000);
	highScoresAddPreset(0, 6000, 5, "BRI", 1436000000);
	highScoresAddPreset(0, 7000, 6, "DBY", 1438000000);
	highScoresAddPreset(0, 8000, 7, "ATE", 1440000000);
	highScoresAddPreset(0, 9000, 8, "CRE", 1442000000);
	highScoresAddPreset(0, 10000, 9, "BTM", 1443500000);
}

void highScoresCreateList(int in_cheat, int in_score, int in_win, std::string in_initials, time_t in_date)
{
	// Helper function which takes the data from highScoresLoad() and inserts it into a linked list.

	Record *newRecordNode;
	newRecordNode = new Record(in_cheat, in_score, in_win, in_initials, in_date);

	if (newRecordNode == NULL)
	{
		std::cout << "Out of Memory\n";
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

void highScoresPrintDate(Record* pointer)
{
	// Prints the date in a nice format for the high scores list.

	time_t date_node = pointer->getDate();
	tm convert_date = *localtime(&date_node);

	if (convert_date.tm_mon < 9)
	{
		std::cout << " ";
	}

	std::cout << convert_date.tm_mon + 1;

	if (convert_date.tm_mday < 10)
	{
		std::cout << "/0";
	}
	else
	{
		std::cout << "/";
	}

	std::cout << convert_date.tm_mday << "/" << convert_date.tm_year % 100;
}

void highScoresLoad()
{
	// Extracts the data from the high scores save file and puts it into a linked list.

	int cheat = 0;
	int score = 0;
	int win = 0;
	std::string cheat_string = "";
	std::string date_string = "";
	std::string initials = "";
	std::string score_string = "";
	std::string win_string = "";
	time_t date = 0;

	std::ifstream highScoresLoad(HIGH_SCORES);

	if (highScoresLoad.is_open())
	{
		std::string line;
		while (getline(highScoresLoad, line))
		{
			std::istringstream parsed(line);

			getline(parsed, cheat_string, ',');
			std::istringstream(cheat_string) >> cheat;

			getline(parsed, date_string, ',');
			std::istringstream(date_string) >> date;

			getline(parsed, initials, ',');

			getline(parsed, score_string, ',');
			std::istringstream(score_string) >> score;

			getline(parsed, win_string, ',');
			std::istringstream(win_string) >> win;

			highScoresCreateList(cheat, score, win, initials, date);
		}
	}
	else
	{
		highScoresBuilder();
	}

	highScoresLoad.close();
}

void highScoresSave()
{
	// Saves the high scores to the file.

	FILE *fileName;
	Record *node;

	char *cheat_converted = new char[1];
	char *date_converted = new char[10];
	char *initials_converted = new char[MAX_INITIALS_LENGTH];
	char *score_converted = new char[MAX_SCORE_LENGTH];
	char *win_converted = new char[1];

	int counter = 0;
	std::string string_holder = "";

	fileName = fopen(HIGH_SCORES, "wb");

	if (fileName != NULL)
	{
		node = headRecordNode;
		while (node != NULL && counter < 15)
		{
			// Limits output file to 15 lines.
			// This is good because it is a save file.

			string_holder = std::to_string(node->getCheat());
			std::strcpy(cheat_converted, string_holder.c_str());
			fwrite(cheat_converted, string_holder.length(), 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			string_holder = std::to_string(node->getDate());
			std::strcpy(date_converted, string_holder.c_str());
			fwrite(date_converted, string_holder.length(), 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			string_holder = node->getInitials();
			std::strcpy(initials_converted, string_holder.c_str());
			fwrite(initials_converted, string_holder.length(), 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			string_holder = std::to_string(node->getScore());
			std::strcpy(score_converted, string_holder.c_str());
			fwrite(score_converted, string_holder.length(), 1, fileName);

			fwrite(",", sizeof(','), 1, fileName);

			string_holder = std::to_string(node->getWin());
			std::strcpy(win_converted, string_holder.c_str());
			fwrite(win_converted, string_holder.length(), 1, fileName);

			node = node->nextRecordNode;
			fwrite("\n", sizeof('\n'), 1, fileName);
			counter++;
		}
	}
	else
	{
		std::cout << "\n ERROR: Could not open file for saving data ! \n";
	}
}

void highScoresView()
{
	// Displays a list of the high scores for the user.

	Record *view_pointer = headRecordNode;

	if (view_pointer == NULL)
	{
		std::cout << "\n No Records Found.";
	}
	else
	{
		int counter = 1;

		std::cout << "\n                              High Scores!!!";
		std::cout << "\n ------------------------------------------------------------------------";
		std::cout << "\n\n  Initials | High Score | Best Hand Earned | Date Won | Secret Column!!!\n";

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
				std::cout << "\n    " << counter << ") ";
			}
			else
			{
				std::cout << "\n   " << counter << ") ";
			}

			std::cout << view_pointer->getInitials() << " | ";
			std::cout << std::setw(MAX_SCORE_LENGTH) << view_pointer->getScore() << " | ";
			std::cout << std::setw(MAX_WIN_LENGTH) << orderPrizes(view_pointer->getWin()) << " | ";

			highScoresPrintDate(view_pointer);

			if (view_pointer->getCheat() == 1)
			{
				std::cout << " | Cheats enabled!! ";
			}
			else
			{
				std::cout << " |                  ";
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
	std::string string_user_input = "";
	last_char = ' ';

	std::cout << "\n Welcome to Brian's Five Card Draw!!!";
	std::cout << "\n\n -------------\t\tTotal Credits: " << total_credits;
	std::cout << "\n   Main Menu";
	std::cout << "\n -------------\t\t  Current Bet: " << current_bet;
	std::cout << "\n\n P) Play 5 Card Draw";
	std::cout << "\n B) Buy More Credits";
	std::cout << "\n C) Change Current Bet";
	std::cout << "\n H) How to Play";
	std::cout << "\n L) List the Prizes";
	std::cout << "\n S) Show the Rules";
	std::cout << "\n V) View the High Scores";
	std::cout << "\n Q) Quit";
	std::cout << "\n\n Please enter a choice ---> ";

	std::cin >> string_user_input;
	char_user_input = string_user_input.at(0);
	char_user_input = tolower(char_user_input);
	last_char = char_user_input;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clearScreen();

	if (string_user_input == "Cheato")
	{
		cheatCode();
	}
	else if (char_user_input == 'b' || char_user_input == 'c' || char_user_input == 'h' ||
		char_user_input == 'l' || char_user_input == 'p' || char_user_input == 's' ||
		char_user_input == 'v')
	{
		srand(unsigned(time(NULL)));
		branchingMenu(char_user_input);
	}
	else if (char_user_input == 'q')
	{

	}
	else {
		std::cout << "\n Please enter a letter corresponding to a menu option.\n";
		mainMenu();
	}
}

std::string orderPrizes(int tier)
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

		std::cout << "\n ------------\t\tTotal Credits: " << total_credits;
		std::cout << "\n   New Hand";
		std::cout << "\n ------------\t\t  Current Bet: " << current_bet << "\n";

		SetConsoleTextAttribute(screen, 240);
	}
	else
	{
		std::cout << "\n --------------------\tTotal Credits: " << total_credits;
		std::cout << "\n   After Discarding";
		std::cout << "\n --------------------\t  Current Bet: " << current_bet << "\n";
	}

	initial = !initial;

	for (print_index = 0; print_index < HAND_SIZE; print_index++)
	{
		if (suit_names[PlayerHand[print_index].suit_letter] == "Diamonds" || suit_names[PlayerHand[print_index].suit_letter] == "Hearts")
		{
			SetConsoleTextAttribute(screen, 252);
		}

		if (PlayerHand[print_index].card_value == 10)
			std::cout << "\n " << print_index + 1 << ")  10 " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		else if (PlayerHand[print_index].card_value == 11)
			std::cout << "\n " << print_index + 1 << ")  J  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		else if (PlayerHand[print_index].card_value == 12)
			std::cout << "\n " << print_index + 1 << ")  Q  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		else if (PlayerHand[print_index].card_value == 13)
			std::cout << "\n " << print_index + 1 << ")  K  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		else if (PlayerHand[print_index].card_value == 14)
			std::cout << "\n " << print_index + 1 << ")  A  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		else
			std::cout << "\n " << print_index + 1 << ")  " << PlayerHand[print_index].card_value << "  " << suit_symbols[PlayerHand[print_index].suit_letter] << " " << suit_names[PlayerHand[print_index].suit_letter] << "\n";
		if (print_index == 4)
			std::cout << "\n";

		SetConsoleTextAttribute(screen, 240);
	}
}

void printHowToPlay()
{
	// Displays the guide to the user.

	std::cout << "\n How to Play";
	std::cout << "\n -----------";
	std::cout << "\n\n After selecting play from the menu you will be dealt five cards.";
	std::cout << "\n Enter the numbers that correspond with the cards in your hand";
	std::cout << "\n that you would like to draw, and you will be dealt new cards based";
	std::cout << "\n on what you entered. If you have a winning hand, you will earn credits.";
	std::cout << "\n If you lose, your bet will be subtracted from your total credits.";
	std::cout << "\n After each hand is played, you will be returned to the main menu.";
	std::cout << "\n\n Good luck and have fun!!!";
	cleanReset();
}

void printPrizes()
{
	// Displays the prize tiers for the user.

	std::cout << "\n Prize Pool";
	std::cout << "\n ----------";
	std::cout << "\n\n Winning name: Multiple of amount bet\n";
	std::cout << "\n Royal flush:\t  5000";
	std::cout << "\n Straight flush:  500";
	std::cout << "\n Four of a kind:  150";
	std::cout << "\n Full house:\t  75";
	std::cout << "\n Flush:\t\t  50";
	std::cout << "\n Straight:\t  20";
	std::cout << "\n Three of a kind: 5";
	std::cout << "\n Two pair:\t  2";
	std::cout << "\n Jacks or better: 1";
	cleanReset();
}

void printRules()
{
	// Displays the rules set to the user.

	std::cout << "\n Rules";
	std::cout << "\n -----";
	std::cout << "\n\n The minimum bet is " << MINIMUM_BET << " credits.";
	std::cout << "\n The maximum bet is " << MAXIMUM_BET << " credits.";
	std::cout << "\n\n If your credit balance falls below the minimum bet, ";
	std::cout << "\n you must add more to continue playing.";
	cleanReset();
}

void purchaseCredits()
{
	// Allows the user to buy more credits if they have fallen under 1000.

	int add_credits;

	if (total_credits >= 1000)
	{
		std::cout << "\n You may only add to your balance if you are below " << ONE_THOUSAND << " credits.";
	}
	else
	{
		std::cout << "\n You may currently add up to " << ONE_THOUSAND - total_credits << " credits.";
		std::cout << "\n\n How many credits would you like to buy? ---> ";
		std::cin >> add_credits;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n User input not an integer.";
		}
		else
		{
			if (add_credits < 1)
			{
				std::cout << "\n You may only add a positive credit amount.";
			}
			else if (add_credits < (MINIMUM_BET - total_credits))
			{
				std::cout << "\n You must buy enough credits to play at least once!";
			}
			else if (add_credits >(ONE_THOUSAND - total_credits))
			{
				std::cout << "\n You may only buy up to " << ONE_THOUSAND << " credits.";
			}
			else
			{
				total_credits += add_credits;
				std::cout << "\n Total credits is now " << total_credits << ".";
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

		std::swap(PlayerHand[start_index].card_value, PlayerHand[smallest_index].card_value);
		std::swap(PlayerHand[start_index].suit_letter, PlayerHand[smallest_index].suit_letter);
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
		std::cout << "\n CONGRATULATIONS ROYAL FLUSH!!";
		std::cout << "\n ---You win 5000x your bet!---";
		std::cout << "\n\n Won this hand: " << 5000 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS STRAIGHT FLUSH!";
		std::cout << "\n ----You win 500x your bet!----";
		std::cout << "\n\n Won this hand: " << 500 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS FOUR OF A KIND!";
		std::cout << "\n ----You win 150x your bet!!----";
		std::cout << "\n\n Won this hand: " << 150 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS FULL HOUSE!";
		std::cout << "\n ---You win 75x your bet!---";
		std::cout << "\n\n Won this hand: " << 75 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS FLUSH!!";
		std::cout << "\n -You win 50x your bet!-";
		std::cout << "\n\n Won this hand: " << 50 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS STRAIGHT!";
		std::cout << "\n --You win 20x your bet!--";
		std::cout << "\n\n Won this hand: " << 20 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS THREE OF A KIND!";
		std::cout << "\n ------You win 5x your bet!------";
		std::cout << "\n\n Won this hand: " << 5 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS TWO PAIR";
		std::cout << "\n --You win 2x your bet!--";
		std::cout << "\n\n Won this hand: " << 2 * current_bet << "\n";
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
		std::cout << "\n CONGRATULATIONS JACKS OR BETTER!";
		std::cout << "\n ------You win 1x your bet!------";
		std::cout << "\n\n Won this hand: " << current_bet << "\n";
		total_credits += current_bet;

		if (biggest_win < 1)
		{
			biggest_win = 1;
		}
	}
	else
	{
		std::cout << "\n\n\n\n\n";
	}

	if (total_credits > max_credits)
	{
		max_credits = total_credits;
	}
}
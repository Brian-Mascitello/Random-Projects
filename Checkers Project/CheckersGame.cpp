//3-Player Checkers
//By Shivaan Kulanathan, Jonathan Martin, and Brian Mascitello
//CSE 240 - Mr. Wing Cheng
//11/9/2013


#define sgn(x) ((x>0)-(x<0))

#include "consoleutil.h"
#include <cmath>
#include <iostream>
#include <string>

bool game_running();
bool play_or_quit = true;

#define ascii_0_value 48
#define ascii_A_value 65
#define ascii_a_value 97
#define board_row_draw_size 24
#define board_column_draw_size 33
#define GAME_DIMENSION 9
#define NUM_ROWS 2
#define NUM_PLAYERS 3
const char PIECE_LOOKUP[2][4] = {{' ','r','b','g'},{' ','R','B','G'}};

//int take_user_board_input();
int turn_counter = 0;

typedef enum Color{non_color, red, black, green};
Color winning_color;
Color player_colors[NUM_PLAYERS] = {red,black,green};

using namespace std;

void main_menu();
void print_board();
void print_piece(int i,int j);
void update_board();
int take_user_board_input();
bool is_eliminated(Color shade);

class Piece
{
	protected:
		bool kinged;
		bool special;
		Color shade;
		int cd;
		int column;
		int life;
		int rd;
		int row;

	public:
		Color get_color();
		bool get_kinged();
		bool has_special();
		int get_rd();
		int get_cd();
		int get_life();
		int jump_piece(int r, int c);
		int move_piece(int r, int c);
		Piece(int r, int c, int rd, int cd);
		//~Piece();
		void black_take_damage();
		void king_piece();
		void take_damage();
		void use_special();
		void set_color(Color color);
		int green_piece_special(int r, int c);

}; //end class Piece

Piece* create_piece(Color,int,int,int,int);
Piece* game_board[GAME_DIMENSION][GAME_DIMENSION];

class Black_Piece : public Piece
{
	public:
		Black_Piece(int row, int column, int rd, int cd);
}; //end class Black_Piece : public Piece

class Green_Piece : public Piece
{
	public:
		Green_Piece(int r, int c, int rd, int cd, bool special);
}; //end class Green_Piece : public Piece

class Red_Piece : public Piece
{
	public:
		Red_Piece(int r, int c, int rd, int cd);
}; //end class Red_Piece : public Piece

//struct Piece_Node
//{
//	Color shade;
//	Piece_Node *next;
//};

/*void add_Piece_Node(Piece new_piece, Piece_Node* color_list)
{
	struct Piece_Node *head = (struct Piece_Node *)malloc(sizeof(struct Piece_node);
	struct Piece_Node *temp;

	head -> shade = new_piece.get_color();

	if(color_list == NULL)
	{
		color_list = head;
	}

	temp = color_list;

	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}

	temp -> next = head;
}

void delete_Piece_Node(Piece_Node* color_list)
{
	struct Piece_Node* temp = color_list;
	if(temp == NULL)
		return;
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		delete(temp);
	}
}


struct Piece_Node* red_list = NULL;
struct Piece_Node* black_list = NULL;
struct Piece_Node* green_list = NULL;
*/
int main()
{
	//Prompt color assignments
	//Initialization of game board

	main_menu();

	while(play_or_quit)
	{

		int int_letter = (ascii_A_value - 1);
		int int_number = ascii_0_value;
		for(int y = 0; y < (board_row_draw_size - 1); y++)
		{
			for(int x = 0; x < 2; x++)
			{
				if(x == 1 && y%2 == 1)
				{
					char char_letter = (char)(int_letter);
					print_char(x, y, char_letter);
					print_char((board_column_draw_size - 2 - x), y, char_letter);
					int_letter++;
				}

				else
				{
					print_char(x, y, ' ');
					print_char((board_column_draw_size - 2 - x), y, ' ');
				}
			}
		}

		for(int x = 0; x < (board_column_draw_size - 1); x++)
		{
			for(int y = 0; y < 2; y++)
			{
				if(y == 1 && x%3 == 0 && x>1 && x<29)
				{
					print_char(x,y,' ');
				}

				else if(y == 1 && x%3 == 1 && x>1 && x<29)
				{
					char char_number = (char)(int_number);
					print_char(x, y, char_number);
					print_char(x, (board_row_draw_size - 2 - y), char_number);
					int_number++;
				}

				else
				{
					print_char(x, y, ' ');
					print_char(x, (board_row_draw_size - 2 - y), ' ');
				}
			}
		}

		for(int x = 2; x < (board_column_draw_size - 3); x++)
		{
			for(int y = 2; y < (board_row_draw_size - 3); y+=2)
			{
				if(x%3 == 2)
				{
					print_char(x, y, '+');
				}
				else
				{
					print_char(x, y, '-');
				}
			}
		}

		for(int x = 2; x < (board_column_draw_size - 3); x+=3)
		{
			for(int y = 3; y < (board_row_draw_size - 3); y+=2)
			{
				print_char(x, y, '|');
			}
		}

		for(int i = 0;i < NUM_ROWS; i++)
		{
			for(int j = (i%2)+1; j < GAME_DIMENSION - 1; j+=2)
			{
				game_board[i][j] = create_piece(player_colors[0],i,j,1,0);
				game_board[GAME_DIMENSION-1-i][j] = create_piece(player_colors[1],GAME_DIMENSION-1-i,j,-1,0);
				if(NUM_PLAYERS < 3)
				{
					continue;
				}
				game_board[j][i] = create_piece(player_colors[2],j,i,0,1);
			}
		}

/////////Game Loop
		update_board();
		while(game_running())
		{
			if(is_eliminated(player_colors[turn_counter]))
				turn_counter = (turn_counter+1) % NUM_PLAYERS;
			if(take_user_board_input() == -1)
			continue;
			turn_counter = (turn_counter+1) % NUM_PLAYERS;
			update_board();
		}
//////Declaring a winner
		if(winning_color == non_color)
			print_to_row(board_row_draw_size - 2, "Tie game!");
		if(winning_color == red)
			print_to_row(board_row_draw_size - 2, "Red is the winner!");
		if(winning_color == black)
			print_to_row(board_row_draw_size - 2, "Black is the winner!");
		if(winning_color == green)
			print_to_row(board_row_draw_size - 2, "Green is the winner!");
		print_to_row(board_row_draw_size - 1, "Enter any non-empty field to continue...");
		std::string temp;
		cin >> temp;
		for(int i = 0; i < GAME_DIMENSION; i++)
			for(int j = 0; j < GAME_DIMENSION; j++)
			{
				if(game_board[i][j] == NULL)
					continue;
				delete game_board[i][j];
				game_board[i][j] = NULL;
			}
		main_menu();
	}//end while loop

}; //end int main()

bool is_eliminated(Color shade)
{
	for(int i = 0; i < GAME_DIMENSION; i++)
		for(int j = 0; j < GAME_DIMENSION; j++)
		{
			if(game_board[i][j] == NULL)
				continue;
			if((*game_board[i][j]).get_color() == shade)
				return false;
		}
	return true;
};

bool game_running()
{
	winning_color = non_color;	//winning_color is global so that it will indicate winner when game loop ends

	for(int i = 0; i < GAME_DIMENSION; i++)
	{
		for(int j = 0; j < GAME_DIMENSION; j++)
		{
			if(game_board[i][j] != NULL)		//Only consider nonempty squares
			{
				if(winning_color == non_color)
				{
					winning_color = (*game_board[i][j]).get_color();
				}
				else if((*game_board[i][j]).get_color() != winning_color)
				{
					return true;				//If two or more colors of piece are still present,
				}
			}
		}
	}
	return false; //if board only contains one type of piece, then game has ended and winning_color is the winner
}; //end bool game_running()

Piece* create_piece(Color piece_color,int i,int j,int id,int jd)
{
	switch(piece_color)
	{
		case red:
			return new Red_Piece(i,j,id,jd);
//			add_Piece_Node(new Red_Piece(i,j,id,jd), red_list);
			break;

		case black:
			return new Black_Piece(i,j,id,jd);
//			add_Piece_Node(new Black_Piece(i,j,id,jd), black_list);
			break;

		case green:
			return new Green_Piece(i,j,id,jd,true);
//			add_Piece_Node(new Green_Piece(i,j,id,jd), green_list);
			break;
	}
	return NULL;
}; //end Piece* create_piece(Color piece_color,int i,int j,int id,int jd)

void main_menu()
{
	char menu_select_char, wiper[83];

	for(int blank = 0; blank < 80; blank++)
	{
		wiper[blank] = ' ';
	}

	wiper[81] = '\0';

	for(int clear_column = 0; clear_column<31; clear_column++)
	{
		print_to_row(clear_column,wiper);
	}

	print_to_row(1, "Welcome to Titanic Checkers");
	print_to_row(3, "Player 1 = Red 'R' and 'r' pieces");
	print_to_row(4, "Player 2 = Black 'b' pieces");
	print_to_row(5, "Player 3 = Green 'G' and 'g' pieces");
	print_to_row(7, "Move a piece by selecting entering its row and column,");
	print_to_row(8, "then enter its destination the same way!");
	print_to_row(9, "Typing in 'E3' or 'e3'");
	print_to_row(10, "Will select the piece on row E column 3");
	print_to_row(12, "Would you like to play checkers?");
	print_to_row(13, "Please enter Y to play a game, or N to quit: ");

	do
	{
		std::string menu_select_str;

		cin >> menu_select_str;
		menu_select_char = tolower(menu_select_str[0]);
	}
	while(menu_select_char != 'y' && menu_select_char != 'n');

	if(menu_select_char == 'y')
	{
		for(int clear_column = 0; clear_column<31; clear_column++)
		{
			print_to_row(clear_column,wiper);
		}
	}

	if(menu_select_char == 'n')
	{
		play_or_quit = false;
	}

} //end void display_menu()

void update_board()
{
	for(int i = 0; i < GAME_DIMENSION; i++)
	{
		for(int j = 0; j < GAME_DIMENSION; j++)
		{
			if(game_board[i][j] == NULL)
			{
				continue;
			}
			if((*game_board[i][j]).get_life() <= 0)
			{
/*				switch(*gameboard[i][j]).get_color())
				{
					case red:
						delete_Piece_Node(red_list);
						break;
					case black:
						delete_Piece_Node(black_list);
						break;
					case green:
						delete_Piece_Node(green_list);
						break;
				}
				*/
				delete (game_board[i][j]);
				game_board[i][j] = NULL;
			}
		}
	}
	print_board();
}; //end void update_board()

void print_board()
{
	for(int i = 0; i < GAME_DIMENSION; i++)
	{
		for(int j = 0; j < GAME_DIMENSION; j++)
		{
			print_piece(i,j);
		}
	}
}; //end void print_board()

void print_piece(int i, int j)
{
	Piece* p = game_board[i][j];

	if(p == NULL)
	{
		print_char(3*j+3,2*i+3,' ');
		print_char(3*j+3+1,2*i+3,' ');
		return;
	}

	print_char(3*j+3,2*i+3,PIECE_LOOKUP[(*p).has_special() || (*p).get_life() == 2][(*p).get_color()]);

	if((*p).get_kinged())
	{
		print_char(3*j+3+1,2*i+3,'K');
	}
	else
	{
		print_char(3*j+3+1,2*i+3,' ');
	}
}; //end void print_piece(int i, int j)

int take_user_board_input() //expects a letter and number entered like A2 or a2
{
	char input_buffer_char, input_buffer_char_2;
	char player_say[34] = "Please select a piece to move. ";
	char player_final[50];

	int char_int_value, second_coord_value;
	int char_int_value_2, second_coord_value_2;

	std::string input_buffer_string;
	std::string input_buffer_string_2;
	//Try to signal the player whose turn it is by using turn value and enum color.

	if(turn_counter == 0)
	{
		char player_color[15] = "RED PLAYER 1: ";
		for(int first = 0; first < 14; first++)
		{
			player_final[first] = player_color[first];
		}
		for(int last = 0; last < 33; last++)
		{
			player_final[last+14] = player_say[last];
		}
		player_final[47]='\0';
	}

	else if(turn_counter == 1)
	{
		char player_color[17] = "BLACK PLAYER 2: ";
		for(int first = 0; first < 16; first++)
		{
			player_final[first] = player_color[first];
		}
		for(int last = 0; last < 35; last++)
		{
			player_final[last+16] = player_say[last];
		}
		player_final[49]='\0';
	}

	else
	{
		char player_color[17] = "GREEN PLAYER 3: ";
		for(int first = 0; first < 16; first++)
		{
			player_final[first] = player_color[first];
		}
		for(int last = 0; last < 35; last++)
		{
			player_final[last+16] = player_say[last];
		}
		player_final[49]='\0';
	}

	print_to_row(board_row_draw_size-2,player_final);
	cin >> input_buffer_string;

	if(input_buffer_string.length() != 2)
	{
		print_to_row(board_row_draw_size-1,"That is not a valid set of coordinates.");
		return -1;
	}

	input_buffer_char = tolower(input_buffer_string[0]);
	second_coord_value = ((int)input_buffer_string[1] - ascii_0_value);
	char_int_value = (((int)input_buffer_char) - ascii_a_value);

	if(char_int_value < 0 || char_int_value > (GAME_DIMENSION - 1))
	{
		print_to_row(board_row_draw_size-1,"This set of coordinates is not on the board");
		return -1;
	}
	if(game_board[char_int_value][second_coord_value] == NULL)
	{
		print_to_row(board_row_draw_size-1,"There is no piece there.");
		return -1;
	}

	if(second_coord_value < 0 || second_coord_value > (GAME_DIMENSION - 1))
	{
		print_to_row(board_row_draw_size-1,"This set of coordinates is not on the board");
		return -1;
	}

	if((*game_board[char_int_value][second_coord_value]).get_color() != player_colors[turn_counter])
	{
		print_to_row(board_row_draw_size-1,"It is not that player's turn.");
		return -1;
	}

	print_to_row(board_row_draw_size-1,"Please enter the where you would like to move. ");
	cin >> input_buffer_string_2;

	if(input_buffer_string_2.length() != 2)
	{
		print_to_row(board_row_draw_size-1,"That is not a valid set of coordinates.");
		return -1;
	}

	input_buffer_char_2 = tolower(input_buffer_string_2[0]);
	second_coord_value_2 = ((int)input_buffer_string_2[1] - ascii_0_value);
	char_int_value_2 = ((int)input_buffer_char_2 - ascii_a_value);

	if(char_int_value_2 < 0 || char_int_value_2 > (GAME_DIMENSION - 1))
	{
		return -1;
	}

	if(second_coord_value_2 < 0 || second_coord_value_2 > (GAME_DIMENSION - 1))
	{
		print_to_row(board_row_draw_size-1,"This set of coordinates is not on the board");
		return -1;
	}

	bool jumping = abs(char_int_value-char_int_value_2) > 1 || abs(second_coord_value-second_coord_value_2) > 1;

	if(player_colors[turn_counter] != green || !(*game_board[char_int_value][second_coord_value]).has_special() || jumping)
	{
		if ((*game_board[char_int_value][second_coord_value]).move_piece(char_int_value_2, second_coord_value_2) == -1)
		{
			print_to_row(board_row_draw_size-1,"Not a valid move.");
			return -1;
		}
		else
		{
			print_to_row(board_row_draw_size-1,"Move successful!");
			return 0;
		}
	}

	char special_answer;

	do
	{
		print_to_row(board_row_draw_size-1,"This piece may copy itself. Would you like to use this special? (Y/N)\t");
		std::string temp;
		cin >> temp;
		special_answer = tolower(temp[0]);
	}
	while(special_answer != 'y' && special_answer != 'n');

	if(special_answer == 'y')
	{
		if ((*game_board[char_int_value][second_coord_value]).green_piece_special(char_int_value_2, second_coord_value_2) == -1)
		{
			print_to_row(board_row_draw_size-1,"Not a valid move.");
			return -1;
		}
		else
		{
			print_to_row(board_row_draw_size-1,"Move successful!");
			return 0;
		}
	}

	if ((*game_board[char_int_value][second_coord_value]).move_piece(char_int_value_2, second_coord_value_2) == -1)
	{
		print_to_row(board_row_draw_size-1,"Not a valid move.");
		return -1;
	}
	else
	{
		print_to_row(board_row_draw_size-1,"Move successful!");
		return 0;
	}

}; //int take_user_board_input()

Piece::Piece(int row, int column, int rd, int cd)
{
	(*this).row = row;
	(*this).column = column;
	(*this).rd = rd;
	(*this).cd = cd;
	kinged = false;
	special = false;
	life = 1;
}; //end Piece::Piece(int row, int column, int rd, int cd)

Color Piece::get_color()
{
	return shade;
}; //end Color Piece::get_color()

void Piece::set_color(Color color)
{
	shade = color;
}; //end void Piece::set_color(Color color)

int Piece::move_piece(int r, int c)
{
	if((r < 0 || r > (GAME_DIMENSION - 1)) || (c < 0 || c > (GAME_DIMENSION - 1))) //destination on gameboard
		return -1;

	if(game_board[r][c] != NULL) //destination is empty thus available for movement
		return -1;

	if(abs(row-r) > 2 || abs(column-c) > 2) //desired square is no more than two in any direction
		return -1;

	if((abs(row-r) == 1 && abs(column-c) == 2) || (abs(row-r) == 2 && abs(column-c) == 1)) //prevents the piece from ever moving like a knight in chess
		return -1;

	if(!kinged) //addtional restrictions for pawns
	{
		if(abs(row-r) != abs(column-c)) //forces diagonal movement from the current space
			return -1;

		if(rd !=0 && sgn(r-row) != rd) //checks that the piece is moving in an allowed direction
			return -1;

		if(cd !=0 && sgn(c-column) != cd) //checks that the piece is moving in an allowed direction
			return -1;
	}

	if(abs(row-r) == 1 || abs(column-c) == 1) //actually moves the piece if conditions are met
	{
		game_board[row][column] = NULL;
		game_board[r][c] = this;
		row = r;
		column = c;
	if(rd*(row+1+rd)*(GAME_DIMENSION-1-rd*row) == 0 && cd*(column+1+cd)*(GAME_DIMENSION-1-cd*column) == 0)
		kinged = true;
		return 0;
	}

	else
	{
		return jump_piece(r, c); //calls the jump function
	}
}; //end int Piece::move_piece(int r, int c)

int Piece::jump_piece(int r, int c)
{
	if(game_board[(row+r)/2][(column+c)/2] == NULL) //checks jumped square for a piece
		return -1;

	if((*game_board[(row+r)/2][(column+c)/2]).get_color() == (*this).get_color()) //makes sure piece is not jumping a teammate
		return -1;

	if((*game_board[(row+r)/2][(column+c)/2]).get_color() == black) //if piece being jumped is black, runs black_take_damage
		black_take_damage();

	(*game_board[(row+r)/2][(column+c)/2]).take_damage(); //deals damage to the jumped piece

	game_board[row][column] = NULL;
	game_board[r][c] = this;
	row = r;
	column = c;
	if(rd*(row+1+rd)*(GAME_DIMENSION-1-rd*row) == 0 && cd*(column+1+cd)*(GAME_DIMENSION-1-cd*column) == 0)
		kinged = true;
	return 0;
}; //end int Piece::jump_piece(int r, int c)

void Piece::black_take_damage()
{
	if(rand() % 2) //if the random remainder is one, the jumping piece takes damage
		(*game_board[row][column]).take_damage();
}; //end void Piece::black_take_damage()

void Piece::king_piece()
{
	kinged = true;
}; //end void Piece::king_piece()

bool Piece::get_kinged()
{
	return kinged;
}; //end bool Piece::get_kinged()

int Piece::get_life()
{
	return life;
}; //end int Piece::get_life()

void Piece::take_damage()
{
	life--;
}; //end void Piece::take_damage()

int Piece::get_rd()
{
	return rd;
}; //end int Piece::get_rd()

int Piece::get_cd()
{
	return cd;
}; //end int Piece::get_cd()

bool Piece::has_special()
{
	return special;
}; //end bool Piece::has_special()

int Piece::green_piece_special(int r, int c)
{
	int tempr = row, tempc = column;
	if(!special)
		return -1;
	if(move_piece(r, c) == 0)
	{
		game_board[tempr][tempc] = new Green_Piece(tempr, tempc, get_rd(), get_cd(), false);
		special = false;
		if(kinged)
			(*game_board[tempr][tempc]).king_piece();
		return 0;
	}

	return -1;
}; //end int Piece::green_piece_special(int r, int c)

Red_Piece::Red_Piece(int r, int c, int rd, int cd) : Piece(r, c, rd, cd)
{
	set_color(red);
	life = 2;
}; //end Red_Piece::Red_Piece(int r, int c, int rd, int cd) : Piece(r, c, rd, cd)

Green_Piece::Green_Piece(int r, int c, int rd, int cd, bool special) : Piece (r, c, rd, cd)
{
	set_color(green);
	(*this).special = special;
}; //end Green_Piece::Green_Piece(int r, int c, int rd, int cd, bool special) : Piece (r, c, rd, cd)

Black_Piece::Black_Piece(int row, int column, int rd, int cd) : Piece (row, column, rd, cd)
{
	set_color(black);
}; //end Black_Piece::Black_Piece(int row, int column, int rd, int cd) : Piece (row, column, rd, cd)
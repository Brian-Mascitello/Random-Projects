/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
EXERCISE:		P4.22
SPECIFICATION:	Java Practice - The game of Nim. This is a well-known game
	with a number of variants. The following variant has an interesting
	winning strategy. Two players alternately take marbles from a pile. In
	each move, a player chooses how many marbles to take. The player must
	take at least one but at most half of the marbles. Then the other
	player takes a turn. The player who takes the last marble loses. Write
	a program in which the computer plays against a human opponent.
	Generate a random integer between 10 and 100 to denote the initial
	size of the pile. Generate a random integer between 0 and 1 to decide
	whether the computer or the human takes the first turn. Generate a
	random integer between 0 and 1 to decide whether the computer plays
	smart or stupid. In stupid mode the computer simply takes a random
	legal value (between 1 and n/2) from the pile whenever it has a turn.
	In smart mode the computer takes off enough marbles to make the size
	of the pile a power of two minus 1—that is, 3, 7, 15, 31, or 63. That
	is always a legal move, except when the size of the pile is currently
	one less than a power of two. In that case, the computer makes a
	random legal move. You will note that the computer cannot be beaten in
	smart mode when it has the first move, unless the pile size happens to
	be 15, 31, or 63. Of course, a human player who has the first turn and
	knows the winning strategy can win against the computer.
-------------------------------------------------------------------------*/

import java.util.Random;
import java.util.Scanner;
public class Nim {
	public static void main(String[] args) {
		Random randomMaker = new Random();
		int firstTurn = randomMaker.nextInt(2); // Generates 0 or 1
		int initialSize = randomMaker.nextInt(91) + 10; // Generates 10 to 100
		int smartStupid = randomMaker.nextInt(2); // Generates 0 or 1
		welcomeMethod(firstTurn, initialSize, smartStupid);
		gamePlay(firstTurn, initialSize, smartStupid);
	}
	
	private static void gamePlay(int turn, int size, int intel) {
		int check = size;
		while (size > 0) {
			
			// all the moving happens
			if (turn == 0) {
				if (intel == 0) {
					size = moveSmart(size);
				} else {
					size = moveStupid(size);
				}
			} else {
				size = moveHuman(size);
			}
			
			// switch turns
			if (check != size) {
				if (turn == 0) {
					turn = 1;
				} else {
					turn = 0;
				}
				check = size;
			}
		}
		
		// winner
		if (turn == 0) {
			System.out.println("The computer wins!");
		} else {
			System.out.println("The human wins!");
		}
	} // end of gamePlay(int, int, int)

	private static int moveHuman(int size) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		System.out.println("The current board size is " + size + ".");
		if (size > 3) {
			System.out.print("Please enter a number between 1 and " + (size / 2) + ": ");
			int marbles = scan.nextInt();
			if (marbles < 1 || marbles > (size / 2)) {
				System.out.println("Invalid amount.");
			} else {
				return (size - marbles);
			}
		} else {
			System.out.print("Please enter the number 1: ");
			int marbles = scan.nextInt();
			if (marbles < 1 || marbles > 1) {
				System.out.println("Invalid amount.");
			} else {
				return (size - marbles);
			}
		}
		return size;
	}

	private static int moveSmart(int size) {
		int marbles = 1;
		if (size == 63 || size == 31 || size == 15 || size == 7 || size == 3) {
			Random think = new Random();
			marbles = think.nextInt(size / 2) + 1;
		} else if (size > 63) {
			marbles = size - 63;
		} else if (size > 31) {
			marbles = size - 31;
		} else if (size > 15) {
			marbles = size - 15;
		} else if (size > 7) {
			marbles = size - 7;
		} else if (size > 3) {
			marbles = size - 3;
		}
		System.out.println("The computer took " + marbles + " of " + size + " marbles.");
		return size - marbles;		
	} // end of moveSmart(int)
	
	private static int moveStupid(int size) {
		int marbles = 1;
		if (size > 3) {
			Random think = new Random();
			marbles = think.nextInt(size / 2) + 1; // Generates between 1 and size / 2
		}
		System.out.println("The computer took " + marbles + " of " + size + " marbles.");
		return size - marbles;		
	} // end of moveStupid(int)

	private static void welcomeMethod(int turn, int size, int intel) {
		System.out.println("Welcome to the Game of Nim!!!");
		System.out.println("The initial size of the pile is: " + size);
		
		if (intel == 0) {
			System.out.println("The computer is set to smart mode.");
		} else {
			System.out.println("The computer is set to stupid mode.");
		}
		
		if (turn == 0) {
			System.out.println("The computer gets to go first.");
		} else {
			System.out.println("You go first!");
		}
		
		if (intel == 0 && turn == 0 && (size != 15 || size != 31 || size != 63)) {
			System.out.println("*** Note this game should be unwinnable. ***");
		}
	} // end of welcomeMethod(int, int, int)
}
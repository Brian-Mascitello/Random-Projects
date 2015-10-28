/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
DATE:			10/28/2015
EXERCISE:		HelloWorld
SPECIFICATION:	Java Practice - Get a user name and age, then print it
	back to them.
-------------------------------------------------------------------------*/

import java.util.Scanner; // necessary for user input

public class HelloWorld {

	public static void main(String[] args) {
		
		int age = 0; // variable to store user's age
		String name = ""; // variable to store user's name

		System.out.println("Welcome to Hello World on Java");

		Scanner input = new Scanner(System.in); // opens a scanner called "input"
		
		System.out.print("Please enter your first name: ");
		name = input.nextLine();
		System.out.print("Please enter your age: ");
		age = input.nextInt();
		
		input.close(); // closes the scanner, only do this when inputs are done

		System.out.println("Hey " + name + ", hope " + age + " is a good year!");
	}
}
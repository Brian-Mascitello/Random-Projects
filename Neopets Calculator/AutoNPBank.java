//********************************************
// Name: Brian Mascitello
// Title: NPBank.java
// Description: Input Total NP, Output tells Account Type, Current Daily Gains, and NP until +1NP/day Interest
// Time spent: 2 hours
// Date: 9/18/2012
//********************************************

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;
//import javax.swing.*;

public class AutoNPBank
{
	public static void main(String[] args)
	{
		DecimalFormat format = new DecimalFormat("#");
		format.setRoundingMode(RoundingMode.UP);
		Scanner scan = new Scanner(System.in);

		double Balance;
		double Rate;
		double Daily;

		/*JFrame frame = new JFrame();

		final int FRAME_WIDTH = 300;
		final int FRAME_HEIGHT = 400;
		frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
		frame.setTitle("Automatic Neopoint Bank");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.setVisible(true);*/

		System.out.println( "Enter your Current Balance: " );
		Balance = scan.nextInt();
		Rate = 0;

		if ( 0 <= Balance && Balance < 1000 )
		{
			System.out.println( "\nAccount Type: \t \t Junior Saver" );
			Rate = 4.5;
			}

		if ( 1000 <= Balance && Balance < 2500 )
		{
			System.out.println( "\nAccount Type: \t \t Neopian Student" );
			Rate = 5.5;
			}

		if ( 2500 <= Balance && Balance < 5000 )
		{
			System.out.println( "\nAccount Type: \t \t Bronze Saver" );
			Rate = 6.0;
			}

		if ( 5000 <= Balance && Balance < 10000 )
		{
			System.out.println( "\nAccount Type: \t \t Silver Saver" );
			Rate = 6.5;
			}

		if ( 10000 <= Balance && Balance < 25000 )
		{
			System.out.println( "\nAccount Type: \t \t Super Gold Plus" );
			Rate = 7.0;
			}

		if ( 25000 <= Balance && Balance < 50000 )
		{
			System.out.println( "\nAccount Type: \t \t Platinum Extra" );
			Rate = 7.5;
			}

		if ( 50000 <= Balance && Balance < 75000 )
		{
			System.out.println( "\nAccount Type: \t \t Double Platinum" );
			Rate = 8.0;
			}

		if ( 75000 <= Balance && Balance < 100000 )
		{
			System.out.println( "\nAccount Type: \t \t Triple Platinum" );
			Rate = 8.5;
			}

		if ( 100000 <= Balance && Balance < 250000 )
		{
			System.out.println( "\nAccount Type: \t \t Diamond Deposit" );
			Rate = 9.0;
			}

		if ( 250000 <= Balance && Balance < 500000 )
		{
			System.out.println( "\nAccount Type: \t \t Diamond Deposit Plus" );
			Rate = 9.5;
			}

		if ( 500000 <= Balance && Balance < 1000000 )
		{
			System.out.println( "\nAccount Type: \t \t Diamond Deposit Gold" );
			Rate = 10.0;
			}

		if ( 1000000 <= Balance && Balance < 2000000 )
		{
			System.out.println( "\nAccount Type: \t \t Millionaire Platinum" );
			Rate = 10.5;
			}

		if ( 2000000 <= Balance && Balance < 5000000 )
		{
			System.out.println( "\nAccount Type: \t \t Millionaire Double Platinum" );
			Rate = 11.0;
			}

	 	if ( 5000000 <= Balance && Balance < 7500000 )
		{
			System.out.println( "\nAccount Type: \t \t Millionaire Mega-Platinum" );
			Rate = 11.5;
			}

		if ( 7500000 <= Balance && Balance < 10000000 )
		{
			System.out.println( "\nAccount Type: \t \t Neopian Mega-Riches" );
			Rate = 12.0;
			}

		if ( 10000000 <= Balance && Balance < 2147483647 )
		{
			System.out.println( "\nAccount Type: \t \t Ultimate Riches!" );
			Rate = 12.5;
			}

		System.out.println( "Current Balance: \t " + (int)Balance + " NP" );

		System.out.println( "Interest Rate: \t \t " + ( Rate ) + "% per year" );

		System.out.println( "Yearly Interest: \t " + (int)Math.floor( Balance * Rate / 100 ) + " NP" );

		System.out.println( "\nDaily Interest: \t " + format.format( Balance * Rate / 100 / 365 ) + " NP" );

		Daily = Math.ceil( Balance * Rate / 100 / 365 );

		System.out.println( "Next Neopoint/Day: \t " + format.format( (( Daily ) / Rate * 100 * 365 ) - Balance) + " NP" + "\n" ); // + ( Balance % ( 365 / Rate * 100 ))

	}
}
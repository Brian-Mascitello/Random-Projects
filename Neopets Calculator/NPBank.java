//********************************************
// Name: Brian Mascitello
// Title: NPBank.java
// Description: Input Total NP and Interest, Output Current Daily Gains and NP until +1NP/day Interest
// Time spent: 1 hour
// Date: 9/18/2012
//********************************************

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;
public class NPBank
{
	public static void main(String[] args)
	{
		DecimalFormat format = new DecimalFormat("#");
		format.setRoundingMode(RoundingMode.UP);
		Scanner scan = new Scanner(System.in);

		double Balance;
		double Rate;
		double Daily;

		System.out.println( "Enter your Current Balance: " );
		Balance = scan.nextInt();
		System.out.println( "Enter your Interest Rate: " );
		Rate = scan.nextDouble();

		System.out.println( "Your current daily interest is: " + format.format( ( Balance * Rate / 100 / 365 ) - .0025 ) + "NP" );

		Daily = Math.round( ( Balance * Rate / 100 / 365 ) + 1.4975 );

		System.out.println( "Next Neopoint per day in: " + format.format(((( Daily - .9975 ) / ( Rate / 100 )) * 365 ) - Balance ) + "NP" );
	}
}
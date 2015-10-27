/*-------------------------------------------------------------------------
AUTHOR:			Brian Mascitello
EXERCISE:		newtoncube
SPECIFICATION:	Java Practice - After making a newtoncube formula for both
	MATLAB and Python, I will be making one for Java.
-------------------------------------------------------------------------*/

import java.lang.Math; // used to find machine epsilon
import java.util.Scanner; // necessary for user input

public class newtoncube {

	public static void main(String[] args) {
		
		double epsilon = Math.ulp(1.0); // Machine epsilon in Java
		System.out.println("Machine epsilon set as: " + epsilon);
		
		System.out.println("f(x) = ax^3 + bx^2 + cx + d"); // Prints what the equation looks like.
		
		Scanner input = new Scanner(System.in);
		System.out.print("Please enter the value of a: ");
		double a = input.nextDouble();
		System.out.print("Please enter the value of b: ");
		double b = input.nextDouble();
		System.out.print("Please enter the value of c: ");
		double c = input.nextDouble();
		System.out.print("Please enter the value of d: ");
		double d = input.nextDouble();
		System.out.print("Please enter your guess of the root: ");
		double x0 = input.nextDouble();
		input.close();
		
		double change = 0;
		double residual = 0;
		double x = x0;
		double xprevious = 0;
		int k = 0;
		
		while (k < 20 && Math.abs(a*Math.pow(x, 3) + b*Math.pow(x, 2) + c*x + d) >
			epsilon*Math.abs(a*Math.pow(x0, 3) + Math.pow(x0, 2) + c*x0 + d))
		{	
			k++;
			xprevious = x;
			x -= (a*Math.pow(x, 3) + b*Math.pow(x, 2) + c*x + d) / (3*a*Math.pow(x, 2) + 2*b*x + c);
			change = Math.abs(x - xprevious);
			residual = a*Math.pow(x, 3) + b*Math.pow(x, 2) + c*x + d;
			System.out.printf("Iteration: %2d, Root: %10f, Change: %10f, Residual: %10f\n",k,x,change,residual);
		}
		
		System.out.print("Root at " + x);
	}
}
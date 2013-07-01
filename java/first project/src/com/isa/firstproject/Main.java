package com.isa.firstproject;
import java.util.Scanner;
public class Main {

		public static void main(String[] args) {
	String answer;
	Integer number;
	System.out.print("whats your last name");	
	Scanner input=new Scanner(System.in);
	answer=input.nextLine();
	System.out.print("hello "+answer);
	System.out.print(" what is your age");
	number=input.nextInt();
	System.out.print(" age is"+number);
	input.close();
	}

}

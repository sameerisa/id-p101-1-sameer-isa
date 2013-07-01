package com.secondproject.isa;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JTextPane;
import javax.swing.text.html.HTMLEditorKit;


public class Main {

	
	public static void main(String[] args) {
		int loop;
		Dog rascal = new Dog("rascal",0);
		Scanner input=new Scanner(System.in);
		System.out.print(rascal.name);
		Cat fluffy= new Cat("fluffy",0);
		System.out.print(fluffy.name);
		System.out.print("how many times would you like the cat to meow");
		loop=input.nextInt();
		fluffy.meow(loop);
		
		
	}

}

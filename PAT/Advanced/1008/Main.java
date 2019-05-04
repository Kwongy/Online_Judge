package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int first=0,second=0;
		int t=scan.nextInt();
		int sum=0;
		for (int i = 0; i < t; i++) {
			second=scan.nextInt();
			if(second>first)
			{
				sum+=(second-first)*6;
			}
			else {
				sum+=(first-second)*4;
			}
			sum+=5;
			first=second;
			
		}
		System.out.println(sum);
	}
}
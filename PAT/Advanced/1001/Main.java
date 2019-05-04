package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int sum=a+b;
		if(Math.abs(sum)<1000)
		{
			System.out.println(sum);
		}
		else if(Math.abs(sum)<1000000)
		{
			int m=sum%1000;
			int n=sum/1000;
			System.out.println(n +","+ String.format("%03d", Math.abs(m)));
		}
		else 
		{
			int m=sum%1000;
			sum=sum/1000;
			int m1=sum%1000;
			int n=sum/1000;
			
			System.out.println(n +","+String.format("%03d", Math.abs(m1))+","+ String.format("%03d",  Math.abs(m)));
		}
	}
}
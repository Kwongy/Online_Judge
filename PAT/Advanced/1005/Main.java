package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String n=scan.nextLine();
		char[] array=n.toCharArray();
		int a[]=new int[101];
		int len=n.length();
		int sum=0;
		for(int i=0;i<len;i++) {
			sum+=array[i]-'0';
		}
		int count=0;
		if(sum==0)
		{
			count=1;
		}
		while(sum!=0)
		{
			a[count]=sum%10;
			count++;
			sum=sum/10;
		}
		if(count!=1)
		{   
			print(a[count-1]);
			for(int i=count-2;i>=0;i--)
			{
				System.out.print(" ");
				print(a[i]);
			}	
		}
		else {
			print(a[count-1]);
		}
	}
	public static void print(int n) {
		if(n==0)
		{
			System.out.print("zero");
		}
		else if(n==1)
		{
			System.out.print("one");
		}
		else if(n==2)
		{
			System.out.print("two");
		}
		else if(n==3)
		{
			System.out.print("three");
		}
		else if(n==4)
		{
			System.out.print("four");
		}
		else if(n==5)
		{
			System.out.print("five");
		}
		else if(n==6)
		{
			System.out.print("six");
		}
		else if(n==7)
		{
			System.out.print("seven");
		}
		else if(n==8)
		{
			System.out.print("eight");
		}
		else if(n==9)
		{
			System.out.print("nine");
		}
	}
}
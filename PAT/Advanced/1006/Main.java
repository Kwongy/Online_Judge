package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String str=new String();
		int n=scan.nextInt();
		scan.nextLine();
		String sign_in_name="";
		String sign_out_name="";
		String sign_in="23:59:59";
		String sign_out="00:00:00";
		for(int i=0;i<n;i++)
		{
			str=scan.nextLine();
			String[] s=str.split(" ");
			if((s[1].compareTo(sign_in))<0)
			{
				sign_in_name=s[0].substring(0,s[0].length());
				sign_in=s[1].substring(0,s[1].length());
			}
			if((s[2].compareTo(sign_out))>0)
			{
				sign_out_name=s[0].substring(0,s[0].length());
				sign_out=s[2].substring(0,s[2].length());
			}
		}
		System.out.println(sign_in_name+" "+sign_out_name);
	}
}
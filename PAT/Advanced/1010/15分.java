package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String input=scan.nextLine();
		String[] str=input.split(" ");
		int tag=Integer.parseInt(str[2]);
		long radix=Long.parseLong(str[3]);
		long num;
		long max;
		long ans;
		if(tag==1)
		{
			num=transfor(str[0],radix);
			max=findmax(str[1]);
			ans=binarysearch(str[1],num,max);
			
		}else {
			num=transfor(str[1],radix);
			max=findmax(str[0]);
			ans=binarysearch(str[0],num,max);
		}
		boolean ok=false;
		if(str[0].equals("1") && str[1].equals("1"))  
        {  
			System.out.println("2");
			ok=true;
        }  
        if(str[0].equals(str[1])&&ok==false)  
        {  
        	System.out.println(radix);
        	ok=true;
        }  
		if(ans!=-1&&ok==false) {
		System.out.println(ans);
		ok=true;
		}
		if(ans==-1&&ok==false)
		{
			System.out.println("Impossible");
		}
	}
	private static long transfor(String s,long radix) {
		long ans= 0;
		long d=1;
		for(int i=s.length()-1;i>=0;i--)
		{
			int num;
			char c=s.charAt(i);
			if(c>='0'&&c<='9')
			{
				num=c-'0';
			}
			else {
				num=c-'a'+10;
			}
			ans+=num*d;
			d*=radix;
		}
		return ans;
	}
	private static long findmax(String s) {
		long d=-1;
		for(int i=0;i<s.length();i++)
		{
			int num;
			char c=s.charAt(i);
			if(c>='0'&&c<='9')
			{
				num=c-'0';
			}
			else {
				num=c-'a'+10;
			}
			if (num>d) d=num;
		}
		return d+1;
	}
	private static long binarysearch(String s,long left,long right) {
		long ans;
		long num=left;
		 while(left>=right)  
		    {  
		        ans=(left+right)/2;
		        long res=transfor(s,ans);  
		        if(res==num)
		        {
		        	return ans;
		        }
		        else if(res>num)
		        {
		        	left=ans-1;
		        }
		        else {
		        	right=ans+1;
		        }
		    }  
		    return -1;  
	}
}
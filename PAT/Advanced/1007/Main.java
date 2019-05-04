package subjectSelect;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		int[] begin= {0,0};
		int end= 0;
		int num;
		int[] sum= {-1,0};
		ArrayList array=new ArrayList<>();
		boolean isnegative=true;
		for(int i=0;i<t;i++)
		{
			num=scan.nextInt();
			array.add(num);
			if(num>=0)
			{
				isnegative=false;
			}
			sum[1]=sum[1]+num;
			if(sum[1]>sum[0])
			{
				sum[0]=sum[1];
				begin[0]=begin[1];
				end=i;
			}
			else if(sum[1]<0)
			{
				sum[1]=0;
				begin[1]=i+1;
			}
		}
		if(isnegative)
		{
			System.out.println("0 "+array.get(0)+" "+array.get(t-1));
		}
		else
		{
			System.out.println(sum[0]+" "+array.get(begin[0])+" "+array.get(end));
		}
		
	}
}
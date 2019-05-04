package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int[] expo=new int[11];
		double[] coef=new double[11];
		int n,m;
		int[] result_expo=new int[101];
		double[] result_coef=new double[101];
		n=scan.nextInt();
		int input_i;double input_d;
		for(int i=0;i<n;i++)
		{
			expo[i]=scan.nextInt();
			coef[i]=scan.nextDouble();
		}
		m=scan.nextInt();
		int count=0;
		for(int i=0;i<m;i++)
		{
			input_i=scan.nextInt();
			input_d=scan.nextDouble();
			for(int j=0;j<n;j++)
			{
				result_expo[count]=input_i+expo[j];
				result_coef[count]=input_d*coef[j];
				count++;
			}
		}
		n=count;
		for(int i=0;i<count;i++)
		{
			for(int j=i+1;j<count;j++)
			{
				if(result_expo[i]==result_expo[j])
				{
					if(Math.abs(result_coef[i])>0.001)
						{
							result_coef[i]+=result_coef[j];
							result_coef[j]=0;
							result_expo[j]=0;
							n--;
						}
				}
			}
		}
		for(int j=0;j<count;j++)
		{
			for(int i=j;i<count;i++)
			{
				if(result_expo[j]<result_expo[i])
				{
					input_i=result_expo[j];
					result_expo[j]=result_expo[i];
					result_expo[i]=input_i;
					input_d=result_coef[j];
					result_coef[j]=result_coef[i];
					result_coef[i]=input_d;
				}
				
			}
		}
		if(n==1&&Math.abs(result_coef[0])<0.001)
		{
			n=0;
		}
		System.out.print(n);
		for(int j=0;j<count;j++)
		{
			if(Math.abs(result_coef[j])>0.001)
			{
				System.out.printf(" %d %.1f",result_expo[j],result_coef[j]);
			}
			
		}

	}
}
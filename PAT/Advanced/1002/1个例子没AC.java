package subjectSelect;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int[] a=new int[30];
		double[] b=new double[30];
		int k1=scan.nextInt();
		int count=0;
		int m;
		double n;
		for(int i=0;i<k1;i++)
		{
			m=scan.nextInt();
			n=scan.nextDouble();
			if(Math.abs(n)-0<0.0001) {
				continue;
			}
			else {
				a[count]=m;
				b[count]=n;
				count++;
			}
		}
		int k2=scan.nextInt();
		
		for (int i=0;i<k2;i++)
		{
			int find=0;
			boolean isFind=false;
			m=scan.nextInt();
			n=scan.nextDouble();
			if(Math.abs(n)<0.0001) {
				continue;
			}
			else {
				for(int j=0;j<count;j++)
				{
					if (a[j]==m) {
						isFind=true;
						find=j;
						break;
					}
				}
				if(isFind==true)
				{
					b[find]+=n;
					if(Math.abs(b[find])<0.0001)
					{	
							for(int k=find;k<count-1;k++)
							{
								a[k]=a[k+1];
								b[k]=b[k+1];
							}	
							count--;
					}
				}
				else {
					a[count]=m;
					b[count]=n;
					count++;
				}
			}
		}
		for(int i=0;i<count-1;i++)
		{
			for (int j=1;j<count;j++)
			{
				if(a[i]<a[j])
				{
					m=a[i];
					a[i]=a[j];
					a[j]=m;
					n=b[i];
					b[i]=b[j];
					b[j]=n;
					
				}
			}
			
		}
		System.out.print(count);
		for(int i=0;i<count;i++)
		{
			System.out.print(" "+a[i]+" "+String.format("%.1f", b[i]));
		}
		System.out.println();
	}
}
package subjectSelect;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    	Scanner scan=new Scanner(System.in);
    	double max;
    	double sum=1;
    	char[] output=new char[3];
    	for(int i=0;i<3;i++)
    	{
    		max=0;
    		for(int j=0;j<3;j++)
    		{
    			double input=scan.nextDouble();
    			if(input>max) {
    				max=input;
    				if(j==0)
    					{output[i]='W';}
    				else if(j==1)
    					{output[i]='T';}
    				else {output[i]='L';}}
    		}
    		sum*=max;
    		
    	}
    	sum=2*(sum*0.65-1);
    	System.out.println(output[0]+" "+output[1]+" "+output[2]+" "+String.format("%.2f", sum));
   }
    
}
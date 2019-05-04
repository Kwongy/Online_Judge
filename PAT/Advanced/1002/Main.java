package text;

import java.util.Scanner;

public class Main {
	 public static void main(String args[])
		{			
	      double[] input=new double[1001];
	      Scanner scan=new Scanner(System.in);
	      int k,count=0;
	      int i,expo;
	      double coef;
	      for (i = 0; i < input.length; i++) {
			input[i] = 0;
			}
	      k=scan.nextInt();
	      for ( i= 0; i < k; i++) {
			expo=scan.nextInt();
			coef=scan.nextDouble();
			input[expo]+=coef;
	      }
	      k=scan.nextInt();
	      for ( i= 0; i < k; i++) {
			expo=scan.nextInt();
			coef=scan.nextDouble();
			input[expo]+=coef;
	      }
	      for(i=1000;i>=0;i--)
	      {
	    	  if(Math.abs(input[i])>0.01)
	    	  {
	    		  count++;
	    	  }
	      }
	      System.out.print(count);
	      for(i=1000;i>=0;i--)
	      {
	    	  if(Math.abs(input[i])>0.01)
	    	  {
	    		  System.out.print(" "+i+" "+String.format("%.1f",input[i])); 
	    	  }
	      }
	    }
}

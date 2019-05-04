package subjectSelect;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n1 = sc.next(), n2 = sc.next();
        int tag = sc.nextInt(), radix = sc.nextInt();
        if (tag == 2) {
            String tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        BigInteger num1 = str2Num(n1, radix);
        BigInteger low=findBiggest(n2);
        BigInteger minRadix=BigInteger.ZERO;
        BigInteger left=low.add(BigInteger.ONE);
        BigInteger right=num1.max(BigInteger.valueOf(50)).add(BigInteger.ONE);
        while(left.compareTo(right)!=1){
            BigInteger mid=left.add(right).divide(BigInteger.valueOf(2));
            BigInteger tmpValue=BigInteger.ZERO;
            int flag=-1;
            for(int i=0;i<n2.length();i++){
                tmpValue=tmpValue.multiply(mid).add(char2Num(n2.charAt(i)));
                if(tmpValue.compareTo(num1)==1){
                    flag=1;
                    break;
                }else if(tmpValue.compareTo(num1)==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                right=mid.subtract(BigInteger.ONE);
            else if(flag==-1)
                left=mid.add(BigInteger.ONE);
            else{
                minRadix=mid;
                right=mid.subtract(BigInteger.ONE);
            }
             
        }
        if(minRadix.equals(BigInteger.ZERO))
            System.out.println("Impossible");
        else
            System.out.println(minRadix);
         
        sc.close();
 
    }
    private static BigInteger findBiggest(String str) {
        BigInteger max=BigInteger.ZERO;
        for(int i=0;i<str.length();i++){
            if(max.compareTo(char2Num(str.charAt(i)))==-1)
                max=char2Num(str.charAt(i));
        }
        return max;
    }
 
    private static BigInteger str2Num(String str, int radix) {
        BigInteger value=BigInteger.ZERO;
        for(int i=0;i<str.length();i++){
            value=value.multiply(BigInteger.valueOf(radix)).add(char2Num(str.charAt(i)));
        }
        return value;
    }
     

    private static BigInteger char2Num(Character c) {
        BigInteger value;
        if (c >= '0' && c <= '9')
            value = BigInteger.valueOf(c - '0');
        else
            value = BigInteger.valueOf(c - 'a' + 10);
        return value;
 
    }
 
}


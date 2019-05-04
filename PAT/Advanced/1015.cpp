#include <iostream>
#include <algorithm>
#include <cstring>
#include<cmath>
using namespace std;
int caculate(int num,int radix){		//将原数按给定进制转换后，反转，然后再转换回去。 
	int result = 0;
	char s[30];
	int count = 0;
	while(num!=0){
		s[count] = num % radix + '0';
		num = num / radix;
		count ++;
	}
	for(int i = 0; i < count; i++){
		result *= radix;
		result +=  (s[i]-'0');
	}
	return result;
}
int main(){
	int n,d;
	int prime[100500];
	for(int i = 2; i <100500 ; i++){
		if(prime[i] == 0){
			for(int j = 2; j * i < 100500; j++){
				prime[j*i] = 1;
			}
		}
	}
	prime[0] = prime[1] = 1;			//0和1 不是质数 需要特判 
	while(true){
		scanf("%d",&n);
		if(n<0){
			break;
		}
		scanf("%d",&d);
		if(prime[n]){
			printf("No\n");
			continue;
		}
		int re = caculate(n,d);
		if(prime[re]){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	return 0;
}

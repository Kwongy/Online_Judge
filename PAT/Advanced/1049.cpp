#include<iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int left = 0, right = 0, a = 1, now = 1;
	long out = 0;
	while(n / a){
		left = n / (a * 10);
		right = n % a;
		now = n / a % 10;
		if(now == 0) out += left * a;			//如果当前位==0，则该为出现1 的情况由更高位决定，= 更高为数字*当前位数
		else if(now == 1) out += left * a + right + 1;//如果当前位==1，则该为出现1 的情况受更高位以及低位影响，= （更高为数字*当前位数）+（低位数字+1）
		else out += (left + 1) * a; //如果当前位>1，则该为出现1 的情况由更高位决定，= (更高为数字+1)*当前位数
		a = a*10;
	}
	cout << out << endl;
	return 0;
} 

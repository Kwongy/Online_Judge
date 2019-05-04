#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int n,radix;
	cin >> n >> radix;
	char result = 0;
	if(n == 0){
		cout << "Yes" << endl;
		cout << 0 << endl;
		return 0;
	}
	int s[50];
	int count = 0; 
	while(n != 0){
		s[count] = (n % radix) ;
		count++;
		n = n / radix;
	}
	bool ok = true;
	for(int i = 0 ; i < count/2; i++){
		if(s[i] != s[count-1-i]){
			ok = false;
			break;
		}
	}
	if(ok){
		cout << "Yes" << endl;
	}else{
		cout << "No"  << endl;
	}
	for(int i = count - 1; i > 0; i--){
		cout << s[i] << " ";
	}
	cout << s[0];
	return 0;
}

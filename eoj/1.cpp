#include<bits/stdc++.h>
using namespace std;
int main(){
	// output a + b 
	string a, b;
	cin >> a >> b;
	int len1 = a.size();
	int len2 = b.size();
	if(len1 < len2){
		int t = len1;
		len1 = len2;
		len2 = t;
		string s = a;
		a = b;
		b = s;
	}
	int cha = len1 - len2;
	for(int i = 0; i < cha; i++){
		b = "0" + b;
	}
	for(int i = len1; i > 0; i--){
		a[i] = a[i] + b[i] - '0';
		if(a[i] > '9'){
			a[i] -= 10;
			a[i-1] += 1;
		}
	}
	a[0] += b[0] - '0';
	if(a[0] > '9'){
		a[0] -= 10;
		a = "1" + a;
	}
	cout << a << endl;
	return 0;
}

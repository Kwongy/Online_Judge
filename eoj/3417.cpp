#include<bits/stdc++.h>
using namespace std;
int main(){
	int b;
	long long a, ans;
	cin >> a >> b;
	ans = 1;
	while(b){
		if(b&1) ans *= a;
		b >>= 1;
		a = a * a;
	}
	cout << ans << endl;
	return 0;
} 

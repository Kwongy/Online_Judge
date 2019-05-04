#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
int main(){
	int t; cin >> t;
	int a;
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i < 1000005; i++){
		if(i&1) dp[i] = dp[i-1];
		else dp[i] = (dp[i-1] + dp[i/2]) %1000000000;
	}
	for(int i = 0; i < t; i++){
		cin >> a;
		cout << "case #" << i << ":\n" << dp[a] << endl;
	}
	return 0;
} 

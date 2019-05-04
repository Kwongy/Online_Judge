#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int main(){
	int n; cin >> n;
	memset(dp, 0, sizeof(dp));
	// init
	for(int i = 0; i < 1000; i++){
		if(i % 100 == 99) dp[i][1] = 19;
		else if(i % 10 == 9) dp[i][1] = 10;
		else dp[i][1] = 1;
	}
	// calu
	for(int i = 0; i < 1000; i++){
		for(int j = 2; j + i < 1000; j++){
			dp[i][j] = dp[i][j-1] + dp[i+j-1][1];
		}
	}
	int a, b, x;
	for(int q = 1; q <= n; q++){
		cin >> a >> b >> x;
		int maxn = 0;
		for(int i = 0; i <= x; i++) maxn = max(maxn, dp[a][i] + dp[b][x-i]);
		cout << "Case " << q << ": " << maxn << endl;
		
	}
	
	return 0;
}

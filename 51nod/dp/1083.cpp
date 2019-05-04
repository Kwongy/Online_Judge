#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int main(){
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> dp[i][j];
		} 
	} 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[n][n] << endl;
	
	return 0;
}

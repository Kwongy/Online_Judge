#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main(){
	/*
		1183 ±à¼­¾àÀë
		²Î¿¼²©¿Í https://blog.csdn.net/baodream/article/details/80417695 
	*/ 
	int n, m;
	string s1, s2; cin >> s1 >> s2;
	n = s1.size(); m = s2.size();
	// initilization
	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int i = 1; i <= m; i++) dp[0][i] = i;
	// dp 
	// state transition equation
	// dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + flag) 
	// flag = s1[i] == s2[j] ? 0 : 1  
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
			if(s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
		}
	}
	printf("%d", dp[n][m]); 
	return 0;
}

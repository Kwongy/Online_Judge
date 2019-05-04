#include<bits/stdc++.h>
using namespace std;
int dp[105][10005] = {0};
int c[105];
int w[105];
int main(){
	freopen("aa.txt","r",stdin);
	int n, m; scanf("%d %d", &n, &m);
	int a, b;
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &a, &b);
		c[i] = a;
		w[i] = b;
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int v = 0; v <= m; v++){
			if(v < c[i]) dp[i][v] = dp[i-1][v];
			else dp[i][v] = max(dp[i-1][v], dp[i-1][v-c[i]] + w[i]);
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}

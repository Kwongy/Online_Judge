#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int dp[105][maxn];
const int INF = (-1) << 20;
int n;
int c[105];
int main(){
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n ;i++){
		cin >> c[i];
		sum += c[i];
	}
	fill(dp[0], dp[0] + 105 * maxn,INF);
	dp[0][0] = 0;
	// i 表示前 i 块木块 ， j表示两塔相差的高度 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j+c[i]]); //这块木块不放           f[i-1][j]                
														//放在矮的塔上且没超过高塔     f[i-1][j+a[i]]
			if(j >= c[i]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]]+c[i]); 	// 放在高的塔上      f[i-1][j-a[i]]+a[i]
			}else{
				dp[i][j] = max(dp[i][j], dp[i-1][c[i]-j] + j);		//放在矮的塔上但超过了高塔     f[i-1][a[i]-j]+j 
			}
		} 
	}
	if(dp[n][0] > 0) cout << dp[n][0] << endl;
	else cout << 0 << endl;
	return 0;
}

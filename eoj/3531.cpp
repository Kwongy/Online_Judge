#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
//	freopen("aa.txt","r",stdin);
	int n, m; cin >> n >> m;
	int dp[105];
	int damage[105];
	for(int i = 0; i <= n; i++){
		dp[i] = damage[i] = 0;
	}
	int a;
	for(int i = 0; i < m; i++){
		cin >> a;
		damage[a]++;
		dp[a] = 0;
	}
	dp[0] = 0;
	if(!damage[1]) dp[1] = 1;;
	if(!damage[2]) dp[2] = dp[1] + 1;
	if(!damage[3]) dp[3] = dp[1] + dp[2] + 1;
	for(int i = 4; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i - 3];
		if(damage[i]) dp[i] = 0;
	}
	cout << dp[n] << endl;
	return 0;
}

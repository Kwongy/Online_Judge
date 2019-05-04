#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("aa.txt","r",stdin);
	int dp[10005] = {0};
	int n; cin >> n;
	dp[1] = 1; 
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + 1;
		for(int j = 2; j < i / 2; j++){
			if(i % j == 0){
				int s = i / j;
				dp[i] = min(dp[i], dp[s] + dp[j]);
			}
		}
	}
	cout << dp[n] << endl;

	return 0;
}

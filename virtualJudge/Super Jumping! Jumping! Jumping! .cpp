#include<bits/stdc++.h>
using namespace std;
const int inf = (-1) << 20;
typedef long long ll;
int dp[1005], a[1005];
int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans;
		for(int i = 1; i <= n; i++){
			ans = inf;
			for(int j = 0; j < i; j++){
				if(a[i] > a[j]) ans = max(ans, dp[j]);		// 转移方程 
			}
			dp[i] = ans + a[i];						//找到之前最大的dp[j]再加上现在的a[i]组成dp[i] 
		}
		ans = inf;
		for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	return 0;
}

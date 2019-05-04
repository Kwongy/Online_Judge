#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100005];
int main(){
	int n;
	while(~scanf("%d", &n) && n){
		memset(dp, 0, sizeof(dp));
		int cnt = 0, a;
		for(int i = 0; i < n; i++){
			cin >> a;int j;
			for(j = 0; j <= cnt; j++){
				if(dp[j] >= a) {
					dp[j] = a;
					break;
				}
			}
			if(j > cnt) dp[++cnt] = a;
		}
		cout << cnt << endl;
	}
	
	return 0;
} 

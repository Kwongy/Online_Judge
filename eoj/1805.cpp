#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2][52000];
int main(){
	string a, b; cin >> a >> b;
	int maxn = 0;
	int na = a.size(), nb = b.size();
	a = " " + a;
	b = " " + b;
	memset(dp, 0, sizeof(dp));
	int now = 1;
	for(int i = 1; i <= na; i++){
		for(int j = 1; j <= nb; j++){
			if(a[i] == b[j]) dp[now][j] = dp[(now+1) % 2][j-1] + 1;
			else{
				dp[now][j] = 0;
			}
			maxn = max(maxn, dp[now][j]);
		}
		now = (now+1) % 2;
	}
	cout << maxn << endl;
	return 0;
}

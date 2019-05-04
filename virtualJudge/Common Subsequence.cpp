#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005];
char b[1005];
int dp[1005][1005];
// lcs 
int main(){
	int n; cin >> n;
	while(~scanf("%s %s\n", a+1, b+1)){
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(a + 1);
		int len2 = strlen(b + 1);
		
		for(int i = 1; i <= len1; i++){
			for(int j = 1; j <= len2; j++){
				if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;		//相同 则两个字符都有效 
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);		//不相同 要么a[i]没用 要么b[j]没用 
			}
		}
		cout << dp[len1][len2] << endl;
	}
	return 0;
}

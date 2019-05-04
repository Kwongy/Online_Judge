//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
string a, b; 
// 和自己的反串做lcs  数组滚动 
int dp[2][5050];
int main(){
//	freopen("aa.txt","r",stdin);
	cin >> n;
	cin >> a;
	b = a;
	reverse(a.begin(), a.end());
	a = " " + a;
	b = " " + b;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == b[j]) dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
			else dp[i%2][j] = max(dp[(i-1) % 2][j], dp[i%2][j-1]);
		}
	}
	int l = dp[n%2][n];
	cout << n - l << endl;
	return 0;
}

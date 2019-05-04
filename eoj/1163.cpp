#include<bits/stdc++.h>
using namespace std;
const int MAX =  2000005;
int c[MAX];
int w[MAX];
int dp[MAX];
int main(){
	int a;
	while(scanf("%d", &a) != EOF){
		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for(int j = 1; j <= a; j++){
			cin >> c[j];
			w[j] = c[j];
			sum += c[j];
		}
		for(int j = 1; j <= a; j++){
			for(int k = sum/2; k >= c[j]; k--) {
				dp[k] = max(dp[k], dp[k-c[j]]+w[j]); 
			}
		}
		cout << sum - 2 * dp[sum/2] << endl;
	}
	return 0;
} 

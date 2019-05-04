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
	// i ��ʾǰ i ��ľ�� �� j��ʾ�������ĸ߶� 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j+c[i]]); //���ľ�鲻��           f[i-1][j]                
														//���ڰ���������û��������     f[i-1][j+a[i]]
			if(j >= c[i]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]]+c[i]); 	// ���ڸߵ�����      f[i-1][j-a[i]]+a[i]
			}else{
				dp[i][j] = max(dp[i][j], dp[i-1][c[i]-j] + j);		//���ڰ������ϵ������˸���     f[i-1][a[i]-j]+j 
			}
		} 
	}
	if(dp[n][0] > 0) cout << dp[n][0] << endl;
	else cout << 0 << endl;
	return 0;
}

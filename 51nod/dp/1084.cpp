#include<bits/stdc++.h>
using namespace std;
int dp[405][210][210];
int arr[210][210];
int main(){
	// ��·dp
	// ״̬ dp[step + 1][x1][x2] = max{dp[step][x1��][x2��]} + a[x1][y1] + a[x2][y2] 
	// dp[i][j][k] �� i ��ʾ����  ��ʱ�� i - j == i - k   �� j�� k���Ǻ�����
	int n, m; scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 2; i <= n + m; i++){
		for(int j = 1; j <= i - 1 && j <= n; j++){
			for(int k = 1; k <= i - 1 && k <= n; k++){
				dp[i][j][k] = max(max(dp[i-1][j][k-1], dp[i-1][j][k]), max(dp[i-1][j-1][k],dp[i-1][j-1][k-1]))+ arr[j][i - j] + (j == k ? 0 : arr[k][i - k]);
			}
		}
	}
	printf("%d", dp[m+n][n][n]);
	
	return 0;
}

// 多重背包 
/*    case1: 基本算法   
	 每种物品选0，1，2...至c[i]件，转换为0-1背包 
	 时间复杂度 n * W * max(Ci) 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][50005];
int w[105];
int p[105];
int c[105];
int main(){
	int n, W;
	cin >> n >> W;   
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &w[i], &p[i], &c[i]);
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= W; j++){
			for(int k = 0; k <= min(j/w[i], c[i]); k++){
				if(j - k * w[i] >= 0){
					dp[i][j] = max(dp[i-1][j - k * w[i]] + k * p[i], dp[i][j]);
				}
			}
		}
	}
	cout << dp[n][W];
	return 0;
} 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[20005];
ll v[20005];
int ct = 0;
ll dp[50005];

// case2: 二进制拆分思想  可以把n拆成logn个数的和  降低时间复杂度 
// 时间复杂度 O(W * sigma(logCi)) 
int main(){
//	freopen("aa.txt","r",stdin);
	int n, m; scanf("%d %d", &n, &m);
	int a, b, c;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &a, &b, &c);
		int t = 1;
		// 二进制拆分 
		while(c){
			if(c >= t){
				cnt[ct] = t * a;
				v[ct++] = t * b;
				c -= t;
				t *= 2; 
			}else{
				cnt[ct] = c * a;
				v[ct++] = c * b;
				c = 0;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < ct; i++){
		for(int j = m; j >= cnt[i]; j--){
			dp[j] = max(dp[j], dp[j - cnt[i]] + v[i]);
		}
	}
	printf("%lld\n", dp[m]);
	return 0;
}

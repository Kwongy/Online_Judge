// ���ر��� 
/*    case1: �����㷨   
	 ÿ����Ʒѡ0��1��2...��c[i]����ת��Ϊ0-1���� 
	 ʱ�临�Ӷ� n * W * max(Ci) 
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

// case2: �����Ʋ��˼��  ���԰�n���logn�����ĺ�  ����ʱ�临�Ӷ� 
// ʱ�临�Ӷ� O(W * sigma(logCi)) 
int main(){
//	freopen("aa.txt","r",stdin);
	int n, m; scanf("%d %d", &n, &m);
	int a, b, c;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &a, &b, &c);
		int t = 1;
		// �����Ʋ�� 
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

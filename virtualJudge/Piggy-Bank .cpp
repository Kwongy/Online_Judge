#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int c[10005];
int w[10005];
const int maxn = 1 << 29;
// ��ȫ��С���� 
int main(){
//	freopen("aa.txt","r",stdin);
	int t;
	scanf("%d", &t);
	while(t--){
		int m, M; scanf("%d %d", &m, &M);
		M -= m;
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &c[i], &w[i]);
		}
		if(M < 0){
			printf("This is impossible.\n");
			continue;
		}
		for(int j = 0; j < 10005; j++){
			dp[j] = maxn;
			// �ѳ���0֮�ⶼ���ó�maxnʱ�� �ɱ�֤������������ȫ���������� 
		}
		
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = w[i]; j <= M; j++){
				dp[j] = min(dp[j], dp[j-w[i]]+c[i]);
			}
		}
		if(dp[M] != maxn){
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[M]);
		}else{
			printf("This is impossible.\n");
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[505][505];

// dp ����Ӷκͽ���  ������� 
int main(){
	int m, n; scanf("%d %d", &m, &n);
	ll t;
	memset(arr, 0, sizeof(arr));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			// ��ȡ �����е�ǰ׺�� 
			scanf("%lld", &t);
			arr[i][j] = arr[i-1][j] + t;
		}
	ll maxn = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			// ������֮��ӳ��Ϊһά����  ������Ӷκ� 
			ll temp = 0, a;
			for(int k = 1; k <= m; k++){
				a = arr[j][k] - arr[i-1][k];
				temp += a;
				if(temp > 0){
					maxn = max(maxn, temp);
				}else{
					temp = 0;
				}
			}
		}
	}
	printf("%lld\n", maxn);
	return 0;
}

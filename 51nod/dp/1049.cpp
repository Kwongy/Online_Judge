#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[505][505];

// dp 最大子段和进阶  最大矩阵和 
int main(){
	int m, n; scanf("%d %d", &m, &n);
	ll t;
	memset(arr, 0, sizeof(arr));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			// 读取 并求列的前缀和 
			scanf("%lld", &t);
			arr[i][j] = arr[i-1][j] + t;
		}
	ll maxn = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			// 将两行之间映射为一维数组  求最大子段和 
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

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[10005];
int arr[202];
// 类 0 1背包
// 将每个数看做成重量和体积相等的物品， 数的总和的一半 sum/2 为背包体积
// 求这个体积为 sum/2 的背包的最大价值 
int main()
{
	int sum = 0;
	int n;cin >> n; 
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
	int sz = sum / 2;
	for(int i = 0; i < n; i++){
		for(int j = sz; j >= arr[i]; j--){
			dp[j] = max(dp[j], dp[j-arr[i]] + arr[i]);
		}
	}
	cout << sum - dp[sz] * 2  << endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
const int MOD = (int)1e9+7;
int arr[1050][1050];
int main(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= 1000; i++){
		arr[i][1] = arr[1][i] = 1;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % MOD;
		}
	}
	cout << arr[n][m] << endl;
	return 0;
} 

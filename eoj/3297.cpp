#include<bits/stdc++.h>
using namespace std;
int n;
int ans, one;
void dfs(int sum, int before, int q){
	if(sum == 0){
		ans++;
		one += q;
	}else if(sum < 0) return;
	for(int i = 1; i <= 3; i++){
		if(before == i) continue;
		dfs(sum - i, i, i == 1 ? q + 1 : q);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		ans = one = 0;
		cin >> n;
		dfs(n-1, 1, 1);
		dfs(n-2, 2, 0);
		dfs(n-3, 3, 0);
		cout << ans << endl << one << endl;
	}
	return 0;
}

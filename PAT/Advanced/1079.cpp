#include<iostream>
using namespace std;
int vis[20] = {0};
int arr[20];
int flag = 0,n;
void dfs(int i, int sum){
	if(flag) return;
	if(i == n && sum % 360 == 0){
		flag = 1;
		cout <<  "YES" << endl;
		return ;
	}
	for(int j = 0; j < n; j++){
		if(!vis[j]){
			vis[j] = 1;
			dfs(i + 1, sum + arr[j]);
			dfs(i + 1, sum - arr[j]);
			vis[j] = 0;
		}
	}
}
int main(){
	freopen("aa.txt","r",stdin) ;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	dfs(0, 0);
	if(!flag) cout << "NO" << endl;
	return 0;
}

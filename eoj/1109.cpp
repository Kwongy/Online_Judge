#include<bits/stdc++.h>
using namespace std;
const int INF = (-1) << 28;
int arr[105];
int main(){
	int t, n, s;
	cin >> t;
	while(t--){
		cin >> n;
		int maxn = INF;
		int sum = 0;
		int flag = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i] >= 0) flag = 1;
			sum += arr[i];
			if(sum >= 0) maxn = max(maxn , sum);
			else sum = 0;
		}
		if(!flag){
			maxn = INF;
			for(int i = 0; i < n; i++) maxn = max(maxn, arr[i]);
		}
		cout << maxn << endl;
	}
	
	
	
	return 0;
}

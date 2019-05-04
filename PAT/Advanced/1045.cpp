#include<bits/stdc++.h>
using namespace std;
int main(){
	/*
	   mark the favorite color position
	   dp , state transition equation 
	   dp[i] = max(1, dp[j] + 1) [pos[j] <= dp[i]] 
	*/
	
	int i, j, k;
	int pos[300] = {0};
	int arr[100005] = {0};
	int dp[100005] = {0};
	int n, m, l, a;
	scanf("%d", &n);
	scanf("%d", &m);
	for(i = 1; i <= m; i++){
		scanf("%d", &a);
		pos[a] = i;
	}
	scanf("%d", &l);
	for(i = 1, k = 1; i <= l; i++){
		scanf("%d", &a);
		if(pos[a]) arr[k++] = a;
	}
	
	for(j = 1; j < k; j++){
		dp[j] = 1;
		for(i = 1; i < j; i++){
			if(pos[arr[j]] >= pos[arr[i]]) dp[j] = max(dp[j] , dp[i] + 1);
		}
	}
	printf("%d", dp[k-1]); 
	
	return 0;
}

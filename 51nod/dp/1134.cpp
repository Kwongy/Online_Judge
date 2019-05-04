#include<bits/stdc++.h>
using namespace std;
int main(){
	/*
		如果发现一个数比b数组末尾的数要小，
		那么说明现有的子序列中一定存在着比a[i]要大的数，
		用a[i]把第一个比a[i]要大的数替换掉是不会影响子序列的长度的
	*/
	int n;
	// pos始终是一个递增的最长子序列 
	int pos[50005], arr[50005];
	scanf("%d",&n);
    
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	pos[0] = arr[0];
	int len = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] > pos[len-1]){
			pos[len++] = arr[i];
		}else{
			int p = lower_bound(pos, pos+len-1, arr[i]) - pos;
			pos[p] = arr[i];
		}
	}
	printf("%d\n", len);
	return 0;
}

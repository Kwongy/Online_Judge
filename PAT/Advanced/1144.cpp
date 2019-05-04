#include<bits/stdc++.h>
using namespace std;

int arr[200005];
int main(){
	memset(arr, 0, sizeof(arr));
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a > 0 && a < 200005)	arr[a]++;
	}
	int i;
	for(i = 1; i <= 200005; i++){
		if(!arr[i]) break;
	}
	cout << i << endl;
	return 0;
}

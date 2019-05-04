#include<bits/stdc++.h>
using namespace std;
int arr[15][15];
int main(){
	int n; cin >> n;
	memset(arr, 0, sizeof(arr));
	arr[1][1] = 1;
	cout << 1 << endl;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1 || j == i) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			if(j != i) cout << arr[i][j] << " ";
			else cout << arr[i][j] << endl;
		}
	}

}

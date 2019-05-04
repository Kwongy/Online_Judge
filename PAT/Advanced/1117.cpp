#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[100000];
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n, greater<int>());
	int e = 0;
	while(e < n && arr[e] > e + 1) e++;
	cout << e << endl;
	return 0;
}

#include<iostream>

using namespace std;

int main(){
//	freopen("aa.txt","r",stdin);
	int n, t, temp, old, count = 0;
	cin >> n;
	int arr[10050] = {0};
	int color = 1, maxn = 0;
	for(int k = 0; k < n; k++){
		cin >> t;
		for(int i = 1; i <= t; i++){
			cin >> temp;
			if(temp > maxn) maxn = temp;
			if(arr[temp] == 0) arr[temp] = color;
			else{
				old = arr[temp];
				arr[temp] = color;
				for(int j = 1; j <= maxn; j++){
					if(arr[j] == old) arr[j] = color;
				}
				count--;
			}		
		}
		color++;
		count++;
	}
	cout << count << " " << maxn << endl;
	int a, b, c; cin >> c;
	for(int i = 0; i < c; i++){
		cin >> a >> b;
		if(arr[a] == arr[b]) cout << "Yes"  <<endl;
		else cout << "No" << endl;
	}
	return 0;
}

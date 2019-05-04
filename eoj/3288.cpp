#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		int a;
		int i = 0;
		int sum = 0;
		int maxn = -1;
		int minn = 100;
		cout << "case #" << k << ":\n";
		while(true){
			cin >> a;
			if(a != -1){
				maxn = max(maxn, a);
				minn = min(minn, a);
				sum += a;
				i++;
			}else{
				cout << maxn << endl << minn << endl << sum / i << endl;
				break;
			}
		}
	}
	
	
	
}

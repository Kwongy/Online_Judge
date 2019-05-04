#include<bits/stdc++.h>
using namespace std;
const int MAX =  1000005;
vector<int> vec;
int prime[MAX];
int main(){
	memset(prime, 0, sizeof(prime));
	for(int i = 2 ; i < MAX; i++){
		if(!prime[i]){
			vec.push_back(i);
			for(int j = 2; j * i < MAX; j++){
				prime[i*j] = 1;
			}
		}
	}
	int n; cin >> n;
	int t = vec.size();
	for(int i = 0; i < n; i++){
		cout << "case #" << i << ":\n";
		int a; cin >> a;
		for(int j = 0; j < t; j++){
			if(a % vec[j] == 0){
				cout << a / vec[j] << endl;
				break;
			}
		}
	}
	return 0;
} 

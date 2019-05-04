#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int hash[1002];
	memset(hash,0,sizeof(hash));
	int n, m ,a; cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		hash[a]++;
	}
	for(int i = 1; i <= 1000; i++){
		if(hash[i] > 0){
			a = m - i;
			if(a < 0) break;
			if(a != i) {
				if(hash[a] > 0){
					cout << i << " " << a << endl;
					return 0;
				}
			}else{
				if(hash[i] > 1){
					cout << i << " " << i << endl;
					return 0;
	 			}
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n == 2) return true;
	else{
		bool ans = true;
		for(int i = 2; i <= (int)(sqrt(n)); i++){
			if(n % i == 0){
				ans = false;
				break;
			} 
		}
		return ans;
	}
}
int main(){
//	freopen("aa.txt","r",stdin);
	int n, k; cin >> n >> k;
	int arr[2000];
	string t; cin >> t;
	for(int i = 0; i < n; i++){
		arr[i] = t[i] - '0';
	}
	for(int i = 0; i < n - k + 1; i++){
		int s = 0;
		for(int j = i; j < i + k; j++){
			s = s * 10 + arr[j];
		}
		if(prime(s)){
			for(int j = i; j < i + k; j++){
				printf("%d", arr[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("404\n");
	return 0;
}

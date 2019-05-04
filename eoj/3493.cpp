#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll t){
	ll s = ll(sqrt(t));
	bool ans = true;
	for(ll i = 2; i <= s; i++){
		if(t % i == 0){
			ans = false;
			break;
		}
	}
	
	return ans;
}
// 是质数的话 1 不是质数的话  偶数一定可由两个质数组成  奇数可由质数+2 或3质数组成 特判！ 
int main(){
	ll n; cin >> n;
	int ans;
	if(n == 2 || n == 3 || n == 5 || n == 7) ans = 1;
	else if(n % 2 == 0) ans = 2;
	else{
		if(isprime(n)) ans = 1;
		else if(isprime(n-2)) ans = 2;
		else ans = 3;
	}
	cout << ans << endl;
	return 0;
} 

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
// �������Ļ� 1 ���������Ļ�  ż��һ�����������������  ������������+2 ��3������� ���У� 
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

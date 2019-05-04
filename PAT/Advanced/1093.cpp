#include<iostream>

using namespace std;
#define MOD 1000000007
typedef long long ll;
ll sum = 0;

int main(){
	string s; cin >> s;
	int arr[100005][2];
	int cntp = 0, cntt = 0;
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] == 'P') arr[i][0] = ++cntp;
		else arr[i][0] = cntp;
		if(s[i] == 'T') arr[i][1] = ++cntt;
		else arr[i][1] = cntt;
	}
	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			sum = (sum + (arr[i][0] * (cntt - arr[i][1])) % MOD) % MOD;
		}
	}
	cout << sum << endl;
	return 0;
}

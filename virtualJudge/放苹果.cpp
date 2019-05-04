#include<iostream>
#include<cstdio>
using namespace std;
// apple = n, plate = m 
int take(int n, int m){
	if(n == 0 || m == 1) return 1;	//  export
	else if(m > n) return take(n, n);	// plate > apple , so  (plate - apple) is useless
	else return take(n, m - 1) + take(n - m, m);	// all plates have an apple, so take it away
}
int main() {
	int t;cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		cout << take(a, b) << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
/*
	循环最大子段和
	1）笨方法，我们可以用普通最大子段和的方法解决这个问题。我们从每个位置“断开”环，然后按普通的最大子段和的方法去做。这样做的复杂度是O(n^2)。
	2）巧妙点的方法，我们之所以要从某个位置切开是因为循环的最大子段和可能是跨越一部分头和尾 
*/ 
typedef long long ll;
ll maxn = 0;
ll maxm = 0;
vector<int> vec;
int main(){
	int n;cin >> n;
	vec.resize(n + 1);
	ll sum = 0;
	ll cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
		cnt += vec[i];
		if(sum > 0){
			maxn = max(maxn, sum);
		}else{
			sum = 0;
		}
	}
	sum = 0;
	for(int i = 0; i < n; i++){
		sum += vec[i];
		if(sum < 0){
			maxm = min(sum, maxm);
		}else{
			sum = 0;
		}
	}
	cout << max(maxn, (cnt - maxm)) << endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[10];
void dp(ll n, int sign){
	ll cur, pre, after, temp = 1, tn = n;
	while(n){
		cur = n % 10;			     // 当前位 
		pre = n / 10; 				 // 前面部分 
		after = tn - n * temp;		 // 后面部分 
		for(int i = 0; i < 10; i++){		// 对高位的影响    
			if(cur > i) ans[i] += (pre+1)*temp*sign;		    
			else if(cur < i) ans[i] += pre * temp * sign;	 
			else ans[i] += (pre * temp + after + 1) * sign;
		}
		ans[0] -= temp * sign;	//减去前导为0的情况 
		temp *= 10;
		n /= 10;
	}
}
int main() {
	ll r, l;
	scanf("%lld %lld", &l, &r);
	memset(ans, 0, sizeof(ans));
	dp(r, 1);
	dp(l-1, -1);
	for(int i = 0; i < 10; i++) printf("%lld\n", ans[i]);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int x[maxn];
int y[maxn];
int l[maxn << 1];
int r[maxn << 1];
int calul(int a, int b, int n){
	if(a == b) return n;
	else if (a > b){
		return n + a - b;
	}else{
		return b - a;
	}
}
int calur(int a, int b, int n){
	return a + b - 1;
}
int main(){
	int n, a, b;
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	ll cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		int flag = 0;
		// zuobian
		int c = calul(a, b, n);
		// you
		int d = calur(a, b, n);
		flag = x[a] + y[b] + l[c] + r[d];
		x[a]++, y[b]++, l[c]++, r[d]++;
		cnt += flag;
	}
	printf("%lld\n", cnt);
	return 0;
} 

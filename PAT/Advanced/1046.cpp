#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	freopen("aa.txt","r",stdin);
	int n; int c; cin >> n;
	long sum[n+10]; sum[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&c);
		sum[i] = sum[i-1] + c;
	}
	int a, b, m ,temp; cin >> m;
	long x,y;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&a,&b);
		temp = min(a,b);
		b = max(a,b);
		a = temp;
		x = sum[b-1] - sum[a-1];
		y = sum[n] - x;
		printf("%lld\n",min(x,y));
	}
	
	return 0;
} 

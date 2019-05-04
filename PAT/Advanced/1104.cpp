#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	int n; cin >> n;
	double sum = 0;
	double temp;
	ll num; 
	for(int i = 1; i <= n; i++){
		scanf("%lf", &temp);
		sum += temp * i * (n + 1 - i);
	}
	printf("%.2f", sum);
	return 0;
}

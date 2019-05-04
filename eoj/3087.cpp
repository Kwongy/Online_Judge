#include<bits/stdc++.h>
using namespace std;
const double epslion = 1e-15;
double a[4] = {2, -4, 3, -6};
double b[4] = {6, -8, 3, 0};
double cal(double x){
	double ans = a[0] * pow(x, 3) + a[1] * pow(x, 2) + a[2] * pow(x, 1) + a[3] * pow(x, 0);
	return ans;
}
int main(){
	double x0 = 1.5;
	int ans = 0;
	while(fabs(cal(x0)) > epslion){
		x0 = x0 - (cal(x0))/(b[0] * pow(x0, 2) + b[1] * pow(x0, 1) + b[2]);
		ans++;
	} 
	printf("%.2f %d\n", x0, ans);
	
	
	return 0;
}

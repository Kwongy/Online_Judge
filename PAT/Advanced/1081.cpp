#include<iostream>
#include<cmath>

using namespace std;

long gcdd(long a,long b){
    return b==0?a:gcdd(b,a%b);
}
long arr[110][2];
long lcm(long a, long b){
	return (a * b / gcdd(a, b));
}
int main(){
//	freopen("aa.txt","r",stdin);
	int n; cin >> n;
	long a, b; char c;
	for(int i = 0; i < n; i++){
		scanf("%ld%c%ld", &a, &c, &b);
		arr[i][0] = a;
		arr[i][1] = b;
	}
	long g,l;
	for(int i = 1; i < n; i++){
		l = lcm(arr[i- 1][1], arr[i][1]);
		arr[i][0] = (arr[i][0] * (l / arr[i][1])) + (arr[i - 1][0] * (l / arr[i - 1][1]));
		arr[i][1] = l;
		g = gcdd(abs(arr[i][0]), arr[i][1]);
		arr[i][0] /= g;
		arr[i][1] /= g;
	}
	int i = n-1;
	if(arr[i][0] == 0) printf("0\n");
	else if(abs(arr[i][0]) >= arr[i][1]){
		a = arr[i][0] / arr[i][1];
		arr[i][0] = abs(arr[i][0] % arr[i][1]);
		if(arr[i][0] == 0) printf("%ld\n", a);
		else{
			printf("%ld %ld/%ld\n", a, arr[i][0], arr[i][1]);
		}
	}else{
		printf("%ld/%ld\n", arr[i][0], arr[i][1]);
	}
	
	
	return 0;
}

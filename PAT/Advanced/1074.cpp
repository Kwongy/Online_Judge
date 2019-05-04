#include<iostream>
using namespace std;

int main(){
//	freopen("aa.txt","r",stdin);
	int arr[100050][2];
	int i, j;
	int a, b ,c;
	int start, k, n;
	scanf("%d %d %d", &start, &n, &k);
	for(i = 0; i < n; i++){
		scanf("%d %d %d", &a, &b, &c);
		arr[a][0] = b;
		arr[a][1] = c;	
	}
	int output[100050][2];
	a = start;
	int s = n / k;
	for(i = 0; i < s; i++){
		for(j = i * k; j < i * k + k; j++){
			output[2 * i * k + k - j - 1][0] = a;
			output[2 * i * k + k - j - 1][1] = arr[a][0];
			a = arr[a][1];
		}
	}
	for(;j < n; j++){
		output[j][0] = a;
		output[j][1] = arr[a][0];
		a = arr[a][1];
	}
	for(i = 0; i < n - 1; i++) printf("%05d %d %05d\n", output[i][0], output[i][1], output[i+1][0]);
	printf("%05d %d -1\n", output[n-1][0], output[n-1][1]);

	return 0;
}    

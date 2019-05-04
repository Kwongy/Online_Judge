#include<stdio.h>

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
	int output[10000][2];
	a = start;
	if(k > n) k = n;
	for(i = 0; i < k; i++){
		
		output[i][0] = a;
		output[i][1] = arr[a][0];
		a = arr[a][1];
		if(a == -1){
			for(j = i; j > 0; j--){
				printf("%05d %d %05d\n",output[j][0], output[j][1], output[j - 1][0]);
			}
			printf("%05d %d %d\n", output[0][0], output[0][1], -1);
			return 0;
		}
	}
	if(k < n){
		for(i = k - 1; i > 0; i--){
			printf("%05d %d %05d\n", output[i][0], output[i][1], output[i-1][0]);
		}
		printf("%05d %d %05d\n", output[0][0], output[0][1], a);
		while(arr[a][1] != -1){
			printf("%05d %d %05d\n", a, arr[a][0], arr[a][1]);
			a = arr[a][1];
		}
		printf("%05d %d %d\n", a, arr[a][0], arr[a][1]);
	}else{
		for(i = n - 1; i > 0; i--){
			printf("%05d %d %05d\n", output[i][0], output[i][1], output[i-1][0]);
		}
		printf("%05d %d %d\n", output[0][0], output[0][1], -1);
	}
	return 0;
}

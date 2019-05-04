#include<stdio.h>

int arr[10005];
int count = 0;
void adjustdown(int len, int vex){
	int i;
	arr[0] = arr[vex];
	for(i= 2 * vex; i <= len; i *= 2){
		if(i < len && arr[i] > arr[i+1]){
			i++;
		}
		if(arr[0] <= arr[i]) break;
		else{
			arr[vex] = arr[i];
			vex = i;
		}
	}
	arr[vex] = arr[0];
}
void headsort(int len){
	int i;
	for(i = len/2; i > 0; i--){
		adjustdown(len, i);
	}
}

int main(){
//	freopen("aa.txt","r",stdin);
	// 7-29 优先队列 
	int n; int a, i, b;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	int count = 0;
	headsort(n);
	while(n != 1){
		a = arr[1];
		arr[1] = arr[n];
		adjustdown(--n, 1);
		b = arr[1];
		arr[1] = a + b;
		adjustdown(n, 1);
		count += a + b;
	}
	printf("%d", count);
	return 0;
}

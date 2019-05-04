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
	freopen("aa.txt","r",stdin);
	// 7-29 优先队列 
	int n, m, i, a;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= m; i++){
		scanf("%d", &arr[i]);
	}
	headsort(m);
	int b = n - m;
	for(i = 0; i < b; i++){
		scanf("%d", &a);
		if(a > arr[1]){
			arr[1] = a;
			adjustdown(m, 1);
		}
	}
	int flag = 0;
	b = m; 
	int out[20];
	for(i = 1; i <= m; i++){
		out[i] = arr[1];
		arr[1] = arr[b--];
		adjustdown(b, 1);
	}
	printf("%d", out[m]);
	for(i = m - 1; i > 0; i--){
		printf(" %d", out[i]);
	}
	return 0;
}

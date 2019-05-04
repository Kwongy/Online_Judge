#include<stdio.h>

void hanio(int n, char a, char b, char c){
	if(n == 1){
		printf("%c -> %c\n",a, c);
		return;
	}else{	
		hanio(n - 1, a, c, b);
		printf("%c -> %c\n",a, c);
		hanio(n - 1, b, a, c);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	hanio(n, 'a', 'b', 'c');
	
//	printf("\n\n\n\n");
//	char stack[10000][3];
//	int index = 0;
//	
//	while(n != 1){
//		stack
//	}
	return 0;
}

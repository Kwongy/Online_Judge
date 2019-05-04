#include<bits/stdc++.h>
using namespace std;
int Mean(int a, int b) {
	int c = a + b;
	if(c & 1){
		if(c > 0) c--;
		else c++;
	}
	return c / 2;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", Mean(a, b));
    return 0;
}

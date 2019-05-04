#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
//	freopen("aa.txt","r",stdin);
	char s[8], a[8], b[8], d[8], c[8] = {'0','0','0','0'}, f[8] = {'6','1','7','4'};
	int flag = 1;
	scanf("%s", s);
	if(strlen(s) != 4){
		for(int i = strlen(s); i < 4; i++){
			s[i] = '0';
		}
	}
	while(flag){
		strcpy(b, s);
		strcpy(a, s);
		sort(a, a+4);
		sort(b, b+4,greater<int>());
		strcpy(d, b);
		for(int i = 3; i > 0; i--){
			b[i] = b[i] - a[i] + '0';
			if(b[i] < '0'){
				b[i] += 10;
				b[i - 1] --;
			}
		}
		b[0] = b[0] - a[0] + '0';
		cout << d << " - " << a << " = ";
		cout << b << endl;
		if(strcmp(b , c) == 0||strcmp(b, f) == 0){
			break;
		}
		strcpy(s, b);		
	}
	return 0;
}

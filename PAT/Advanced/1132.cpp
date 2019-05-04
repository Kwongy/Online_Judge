#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i, n; char ch[100];
	scanf("%d", &n);
	getchar();
	for(i = 0;i < n;i ++){
		scanf("%s", ch);
		int a = 0, b = 0, c = 0;
		int len = strlen(ch);
		int t = len / 2;
		for(int j = 0; j < t; j++){
			 a = a * 10 + (ch[j] - '0');
			 c = c * 10 + ch[j] - '0';
		}
		for(int j = t; j < len; j++){
			b = b * 10 + (ch[j]- '0');
			c = c * 10 + (ch[j] - '0');
		}
		if(a == 0 || b == 0 || c == 0) cout << "No\n";
		else if(c%(a * b) == 0) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}

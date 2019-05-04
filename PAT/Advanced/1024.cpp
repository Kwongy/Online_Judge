#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool check(char *s){
	bool result = true;
	int n = strlen(s);
	for(int i = 0; i < n/2; i++){
		if(s[i] != s[n-i-1]){
			result = false;
			break;
		}
	}
	return result;
}
void strback(char *s,char *c){
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		c[i] = s[n-i-1];
	}
}
void stradd(char *s,char *c){
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		s[i] += (c[i] - '0');
		if(s[i] > '0' + 9){
			s[i] -= 10;
			s[i+1]++;
		}
	}
	if(s[n] == 1){
		s[n] += '0';
	}
	n = strlen(s);
	for(int i = 0; i < n/2; i++){
		char q = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = q;
	}
}
int main(){
	char s[10000];
	int k;
	cin >> s >> k;
	if(check(s)){
		cout << s << endl << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= k; i++){
		char c[10000];
		strback(s,c);
		stradd(s,c);
		if(check(s)){
			cout << s << endl << i << endl;
			return 0; 
		}
	}
	cout << s << endl<< k;
	return 0;
}

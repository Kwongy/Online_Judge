#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<vector>
using namespace std;
int main(){
//	freopen("aa.txt","r",stdin);
	char c;
	int s[30];
	int cn1[10],cn2[10];
	for(int i = 0; i < 10; i++) cn1[i]=cn2[i]=0;
	bool ok = true;
	int count = 0;
	int flag = 0;
	while(ok){
		c = getchar();
		if(c < '0' || c > '9') break;
		s[count++] = c - '0';
	}
	for(int i = count - 1; i >= 0; i--){
		cn1[s[i]]++;
		s[i] = 2*s[i];
	}
	for(int i = count - 1; i >= 0; i--){
		if(s[i] >= 10){
			s[i] -= 10;
			s[i-1]++;
			if(s[0] >= 10){
				flag = 1;
			}
		}
		cn2[s[i]]++;
	}
	ok = true;
	for(int i = 1; i < 10; i++){
		if(cn1[i] != cn2[i]) ok =false;
	}	
	if(!ok) cout << "No" << endl;
	else{
		cout << "Yes" <<endl;
	}
	if(flag) cout << flag;
	for(int i = 0; i < count ; i++){
			cout << s[i] ;
		}
	return 0;
}

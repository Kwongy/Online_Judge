#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("aa.txt","r",stdin);
	string a ,b;
	getline(cin,a);
	getline(cin,b);
	int hash[200];
	int lena = a.length();
	int lenb = b.length();
	memset(hash,0,sizeof(hash));
	for(int i = 0; i < lenb; i++){
		hash[(int)b[i]]++;
	}
	for(int i = 0; i < lena; i++){
		if(hash[(int)a[i]] == 0){
			cout << a[i];
		}
	}
	return 0;
} 

#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
bool isok[256] = {0};
int main()
{
	freopen("aa.txt","r",stdin);
	set<char> s, s1;
	int n, k;
	string str;
	cin >> k >> str;
	n = str.length();
	int flag, j;
	for(int i = 0; i < 256; i++){
		flag = 0, j = 0;
		for(; j < n; j++){
			if(str[j] == i) {
				flag = 1;
				break;
			}
		}
		if(flag && j < n - k){
			int q = 1;
			for(int t = j + 1; t < j + k; t ++){
				if(str[t-1] == str[t]) q++;
			}
			if(q >= k){
				 isok[str[j]] = true;
				 s.insert(str[j]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(s.find(str[i]) !=  s.end() && s1.find(str[i]) == s1.end()){
			printf("%c",str[i]);
			s1.insert(str[i]);
		}
	}
	cout << endl;
	for(int i = 0; i < n; i++) {
        printf("%c", str[i]);
        if(isok[str[i]]) i = i + k - 1;
    }
	return 0;
}

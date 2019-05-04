#include<bits/stdc++.h>
using namespace std;
int arr[10005];
char str[10005];
int main(){
	int t;
	cin >> t;
	for(int q = 0; q < t; q++){
		string s;
		memset(arr, 0, sizeof(arr));
		cin >> s;
		char before = s[0];
		int cnt = 1;
		int i = 0;
		for(int j = 1; j < s.size(); j++){
			if(s[j] == before){
				cnt++;
				if(cnt == 256){
					cnt = 1;
					arr[i] = 255;
					str[i++] = before;
				}
			}else{
				arr[i] = cnt;
				str[i++] = before;
				cnt = 1;
				before = s[j];
			}
		}
		arr[i] = cnt;
		str[i++] = before;
		cout << "case #" << q << ":\n";
		for(int j = 0; j < i; j++) cout << arr[j] << str[j];
		cout << endl; 
	}
	return 0;
} 

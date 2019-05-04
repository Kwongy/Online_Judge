#include<iostream>
#include<map>
using namespace std;
int main(){
//	freopen("aa.txt","r",stdin);
	map<char, int> mp;
	string s, t;
	cin >> s >> t;
	bool ok = true;
	int len1 = s.length(), len2 = t.length();
	for(int i = 0; i < len1; i++){
		if(mp.find(s[i]) != mp.end()) mp[s[i]] ++;
		else mp[s[i]] = 1;
	}
	int low = 0;
	for(int i = 0; i < len2; i++){
		if(mp.find(t[i]) != mp.end() && mp[t[i]] != 0){
			mp[t[i]] --;
		}else{
			low ++;
			ok = false;
		}
	} 
	if(ok) cout << "Yes " << len1 - len2 << endl;
	else cout << "No " << low << endl;
	return 0;
}

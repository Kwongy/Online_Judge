#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n; cin >> n;
	string s;
	for(int t = 0; t < n; t++){
		cout << "case #" << t << ":" << endl;
		s.erase(s.begin(), s.end()); 
		cin >> s;
		sort(s.begin(), s.end());
		s.resize(unique(s.begin(), s.end()) - s.begin()); 	// unique函数去重 返回最后一个元素的迭代器
		int sz = s.size();
		int sum = ~((-1)<<sz) + 1;
		set<string> st;
		st.clear();
		while(sum-- > 1){	//二进制枚举 
			string temp;
			for(int d = 1, i = 0; i < sz; d <<= 1, i++){
				if(sum&d) temp += s[i];
			}
			st.insert(temp);
		}
		for(string x:st) cout << x << endl;
	}
	
	return 0;
}

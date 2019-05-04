#include<bits/stdc++.h>
using namespace std;
set<int> diff[10005], same[10005];
bool gender[10005];
int n, m, k;
int main(){
	freopen("aa.txt","r",stdin);
	string a, b;
	int c, d;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		c = abs(atoi(a.c_str())); d = abs(atoi(b.c_str()));
		if(a[0] == '-') gender[c] = true;
		if(b[0] == '-') gender[d] = true;
		if(a.size() == b.size()){
			same[c].insert(d);
			same[d].insert(c);
		}else{
			diff[c].insert(d);
			diff[d].insert(c);
		}
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		c = abs(atoi(a.c_str())); d = abs(atoi(b.c_str()));
		vector<int> ans;
		if(a.size() == b.size()){
			for(set<int>::iterator it = same[c].begin(); it != same[c].end(); it++){
				if(*it == d) continue;
				for(set<int>::iterator iter = same[*it].begin(); iter != same[*it].end(); iter++){
					if(*iter == c) continue;
					if(same[d].find(*iter) != same[d].end()){
						ans.push_back(*it);
						ans.push_back(*iter);
					}
				}
			}
		}else{
			for(set<int>::iterator it = same[c].begin(); it != same[c].end(); it++){
				for(set<int>::iterator iter = diff[*it].begin(); iter != diff[*it].end(); iter++){
					if(same[d].find(*iter) != same[d].end()){
						ans.push_back(*it);
						ans.push_back(*iter);
					}
				}
			}
		}
		cout << ans.size() / 2 << endl;
		for(int j = 0; j < ans.size(); j += 2){
			printf("%04d %04d\n", ans[j], ans[j+1]);
		}
	}
	return 0;
}

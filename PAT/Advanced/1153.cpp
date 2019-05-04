#include<bits/stdc++.h>
using namespace std;
typedef struct{
	string name;
	int score;
}node;
typedef struct{
	int num;
	int peo;
}nd;
int cmp1(nd a, nd b){
	if(a.peo != b.peo) return a.peo > b.peo;
	else return a.num < b.num;
}
vector<node> vec[3];	// 0 B, 1 A, 2 T 
map<string, vector<node> > mp;
int grade[2000];
int people[2000];
int cmp(node a, node b){
	if(a.score != b.score) return a.score > b.score;
	else return a.name < b.name;	
}
int main(){
//	freopen("aa.txt","r",stdin);
	int n, k; cin >> n >> k;
	int a;
	memset(grade, 0, sizeof(grade));
	memset(people, 0, sizeof(grade));
	string s, str;
	for(int i = 0; i < n; i++){
		cin >> s >> a;
		node d;
		d.name = s;
		d.score = a;
		if(s[0] == 'B') vec[0].push_back(d);
		else if(s[0] == 'A') vec[1].push_back(d);
		else vec[2].push_back(d);
		str = s.substr(4, 6);
		mp[str].push_back(d);
		int t = (s[1]-'0') * 100 + (s[2]-'0')*10 + s[3] - '0';
		people[t]++;
		grade[t] += a;
	}
	sort(vec[0].begin(), vec[0].end(), cmp);
	sort(vec[1].begin(), vec[1].end(), cmp);
	sort(vec[2].begin(), vec[2].end(), cmp);
	for(int i = 1; i <= k; i++){
		cin >> a >> s;
		cout << "Case " << i << ": "<< a << " " << s << endl;
		if(a == 1){
			if(s[0] == 'B'){
				n = vec[0].size();
				for(int j = 0; j < n; j++){
					cout << vec[0][j].name << " " << vec[0][j].score << endl;
				}
			}else if(s[0] == 'A'){
				n = vec[1].size();
				for(int j = 0; j < n; j++){
					cout << vec[1][j].name << " " << vec[1][j].score << endl;
				}
			}else{
				n = vec[2].size();
				for(int j = 0; j < n; j++){
					cout << vec[2][j].name << " " << vec[2][j].score << endl;
				}
			}
		}else if(a == 2){
		    n = (s[0]-'0') * 100 + (s[1]-'0')*10 + s[2] - '0';
		    if(people[n]) cout << people[n] << " " << grade[n] << endl;
		    else cout << "NA" << endl;
		}else{
			if(mp.find(s) == mp.end()) cout << "NA" << endl;
			else{
				vector<nd> out;
				int po[2000];
				memset(po, 0, sizeof(po));
				for(int j = 0; j < mp[s].size(); j++){
					int cnt = ((mp[s][j].name)[1] - '0') * 100 + ((mp[s][j].name)[2] - '0') * 10 + (mp[s][j].name)[3] - '0';
					po[cnt]++;
				} 
				for(int j = 100; j < 1000; j++){
					if(po[j]){
						nd e;
						e.num = j;
						e.peo = po[j];
						out.push_back(e);
					}
				}
				sort(out.begin(), out.end(), cmp1);
				for(int j = 0; j < out.size(); j++){
					cout << out[j].num << " " << out[j].peo << endl;
				}
			}
		}
	}
	return 0;
}

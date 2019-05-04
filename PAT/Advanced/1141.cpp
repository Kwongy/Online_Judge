#include<bits/stdc++.h>
using namespace std;
struct sch{
	int cnt;
	double grade;
	int rank;
	string name;
};
vector<sch> vec;
map<string, sch> mp;
int cmp(const sch a, const sch b){
	if((int)(a.grade) != (int)(b.grade)) return (int)(a.grade) > (int)(b.grade);
	else if(a.cnt != b.cnt) return a.cnt < b.cnt;
	else return a.name < b.name;
}
int main(){
	freopen("aa.txt","r",stdin);
	int n; cin >> n;
	string s, name;
	int score;
	for(int i = 0; i < n; i++){
		cin >> name >> score >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);	
		if(mp.find(s) != mp.end()){
			if(name[0] == 'A'){
				mp[s].grade += score * 1.0;
			}else if(name[0] == 'B'){
				mp[s].grade += score / 1.5;
			}else mp[s].grade += score * 1.5;
			mp[s].cnt++;
		}else{
			if(name[0] == 'A'){
				mp[s].grade = score * 1.0;
			}else if(name[0] == 'B'){
				mp[s].grade = score / 1.5;
			}else mp[s].grade = score * 1.5;
			mp[s].name = s;
			mp[s].cnt = 1;
		}
	}
	map<string, sch>::iterator it = mp.begin();
	for(; it != mp.end(); it++){
		vec.push_back(it->second);
	}
	sort(vec.begin(), vec.end(),cmp);
	n = vec.size();
	cout << n << endl << 1 << " " << vec[0].name << " " << int(vec[0].grade) << " " << vec[0].cnt << endl;
	vec[0].rank = 1;
	for(int i = 1; i < vec.size(); i++){
		if(int(vec[i].grade) != int(vec[i-1].grade)) {
			cout << i + 1;
			vec[i].rank = i + 1;
		}else{
			cout << vec[i-1].rank;
			vec[i].rank = vec[i-1].rank;
		}
		cout << " " << vec[i].name << " " << int(vec[i].grade) << " " << vec[i].cnt << endl;	
	}
	return 0;
} 

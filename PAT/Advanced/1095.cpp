#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int time;
	int flag;
}node;
// flag == 0 out
// flag == 1 in
int cmp(node a, node b){
	return a.time < b.time;
}
map<string, vector<node> > mp;
int solve_time(string s){
	int ans = ((s[0]-'0')*10 + s[1] - '0') * 3600 + ((s[3]-'0')*10 + s[4]-'0') * 60 + (s[6]-'0')*10 + s[7] - '0';
	return ans;
}
void print_time(int s){
	int h = s / 3600;
	s = s % 3600;
	int m = s / 60;
	s = s % 60;
	printf("%02d:%02d:%02d\n", h, m, s); 
}
int ck[90000];
int cnt = 0;
int maxn = 0;
vector<string> outname(10005);
int main(){
	int n, k;
	cin >> n >> k;
	string a, b, c;
	memset(ck, 0, sizeof(ck));
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		int time = solve_time(b);
		node nd;
		nd.time = time;
		if(c == "in") nd.flag = 1;
		else nd.flag = 0;
		mp[a].push_back(nd);
	}
	map<string, vector<node> >::iterator it = mp.begin();
	for(; it != mp.end(); it++){
		int temp = 0;
		sort((it->second).begin(), (it->second).end(), cmp);
		int sz = (it->second).size();
		int f = 0, before = 0;
		for(int i = 0; i < sz; i++){
			if(f == 0 && (it->second)[i].flag == 1){
				f = 1;
				before = i;
			}else if(f == 1 && (it->second[i].flag == 0)){
				f = 0;
				for(int j = (it->second)[before].time; j < (it->second)[i].time; j++){
					ck[j]++;
				}
				temp += (it->second)[i].time - (it->second)[before].time;
			}else if(f == 1 && (it->second)[i].flag == 1) before = i;
		}
		if(temp > maxn){
			maxn = temp;
			outname[0] = it->first;
			cnt = 1;
		}else if(temp == maxn){
			outname[cnt++] = it->first;
		}
	}
	for(int i = 0; i < k; i++){
		cin >> a;
		int time = solve_time(a);
		cout << ck[time] << endl;
	}
	sort(outname.begin(), outname.begin() + cnt);
	for(int i = 0; i < cnt; i++){
		cout << outname[i] <<  " ";
	}
	print_time(maxn);
	
	return 0;
}

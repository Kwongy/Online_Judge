#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
map<string,int> weight;
map<string,vector<string> > list;
map<string,int> output;
map<string,int> visit;
int cnt,total;
string head;
void dfs(string start){
	visit[start] = 1;
	cnt ++;
	total += weight[start];
	if(weight[start] > weight[head]) head = start;
	for(vector<string>::iterator it = list[start].begin(); it != list[start].end(); it++){
		if(!visit[*it]) dfs(*it);
	}
}
int main(){
	freopen("aa.txt","r",stdin);
	int n, m, d; cin >> n >> m;
	string a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> d;
		if(weight.find(a) != weight.end()) weight[a] += d;
		else weight[a] = d;
		if(weight.find(b) != weight.end()) weight[b] += d;
		else weight[b] = d;
		visit[a] = 0;
		visit[b] = 0;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	for(map<string,int>::iterator it = visit.begin(); it != visit.end(); it++){
		if(it->second == 0){
			cnt = 0;
			total = 0;
			head = it->first;
			dfs(head);
		}
		if(cnt > 2 && total/2 > m) output[head]=cnt; 
	}
	cout << output.size() << endl;
	for(map<string,int>::iterator it = output.begin(); it != output.end(); it ++){
		cout << it->first  << " " << it -> second << endl;
	} 
	return 0;
} 

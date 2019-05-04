#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > vec;
int n, m;
int vis[1005];
void bfs(int k){
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
	}
	queue<int> q;
	q.push(k);
	vis[k] = 1;
	int cnt = 0;
	int level = 0, last = k, tail = k;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 0; i < vec[v].size(); i++){
			int c = vec[v][i];
			if(!vis[c]){
				vis[c] = 1;
				q.push(c);
				tail = c;
			}
		}
		if(level <= m && level >= 1){
			cnt++;
		}
		if(v == last){
			level++;
			last = tail;
		}
		if(level > m) break;
	}
	printf("%d\n", cnt);
}

int main(){
//	freopen("aa.txt","r",stdin);
	
	cin >> n >> m;
	int k, a;
	vec.resize(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &a);
			vec[a].push_back(i); 
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i ++){
		scanf("%d", &a);
		bfs(a);
	}
	
	return 0;
}

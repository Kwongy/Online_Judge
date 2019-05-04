#include<iostream>
#include<vector>
#include<queue>
#define DEBUG 0 
using namespace std;
int n, m;
vector<int> node[100];
vector<int> vis(100,0);
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	scanf("%d %d", &n, &m);
	int k, current, next;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &current, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &next);
			node[current].push_back(next);
		}
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int tail, sum = 0;
	int last = 1, cnt = 1;
	int level = 1 , ans = 1;
	while(q.size() != 0){		
		int now = q.front();
		q.pop();
		for(int i = 0; i < node[now].size(); i++){
			if(!vis[node[now][i]]){
				q.push(node[now][i]);
				vis[node[now][i]] = 1;
				tail = node[now][i];
				sum++;
			}
		}
		if(now == last){			//上一层最后一个出队了，那么Last等于这一层最后一个 
			last = tail;
			cnt ++;
			if(ans < sum){			//修改层数和人数 
				ans = sum;
				level = cnt;
			}
			sum = 0;
		}
	}
	cout << ans << " " << level;
}

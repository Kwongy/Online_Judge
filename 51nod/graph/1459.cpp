#include<bits/stdc++.h>
using namespace std;
#define MAX 505 
const int INF = 1 << 30;
int vis[MAX];
int graph[MAX][MAX];
int spend[MAX];
int value[MAX];
int ans[MAX];
int n, m, s, e;
void dijkstra(){
	int minn, k;
	for(int i = 0; i < n; i++){		// dijkstra 
		minn = INF;
		k = s;
		for(int j = 0; j < n; j++){
			if(!vis[j] && spend[j] < minn){
				k = j;
				minn = spend[j];
			}
		}
		vis[k] = 1;
		for(int j = 0; j < n; j++){
			if(!vis[j]){
				if(spend[j] > spend[k] + graph[k][j]){
					spend[j] = spend[k] + graph[k][j];
					ans[j] = ans[k] + value[j];
				}else if(spend[j] == spend[k] + graph[k][j]){
					ans[j] = max(ans[j], ans[k] + value[j]);
				}
			}
		}
	}
	printf("%d %d\n", spend[e], ans[e]);
	
}
int main() {
	cin >> n >> m >> s >> e;
	for(int i = 0; i < n; i++) cin >> value[i]; 
	int a, b, c;
	fill(graph[0], graph[0] + MAX * MAX, INF);
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	for(int i = 0; i < n; i++){
		vis[i] = 0;
		spend[i] = INF;
	}
	vis[s] = 1;
	spend[s] = 0;
	ans[s] = value[s]; 			// init()
	dijkstra();
    return 0;
}

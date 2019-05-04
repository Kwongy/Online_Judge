#include<bits/stdc++.h>
using namespace std;
int graph[505][505];
int degree[505] = {0};
int vis[505] = {0};
int n;
void dfs(int vex){
	for(int i = vex + 1; i <= n; i++){
		if(!vis[i] && graph[vex][i]){
			vis[i] = 1;
			dfs(i);
		}
	}
}
int main(){
//	freopen("aa.txt","r",stdin);
	
	int m; 
	scanf("%d %d", &n, &m);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
		degree[a]++;
		degree[b]++; 
	}
	int cnt = 0, flag = 1;
	vis[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(degree[i] & 0x01) cnt++;
		if(!vis[i]) flag = 0;
	}
	for(int i = 1; i < n; i++){
		printf("%d ", degree[i]);
	}
	printf("%d\n", degree[n]);
	if(flag){
		if(cnt == 0) printf("Eulerian\n");
		else if(cnt == 2) printf("Semi-Eulerian\n");
		else printf("Non-Eulerian\n");
	}else{
		printf("Non-Eulerian\n");
	}
	
	return 0;
}


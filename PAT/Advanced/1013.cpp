#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int maze[1010][1010];
int vis[1010],count,n;
void dfs(int c){
	vis[c] = 1;
	for(int i = 1; i <= n; i++){
		if(!vis[i] && maze[c][i]){
			dfs(i);
		}
	}
}
int main(){
	int m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a,b,cnt;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&a,&b);
		maze[a][b] = maze[b][a] = 1;
	}
	for(int i = 0; i < k; i++){
		scanf("%d",&a);
		memset(vis,0,sizeof(vis));
		cnt = 0;
		vis[a] = 1;
		for(int j = 1; j <= n; j++){   	//深搜计算连通性 
			if(!vis[j]){
				dfs(j);
				cnt++;
			}
		}
		printf("%d",cnt-1);
	}
	
	
	return 0;
}

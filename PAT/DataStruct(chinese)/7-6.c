#include<stdio.h>

int n, m;
int graph[15][15];
int vis[15];
void dfs(int vex){
	if(vis[vex]) return;
	vis[vex] = 1;
	int i, j;
	for(i = 0; i < n; i++){
		if(i == vex) continue;
		if(graph[vex][i] == 1 && !vis[i]){
			printf(" %d", i);
			dfs(i);
		}
	}
}
int main(){
	freopen("aa.txt","r",stdin);
	
	scanf("%d %d", &n, &m);
	int i, j;
	for(i = 0; i < n; i++){
		vis[i] = 0;
		for(j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}
	int a, b;
	for(i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	for(i = 0; i < n; i++){
		if(!vis[i]){
			printf("{ %d", i);
			dfs(i);
			printf(" }\n");
		}
	}
	
	int arr[20];
	int front = 0;
	int rear = 0;
	for(i = 0; i < n; i++){
		vis[i] = 0;
	}
	for(i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = 1;
			front = 0;
			rear = 0;
			arr[front++] = i;
			printf("{");
			while(rear < front){
				int now = arr[rear];
				printf(" %d",now);
				rear++;
				for(j = 0; j < n; j++){
					if(graph[now][j] == 1 && !vis[j]){
						arr[front++] = j;
						vis[j] = 1;
					}
				}
			}
			printf(" }\n");
		}
	}
	return 0;
}

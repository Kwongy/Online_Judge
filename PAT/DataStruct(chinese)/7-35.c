#include<stdio.h>
#define NA 1 << 20
int n, m , s, d;
int graph[505][505];
int value[505];
int count = 0;	
int shortpath[505];
int spend[505];
int vis[505];
int total[505];
void dfs(int vex, int sum){
	if(sum == spend[d] && vex == d){
		count++;
		return;
	}else if(sum > shortpath[d]){
		return;
	}
	int i = 0;
	for(; i < n; i++){
		if(!vis[i]){
			sum += graph[vex][i];
			vis[i] = 1;
			dfs(i, sum);
			sum -= graph[vex][i];
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("aa.txt","r",stdin);
	
	int i, j;
	scanf("%d %d %d %d", &n, &m, &s, &d);

	
	for(i = 0; i < n; i++){
		scanf("%d", &value[i]);
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			graph[i][j] = NA;
		}
	}
	
	int a, b, c;
	for(i = 0; i < m; i ++){
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}
	
	for(i = 0; i < n; i++){
		spend[i] = graph[s][i];
		shortpath[i] = 0;
		vis[i] = 0;
		total[i] = value[i];
	}
	
	
	// dijkstra
	vis[s] = 1;
	for(i = 0; i < n; i++){
		if(i == s) continue;
		int k = -1;
		int mini = NA;
		for(j = 0; j < n; j++){
			if(!vis[j] && spend[j] < mini){
				mini = spend[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(j = 0; j < n; j++){
			if(!vis[j]){
				if(spend[k] + graph[k][j] < spend[j]){
					spend[j] = spend[k] + graph[k][j];
					shortpath[j] = k;
					total[j] = total[k] + value[j];
				}else if(spend[k] + graph[k][j] == spend[j]){
					if(total[k] + value[j] > total[j])
					{
						shortpath[j] = k;
				   		total[j] = total[k] + value[j];
				    }
					
				}
			}
		}
	}
	for(i = 0; i < n; i++){
		vis[i] = 0;
	}
	vis[s] = 1;
	dfs(s, 0);
	printf("%d %d\n", count, total[s] + total[d]);
	
	int path[505], index = 0;
	a = d;
	while(a != s){
		path[index++] = a;
		a = shortpath[a];
	}
	printf("%d",s);
	for(i = index - 1; i >= 0; i--){
		printf(" %d",path[i]);
	}

	return 0;
}

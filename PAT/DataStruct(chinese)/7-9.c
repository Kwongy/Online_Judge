#include<stdio.h>
#define MAX 1 << 20
struct fee{
	int spend;
	int length;
};
struct fee graph[505][505];
int main(){
	freopen("aa.txt","r",stdin);
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	int vis[505], totalSpend[505], totalLen[505];
	int path[505];
	int i, j, k, node1, node2, input1, input2;
	for(i = 0; i < n; i++){
		vis[i] = 0;
		totalLen[i] = 0;
		path[i] = 0;
		totalSpend[i] = 0;
		for(j = 0; j < n; j++){
			graph[i][j].length = MAX;
			graph[i][j].spend = MAX;
		}
	}
	for(i = 0; i < m; i++){
		scanf("%d %d %d %d", &node1, &node2, &input1, &input2);
		graph[node1][node2].length = input1;
		graph[node1][node2].spend = input2;
		graph[node2][node1].length = input1;
		graph[node2][node1].spend = input2;
	}
	for(i = 0; i < n; i++){
		totalSpend[i] = graph[s][i].spend;
		totalLen[i] = graph[s][i].length;	
	}
	int min, cost;
	vis[s] = 1;
	for(i = 0; i < n; i++){		
		min = MAX;
		for(j = 0; j < n; j++){
			if(!vis[j] && totalLen[j] < min){
				k = j;
				min = totalLen[j];
				cost = totalSpend[j];
			}
		}
		vis[k] = 1;
		for(j = 0; j < n; j++){
			if(!vis[j]){
				if(min + graph[k][j].length < totalLen[j]){
					totalLen[j] = min + graph[k][j].length;
					totalSpend[j] = cost + graph[k][j].spend;
				}else if(min + graph[k][j].length == totalLen[j]){
					if(cost + graph[k][j].spend < totalSpend[j])	totalSpend[j] = cost + graph[k][j].spend;
				}
			}
		}	
	}
	printf("%d %d", totalLen[d], totalSpend[d]);
	return 0;
}






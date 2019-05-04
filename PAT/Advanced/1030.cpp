#include<iostream>
#include<stack>
#define DEBUG 1
const int MAX = 505; 
const int INF = 1 << 20;
struct NODE{
	int distance;
	int cost;
};
using namespace std;
int n, start, END;
int shortPath[MAX];
int path[MAX];
int spend[MAX];
NODE maze[MAX][MAX];
void dijkstra(){
	bool vis[n];
	for(int i = 0; i < n; i++){
		vis[i] = false;
		path[i] = -1;
		spend[i] = maze[start][i].cost;
		shortPath[i] = maze[start][i].distance;
	}
	vis[start] = true;
	for(int i = 0; i < n; i++){
		if(i == start) continue;
		int min = INF;
		int k = start;
		for(int j = 0; j < n; j++){
			if(!vis[j] && shortPath[j] < min){
				k = j;
				min = shortPath[j];
			}
		}
		vis[k] = true;
		for(int j = 0; j < n; j++){
			if(!vis[j] && (min + maze[k][j].distance) <= shortPath[j]){
				if((min + maze[k][j].distance) != shortPath[j]){
					shortPath[j] = min + maze[k][j].distance;
					spend[j] = spend[k] + maze[k][j].cost; 
					path[j] = k;
				}else{
					if(spend[k] + maze[k][j].cost < spend[j]){
						shortPath[j] = min + maze[k][j].distance;
						spend[j] = spend[k] + maze[k][j].cost; 
						path[j] = k;
					}
				}
			}
		}
	}
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif

	int m, s, e, d, c;
	scanf("%d %d %d %d", &n, &m, &start, &END);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			maze[i][j].distance = INF;
			maze[i][j].cost = INF;
		} 
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d %d %d", &s, &e, &d ,&c);
		if(maze[s][e].distance > d){
			maze[s][e].distance = d;
			maze[s][e].cost = c;
			maze[e][s].distance = d;
			maze[e][s].cost = c;
		}
		if(maze[s][e].distance == d && c < maze[s][e].cost){
			maze[s][e].distance = d;
			maze[s][e].cost = c;
			maze[e][s].distance = d;
			maze[e][s].cost = c;
		}
	}
	dijkstra();
	stack<int> st;
	int j = END;
	d = c = 0;	
	while(j != -1){
		st.push(j);
		if(path[j] != -1){
			c += maze[path[j]][j].cost;
			d += maze[path[j]][j].distance;	
		}else{
			c +=  maze[start][j].cost;
			d += maze[start][j].distance; 
		}
		j = path[j];
	}
	st.push(start);
	while(st.size() != 0){
		printf("%d ", st.top());
		st.pop();
	}
	printf("%d %d\n", d, c);
	return 0;
}

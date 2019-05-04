#include <iostream>
using namespace std;
#define MAX 1<<29
int maze[505][505];
int team[505];
int shortpath[505];
int n,m;
int vis[505];
int spend[505];
int pathsum[505];	
void inition(){
	int i,j;
	int a,b,c;						//a,b,c代表a点到b点所花费的代价c
	for(i=0;i<n;i++){	
		vis[i] = 0;
		spend[i] = MAX;
		cin >> a;
		team[i]	 = a;				//开始时S集内无顶点。 
		for(j=0;j<n;j++){
			maze[i][j] = MAX;		//将邻接矩阵初始化为无穷大，代表都无法到达。 
		}
	} 
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		maze[a][b]=c;				//读入边的信息 
		maze[b][a]=c;
	} 	
}
void Dijkstra(int vertex){
	int min,i,j;
	spend[vertex] = 0;
	pathsum[vertex] = team[vertex];
	shortpath[vertex] = 1;
	for(i = 0;i<n;i++){
		if(i == vertex) continue;
		min = MAX;
		int k = -1;
		for(j = 0; j< n; j++){
			if(!vis[j]&&spend[j]<min){
				k = j;
				min = spend[j];
			}
		}
		vis[k] = 1;
		for(j = 0; j< n; j++){
			if(!vis[j]&&(min+maze[k][j]<spend[j])){	
				spend[j] = min+maze[k][j];
				shortpath[j] = shortpath[k];
				pathsum[j] = pathsum[k] + team[j];
            }  else if(!vis[j]&&(min+maze[k][j] == spend[j])) {
                    shortpath[j] += shortpath[k];
                    if(pathsum[j] < pathsum[k] + team[j])
                       pathsum[j] = pathsum[k] + team[j];
                }
		}
	}
}
int main(){
	int start,end;
	cin >> n >> m >> start >> end;
	inition();
	Dijkstra(start);
	cout << shortpath[end] <<" "<<pathsum[end]<<endl;	
	return 0;
}



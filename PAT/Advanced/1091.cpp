#include<bits/stdc++.h>
using namespace std;
int m, n, l, t;
bool vis[1300][130][80];
int arr[1300][130][80];
int dirx[] = {1, -1, 0, 0, 0, 0};
int diry[] = {0, 0, 1, -1, 0, 0};
int dirz[] = {0, 0, 0, 0, 1, -1};
struct node{
	int x, y, z;
};
bool judge(int x, int y, int z){
	if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
	if(arr[x][y][z] == 0 || vis[x][y][z] == true) return false;
	return true;
}
int bfs(int x, int y, int z){
	int cnt = 0;
	node temp;
	temp.x = x, temp.y = y, temp.z = z;
	queue<node> q;
	q.push(temp);
	vis[x][y][z] = true;
	while(q.size() != 0){
		node tp = q.front();
		q.pop();
		cnt++;
		for(int i = 0; i < 6; i++){
			int tx = dirx[i] + tp.x;
			int ty = diry[i] + tp.y;
			int tz = dirz[i] + tp.z;
			if(judge(tx,ty,tz)){
				vis[tx][ty][tz] = true;
				temp.x = tx, temp.y = ty, temp.z = tz;
				q.push(temp); 
			}
		}
	}
	if(cnt >= t) return cnt;
	else return 0;
}
int main(){
	freopen("aa.txt","r",stdin);
	scanf("%d %d %d %d", &m, &n, &l, &t);
	for(int i = 0; i < l; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++){
				scanf("%d", &arr[j][k][i]);
				vis[j][k][i] = false;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++){
				if(!vis[j][k][i] && arr[j][k][i] == 1) ans += bfs(j, k, i);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

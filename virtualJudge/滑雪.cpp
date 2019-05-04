#include<iostream>
#include<vector> 
using namespace std;
typedef long long ll;
// ¼ÇÒä»¯ËÑË÷ 
int arr[105][105];
int val[105][105];
int n, m;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int dfs(int x, int y){
	if(val[x][y] != -1) return val[x][y];
	int c = 1;
	for(int i = 0; i < 4; i++){
		int tx = dirx[i] + x;
		int ty = diry[i] + y;
		if(tx < 0 || ty < 0 || tx == n || ty == m) continue;
		if(arr[tx][ty] > arr[x][y]) c = max(dfs(tx,ty) + 1, c);
	}
	val[x][y] = c;
	return c;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &arr[i][j]);
			val[i][j] = -1;
		}
	}
	int maxn = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			maxn = max(maxn, dfs(i, j));
		}
	}
	cout << maxn << endl;
	return 0;
}

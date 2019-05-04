#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
int mp[105][105];
int vis[105];
int spend[105];
int w[105][105];
int n, m, cnt[105];
// cnt数组类似spend数组，记录从源点到目标点最短路线的个数 
void dijkstra(){
	int minn, k;
	cnt[1] = 1;
	for(int j = 1; j <= n; j++) spend[j] = mp[1][j];
	for(int i = 1; i <= n; i++){
		minn = INF;
		for(int j = 1; j <= n; j++){
			if(spend[j] < minn && !vis[j]){
				minn = spend[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && spend[j] >= spend[k] + mp[k][j]){
				if(spend[j] > spend[k] + mp[k][j]){
					spend[j] = spend[k] + mp[k][j];	
					cnt[j] = cnt[k] * w[k][j];
				}else{
					cnt[j] += cnt[k] * w[k][j];
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	int a, b, c;
	memset(vis, 0, sizeof(vis));
	memset(w, 0, sizeof(w));
	memset(cnt, 0, sizeof(cnt));
	fill(mp[0], mp[0]+105*105, INF);
	mp[1][1] = 0;					// 只要初始化源点到源点的最短路为0 
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		mp[a][b] = c;
		w[a][b]++;
	}
	dijkstra();
	if(spend[n] == INF){
		spend[n] = -1;
	}
	cout << spend[n] << " " << cnt[n] << endl;
	return 0;
}

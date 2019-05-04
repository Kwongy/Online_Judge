#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > graph(10005);
int findmerge[10005], deep;
int found(int i){
	if(findmerge[i] != i) findmerge[i] = found(findmerge[i]);
	return findmerge[i];
}
void join(int x,int y){
	int fx = found(x), fy = found(y);
	if(fx != fy) findmerge[fy] = fx;
}
void bfs(int i){
	queue<int> q;
	q.push(i);
	int a, b, d = 1;
	deep = findmerge[i] = d;
	int vis[10005];
	memset(vis,0,sizeof(vis));
	vis[i] = 1;
	while(!q.empty()){
		a = q.front();
		q.pop();
		for(unsigned int j = 0; j < graph[a].size(); j++){
			b = graph[a][j];
			if(!vis[b]) {
			  q.push(b);
			  findmerge[b] = findmerge[a] + 1;
			  deep = max(findmerge[b],deep);
			  vis[b] = 1;
			}
		}
	}
}
int main(){
	int n,a,b,cnt = 0; cin >> n;
	for(int i = 1; i <= n; i++){
		findmerge[i] = i;
	}
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		join(a,b);							//ִ�в��鼯 
	}
	for(int i = 1; i <= n; i++){
		if(findmerge[i] == i) cnt++; 		//���鼯findmerge[i]����iʱ˵����һ����ͨ�� 
	}
	if(cnt != 1){
		printf("Error: %d components\n",cnt);
		return 0;
	}
	memset(findmerge,0,sizeof(findmerge));
	bfs(1);									//��һ��bfsѰ�������� 
	int i;
	for(i = 1; i <= n; i++){
		if(findmerge[i] == deep) break;
	}
	memset(findmerge,0,sizeof(findmerge));
	bfs(i);									//�Ե�һ��bfs�ҵ���������ڶ���bfs���õ��ĵ����һ��Ϊ�� 
	findmerge[i] = deep;
	for(i = 1; i <= n; i++){
		if(findmerge[i] == deep){
			printf("%d\n",i);
		}
	}
 	return 0;
} 

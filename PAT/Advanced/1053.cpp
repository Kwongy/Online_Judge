#include<iostream>
#include<vector>
#include<algorithm>
#define DEBUG 0
using namespace std;
struct NODE{
	int value;
	vector<int> child;
};

int target;
vector<NODE> node;
vector<int> path;

bool cmp2(int a, int b){
	return node[a].value > node[b].value;
}

void dfs(int index, int nodeNum, int sum){
	if(sum > target) return;
	if(sum == target){
		if(node[index].child.size() != 0) return;
		for(int i = 0; i < nodeNum; i++) printf("%d%c", node[path[i]].value, i == nodeNum - 1 ? '\n' : ' ');
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		int n = node[index].child[i];
		path[nodeNum] = n;
		dfs(n, nodeNum + 1, sum + node[n].value);
	}
	
}

int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int n, m, c, k;
	scanf("%d %d %d", &n, &m, &target);
	node.resize(n);
	path.resize(n);
	for(int i = 0; i < n; i++) scanf("%d",&node[i].value);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &c, &k);
		node[c].child.resize(k);
		for(int j = 0; j < k; j++)	scanf("%d", &node[c].child[j]);
		sort(node[c].child.begin(),node[c].child.end(),cmp2);
	}
	dfs(0, 1, node[0].value);
	return 0;
} 

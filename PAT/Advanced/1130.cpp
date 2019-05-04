#include<iostream>
#include<vector>
using namespace std;
struct node{
	string val;
	int left, right;
};
vector<node> vec;
int n, root = 1;
string dfs(int index){
	if(index == -1) return "";
	if(vec[index].right != -1){
		vec[index].val = dfs(vec[index].left) + vec[index].val + dfs(vec[index].right);
		if(index != root) vec[index].val = "(" + vec[index].val + ")";
	}
	return vec[index].val;
}
int main(){
	freopen("aa.txt","r",stdin);
	cin >> n;
	vec.resize(n + 1);
	vector<bool> vis(n + 1, false);
	for(int i = 1; i <= n; i++){
		cin >> vec[i].val >> vec[i].left >> vec[i].right;
		if(vec[i].left != -1) vis[vec[i].left] = true;
		if(vec[i].right != -1) vis[vec[i].right] = true;
	}
	while(vis[root] == true) root++;
	cout << dfs(root) << endl;
	return 0;
}

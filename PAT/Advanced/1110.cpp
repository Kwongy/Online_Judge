#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#define DEBUG 1
using namespace std;
struct node{
	int left, right;
	int val;
};
vector<node> tree;
int maxn = -1, ans;
void dfs(int root, int idx) {
    if(idx > maxn) {
        maxn = idx;
        ans = root;
    }
    if(tree[root].left != -1) dfs(tree[root].left, idx * 2);
    if(tree[root].right != -1) dfs(tree[root].right, idx * 2 + 1);
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int n;
	cin >> n;
	tree.resize(n);
	vector<int> nd(n, 0);
	string a, b;
	int c,d;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a[0] == '-') c = -1;
		else {
			c = atoi(a.c_str());
			nd[c]++;
		}
		if(b[0] == '-') d = -1;
		else {
			d = atoi(b.c_str());
			nd[d]++;
		}
		tree[i].right = d;
		tree[i].left = c;
		tree[i].val = i;
	}
	int root = 0;
	while(nd[root] != 0) root++;
	dfs(root, 1);
	if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
	return 0;
}

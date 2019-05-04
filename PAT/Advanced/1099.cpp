#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define DEBUG 1
using namespace std;
struct node{
	int value, left, right;
};
int index;
vector<node> tree;
vector<int> val;
bool cmp(int a, int b){
	return a < b;
}
void inorder(node &root){
	if(root.left != -1){
		inorder(tree[root.left]);
	}
	root.value = val[index];
	index ++;
	if(root.right != -1){
		inorder(tree[root.right]);
	}
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	index = 0;
	tree.resize(n);
	val.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &tree[i].left, &tree[i].right);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
	}
	sort(val.begin(), val.end(), cmp);
	inorder(tree[0]);
	queue<node> q;
	q.push(tree[0]);
	bool flag = false;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		if(t.left != -1){
			q.push(tree[t.left]);
		}
		if(t.right != -1){
			q.push(tree[t.right]);
		}
		if(!flag){
			printf("%d",t.value);
			flag = true;
		}else{
			printf(" %d",t.value);
		}
	}
	return 0;
}

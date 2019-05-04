#include<iostream>
#include<vector>
#include<queue>
#define DEBUG 1
using namespace std;
struct node{
	int left, right;
	int val;
};
int index;
vector<node> tree;
int f = 0;
void inorder(node &root){
	if(root.left != -1){
		inorder(tree[root.left]);
	}
	if(!f){
		printf("%d", root.val);
		f = 1;
	}else{
		printf(" %d", root.val);
	}
	if(root.right != -1){
		inorder(tree[root.right]);
	}
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int n;
	scanf("%d\n", &n);
	index = 0;
	tree.resize(n);
	vector<int> nd(n, 0);
	char a,b;
	int c,d;
	for(int i = 0; i < n; i++){
		scanf("%c %c\n", &a, &b);
		if(a != '-'){
			c = a - '0';
			nd[c]++;
		}else{
			c = -1;
		}
		if(b != '-'){
			d = b - '0';
			nd[d]++;
		}else{
			d = -1;
		}
		tree[i].right = c;
		tree[i].left = d;
		tree[i].val = i;
	}
	int root;
	for(int i = 0; i < n;i++){
		if(nd[i] == 0){
			root = i;
			break;
		}
	}
	queue<node> q;
	q.push(tree[root]);
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
			printf("%d",t.val);
			flag = true;
		}else{
			printf(" %d",t.val);
		}
	}
	printf("\n");
	inorder(tree[root]);
	return 0;
}

#include<iostream>
#include<algorithm>
#define DEBUG 0
using namespace std;
typedef struct node{
	int value;
	struct node *left, *right;
}Tree;
int maxi;
int num[1000];
void create(Tree *&root, int val){
	if(root == NULL){
		root = new Tree();
		root->left = NULL;
		root->right = NULL;
		root->value = val;
		return;
	}
	if(root->value >= val){
		create(root->left, val);
	}else{
		create(root->right, val);
	}
}
void dfs(Tree *root, int level){
	if(root == NULL){
		maxi = max(level, maxi);
		return;
	}
	num[level]++;
	dfs(root->right, level + 1);
	dfs(root->left, level + 1);
}
int main(){
	#if DEBUG
	freopen("aa.txt", "r", stdin);
	#endif
	fill(num, num+1000, 0);
	maxi = 0;
	Tree *root = NULL;
	int n, val; cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		create(root, val);
	}
	dfs(root, 0);
	printf("%d + %d = %d", num[maxi - 1], num[maxi - 2], num[maxi - 1] + num[maxi - 2]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef struct nd{
	int val;
	struct nd *left, *right;
}node;
int n;
int arr[1005];
node * build(int i){
	node *root;
	root = (node *)malloc(sizeof(node));
	if(i <= n){
		root->val = arr[i];
		root->left = build(2 * i);
		root->right = build(2 * i + 1);
	}else{
		root = NULL;
	}
	return root;
}
void dfs(vector<int> vec, node * root){
	if(root->left == NULL && root->right == NULL){
		int t = vec.size();
		for(int i = 0; i < t; i++){
			printf("%d ", vec[i]);
		}
		printf("%d\n", root->val);
		return;
	}else if(root->right == NULL){
		vec.push_back(root->val);
		dfs(vec, root->left);
	}else{
		vec.push_back(root->val);
		dfs(vec, root->right);
		dfs(vec, root->left);
	}
}
int main(){
//	freopen("aa.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	node *root = NULL;
	root = build(1);
	vector<int> v;
	dfs(v, root);
	bool maxn = true, minn = true;
	for(int i = 1; i <= n; i++){
		int a = 2 * i;
		int b = 2 * i + 1;
		if(b <= n){
			if(arr[a] < arr[i] || arr[b] < arr[i]) minn = false;
			if(arr[a] > arr[i] || arr[b] > arr[i]) maxn = false;
		}else if(a <= n){
			if(arr[a] < arr[i]) minn = false;
			if(arr[a] > arr[i]) maxn = false;
		}
	}
	if(maxn) printf("Max Heap\n");
	else if(minn)  printf("Min Heap\n");
	else printf("Not Heap\n");
	
	return 0;
}

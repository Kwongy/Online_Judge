#include<bits/stdc++.h>
using namespace std;
/*
	½¨Ê÷zdfs 
*/
typedef long long ll;
struct node{
	int data;
	struct node *left, *right;
};
vector<int> arr;
node* build(node *root, int value){
	if(root == NULL){
		root = new node();
		root->data = value;
		root->left = root->right = NULL;
	}else if(abs(value) <= abs(root->data)){
		root->left = build(root->left, value);
	}else{
		root->right = build(root->right, value);
	}
	return root;
}
bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->data < 0) {
        if (root->left != NULL && root->left->data < 0) return false;
        if (root->right != NULL && root->right->data < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getNum(node *root) {
    if (root == NULL) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->data > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if (root == NULL) return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}
int main(){
//	freopen("aa.txt","r",stdin);
	int t, n; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		arr.resize(n);
		node *root = NULL;
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			root = build(root, arr[i]);
		}
		if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
	}
		
	
	return 0;
}

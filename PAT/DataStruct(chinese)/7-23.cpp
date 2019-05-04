#include<iostream>

using namespace std;
int n;
string preorder;
string inorder;
int Max = 0;
void dfs(int pre_l, int pre_r, int in_l, int in_r, int level){
	if(pre_l > pre_r || in_l > in_r) return;
	if(level > Max) Max = level;
	char index = preorder[pre_l], i = in_l;
	while(inorder[i] != index) i++;
	cout << index << endl;
	dfs(pre_l + 1, pre_l + i - in_l, in_l, i - 1, level + 1);
	dfs(pre_l + i - in_l + 1, pre_r, i + 1, in_r, level + 1);
}
int main(){
	freopen("aa.txt","r",stdin);
	cin >> n;
	cin >> preorder >> inorder;
	dfs(0, n-1, 0, n-1, 1);
	cout << Max << endl;
	return 0;
}

#include<iostream>
#include<stack>
#include<vector> 
#include<cstring>
#define DEBUG 1
using namespace std;
vector<int> preorder;
vector<int> inorder;
bool flag = false;
void transfer(int pre_l, int pre_r, int in_l, int in_r){
	if(pre_l > pre_r) return;
	int k;
	for(int i = in_l; i <= in_r; i++){
		if(inorder[i] == preorder[pre_l]){
			k = i;
			break;
		}
	}
	transfer(pre_l + 1,  pre_l + k - in_l , in_l , k - 1);
	transfer(pre_l + k - in_l + 1,  pre_r , k + 1 , in_r);
	if (flag == false) {
        printf("%d", inorder[k]);
        flag = true;
	}else{
		printf(" %d", inorder[k]);
	}
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	string in;
	int n, m;
	cin >> n;
	stack<int> s;
	for(int i = 0; i < 2*n; i++){
		cin >> in;
		if(in.compare("Push") == 0){
			cin >> m;
			preorder.push_back(m);
			s.push(m);
		}else{
			m = s.top();
			s.pop();
			inorder.push_back(m);
		}
	}
	transfer(0, n-1 , 0, n-1);
}

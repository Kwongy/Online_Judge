#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct node{
	vector<int> child;
}Node;
int count = 0;
int n, d;
double p, r; 
Node nd[100050];
void dfs(int r,int deep){
	if(nd[r].child.size() == 0){
		if(deep > d){
			d = deep;
			count = 1;
		}else if(deep == d){
			count ++;
		}else{
			return;
		}
	}
	for(int i = 0; i < nd[r].child.size(); i++){
		dfs(nd[r].child[i], deep + 1);
	}
}
int main(){
//	freopen("aa.txt","r",stdin);
	cin >> n >> p >> r;
	int temp;
	double sum = 0;
	int root;
	d = 0;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		if(temp == -1){
			root = i;
		}else{
			nd[temp].child.push_back(i);
		}
	}
	dfs(root, 0);
	printf("%.2f %d", p * pow((1 + r /100), d), count);
	return 0;
}

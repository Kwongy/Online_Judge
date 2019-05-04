#include <iostream>
#include <cstring>
#include <vector> 

using namespace std;
vector<int> v[100];
int maxsize = 0,book[100];
void dfs(int node,int depth){
	if(v[node].size() == 0){
		book[depth]++;
		maxsize = maxsize > depth ? maxsize : depth;
		return; 
	}
	for(int i =0;i < v[node].size();i++){
		dfs(v[node][i],depth+1);
	}
}
int main(){
	int n,m,k,node,c;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		cin >> node >> k;
		for(int j=0; j < k; j++){
			cin >> c;
			v[node].push_back(c);
		}
	}
//	memset(book,0,sizeof(book));
	dfs(1,0);
	cout<< book[0];
	for(int i = 1;i<= maxsize;i++){
		cout<< " "<<book[i];
	}
	return 0; 
}

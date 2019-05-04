#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int> > vec;
int deep;
int count = 0;
void dfs(int i, int d){
	if(!vec[i].size()){
		if(d == deep){
			count++;
		}else if(d < deep){
			deep = d;
			count = 1;
		}
	}
	for(int j = 0; j < vec[i].size(); j++){
		dfs(vec[i][j], d+1);
	}
}
int main(){
	
//	freopen("aa.txt","r",stdin);
	deep =  1 << 30;
	int n, t;
	double p, r; cin >> n >> p >> r;
	vec.resize(n);
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t){
			vec[i].resize(t);
			for(int j = 0; j < t; j++){
				cin >> vec[i][j];
			}
		}
	} 
	dfs(0, 0);
	double s = pow(1 + r/100, deep) * p;
	printf("%.4f %d", s, count);
	
	return 0;
}

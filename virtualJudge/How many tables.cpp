#include<cstring>
#include<set>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100050 
int par[MAX];
int deep[MAX];
int n, m;
void init(){
	int i;
	for(i = 1; i <= n; i++){
		par[i] = i;
		deep[i] = 0;
	}
}
int findpar(int x){
	if(par[x] == x) return x;
	else return par[x] = findpar(par[x]);
}
void merge(int x, int y){
	int a = findpar(x);
	int b = findpar(y);
	if(a == b) return;
	if(deep[a] < deep[b]){
		par[a] = par[b]; 
	}else{
		par[b] = par[a];
		if(deep[a] == deep[b]) deep[a]++;
	}
}
int main(){
	int t, a, b;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			merge(a, b);
		}
		int st = 0;
		for(int i = 1; i <= n; i++) if(par[i] == i) st++;
		cout << st << endl;
	}
	
	return 0;
}

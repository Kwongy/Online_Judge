#include<bits/stdc++.h>
using namespace std;
vector<int> vec[10005];
int color[10005];
int main(){
//	freopen("aa.txt","r",stdin);
	int n, m; scanf("%d %d", &n, &m);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		set<int> c;
		int cnt = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &color[j]);
			if(c.find(color[j]) == c.end()){
				cnt++;
				c.insert(color[j]);
			} 
		}
		bool flag = true;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < vec[j].size(); k ++){
				if(color[j] == color[vec[j][k]]){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) printf("%d-coloring\n", cnt);
		else printf("No\n");
	}
	return 0;
}

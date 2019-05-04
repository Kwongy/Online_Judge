#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec;
int main(){
	int n, m; scanf("%d %d", &n, &m);
	vec.resize(m);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		vec[i] = make_pair(a, b);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		set<int> s;
		scanf("%d", &a);
		for(int j = 0; j < a; j++){
			scanf("%d", &b);
			s.insert(b);
		}
		int flag = 1;
		for(int j = 0; j < m; j++){
			a = vec[j].first;
			b = vec[j].second;
			if(s.find(a) == s.end() && s.find(b) == s.end()){
				flag = 0;
				break;
			}
		}
		printf("%s\n", flag == 1 ? "Yes" : "No");
	}
	return 0;
}

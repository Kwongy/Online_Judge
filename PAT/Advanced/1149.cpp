#include<iostream>
#include<map>
#include<vector>
#define DEBUG 0
using namespace std;
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	map<int, vector<int> > mp;
	int n, m; scanf("%d %d", &n, &m);
	int temp1, temp2;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &temp1, &temp2);
		mp[temp1].push_back(temp2); 
		mp[temp2].push_back(temp1); 
	}

	for(int i = 0; i < m; i++){
		int a[100000] = {0};
		vector<int> input;
		int k; scanf("%d", &k);
		input.resize(k);
		for(int j = 0; j < k; j++){
			scanf("%d", &input[j]); 
			a[input[j]] ++;
		}
		bool ok = true;
		for(int j = 0; j < k; j++){
			for(int t = 0; t < mp[input[j]].size(); t++){
				if(a[mp[input[j]][t]] >0) ok = false;
			}
			if(!ok) break;
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}

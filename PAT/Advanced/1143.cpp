#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
	freopen("aa.txt","r",stdin);
	map<int,int> mp;
	vector<int> pre;
	int n, m;
	scanf("%d %d", &m, &n);
	pre.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
		mp[pre[i]] = 1;
	}
	for(int i = 0; i < m; i++){
		int first, second, temp;
		scanf("%d %d", &first, &second);
		for(int j = 0; j < n; j++){
			temp = pre[j];
			if((first >= temp && temp >= second) || (first <= temp && temp <= second)) break;
		}
		if(mp[first] == 0 && mp[second] == 0){
			printf("ERROR: %d and %d are not found.\n", first, second);
		}else if(mp[first] == 0 || mp[second] == 0){ 
			printf("ERROR: %d is not found.\n", mp[first] == 0 ? first : second);
		}else if(temp == first || temp == second){
			printf("%d is an ancestor of %d.\n", temp, temp == first ? second : first);
		}else{
			printf("LCA of %d and %d is %d.\n", first, second, temp);
		}
	}
	return 0;
}


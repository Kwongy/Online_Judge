#include<iostream>
#include<cmath>
#include<vector>
#define DEBUG 1
using namespace std;
vector<int> vec;
int n = 0;
bool find(int first, int second){
	vector<int> wolf(n + 1, 1), lie;
	wolf[first] = wolf[second] = -1;
	for(int i = 1; i <= n; i ++){
		if(wolf[abs(vec[i])] * vec[i] < 0){
			lie.push_back(i);
		} 
	}
	if(lie.size() == 2 && wolf[lie[0]] + wolf[lie[1]] == 0){
		return true;
	}else{
		return false;
	}
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	scanf("%d", &n);
	vec.resize(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &vec[i]);
	}
	for(int i = 1; i < n; i ++){
		for(int j = i + 1; j <= n; j++){
			if(find(i, j)){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}

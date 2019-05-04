#include<iostream>
#include<vector>
#define DEBUG 0
using namespace std;
vector<int> output;
int graph[1050][1050];
int indeep[1050];
int usedeep[1050];
int n;
void copydeep(){
	for(int i = 1; i <= n; i++)	usedeep[i] = indeep[i]; 
}
bool istopo(vector<int> &vec){
	bool result = true;
	for(int i = 0; i < n; i++){
		int v = vec[i];
		if(!usedeep[v]){
			for(int j = 1; j <= n ; j++){
				if(graph[v][j]){
					usedeep[j]--;
				}
			}
		}else{
			result = false;
			break;
		}
	}
	
	return result;
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int m, k, a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		indeep[b]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		vector<int> temp(n);
		copydeep();
		for(int j = 0; j < n; j++){
			scanf("%d", &a);
			temp[j] = a;
		}
		if(!istopo(temp)){
			output.push_back(i);
		}
	}
	for(int i = 0; i < output.size(); i++){
		if(i){
			printf(" %d", output[i]); 
		}else{
			printf("%d", output[i]);
		}
	}
	return 0;
}

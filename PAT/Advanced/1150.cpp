#include<iostream>
#include<set>
#include<vector>
#define DEBUG 0 
using namespace std;
int n, m, k, ans = 1 << 30, ansid;
int graph[250][250];
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	scanf("%d %d", &n, &m);
	int c1, c2, value;
	for(int i = 0; i < m; i ++){
		scanf("%d %d %d", &c1, &c2, &value);
		graph[c1][c2] = graph[c2][c1] = value;
	}
	scanf("%d", &k); 
	for(int i = 1; i <= k; i++){
		int t; scanf("%d", &t);
		vector<int> input(t);
		set<int> node;
		int sum = 0;
		for(int j = 0; j < t; j++){
			scanf("%d", &input[j]); 
			node.insert(input[j]);
		} 
		bool flag = true;
		for(int j = 0; j < t - 1; j++){
			if(graph[input[j]][input[j + 1]] != 0) sum += graph[input[j]][input[j + 1]];
			else flag = false;
		}
		if (flag == 0) {
	        printf("Path %d: NA (Not a TS cycle)\n", i);
	    } else if(input[0] != input[t-1] || node.size() != n) {	//未访问所有结点，或者没有回到原点 
	        printf("Path %d: %d (Not a TS cycle)\n", i, sum);
	    } else if(t != n + 1) {								// 绕了更多路 
	        printf("Path %d: %d (TS cycle)\n", i, sum);
	        if (sum < ans) {
	            ans = sum;
	            ansid = i;
	        }
	    } else {										//除了首结点出发和回来各访问了一次外  其他结点仅访问一次。 
	        printf("Path %d: %d (TS simple cycle)\n", i, sum);
	        if (sum < ans) {
	            ans = sum;
	            ansid = i;
	        }
	    }
	}
	printf("Shortest Dist(%d) = %d\n", ansid, ans);
	return 0;
}

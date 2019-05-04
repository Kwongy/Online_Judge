#include<bits/stdc++.h>
using namespace std;
int vis[31000] = {0};
int prime[31000];
map<int, int> maze;
int main(){
//	freopen("aa.txt","r",stdin);
	
	for(int i = 2; i < 30000; i++){
		if(!prime[i]){
			for(int j = 2; i * j < 30000; j++){
				prime[i * j] = 1;
			}
		}
	}
	char s1[30] = "Are you kidding?", s2[30] =  "Checked";
	char s[5][30] = {"Mystery Award","Minion","Chocolate"};
	int n, a; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a);
		if(i == 1)maze[a] = 0;
		else if(prime[i]){
			maze[a] = 2;
		}else{
			maze[a] = 1;
		}
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a);
		if(maze.find(a) == maze.end()){
			printf("%04d: %s\n", a, s1);
		}else{
			if(vis[a]){
				printf("%04d: %s\n", a, s2);
			}else{
				printf("%04d: %s\n", a, s[maze[a]]);
				vis[a] = 1;	
			}
		}
	}
	return 0;
}

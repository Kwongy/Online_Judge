#include<iostream>
#include<map> 
using namespace std;

int main(){
	map<int,int> maze;
	int n, m ,a; cin >> n >> m;
	int color, num = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d",&a);
			maze[a] ++;
			if(maze[a] > num){
				num = maze[a];
				color = a;
			}
		}
	}
	printf("%d\n",color);
	return 0;
}

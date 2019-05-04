//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main(){
//	int maze[51][10001];
//	memset(maze,0,sizeof(maze));
//	int n, a, b;
//	scanf("%d",&n);
//	for(int i = 1; i <= n; i++){
//		scanf("%d",&a);
//		for(int j = 0; j < a; j++){
//			scanf("%d",&b);
//			maze[i][b]++;
//		}
//	}
//	int query, f, s;
//	scanf("%d",&query);
//	for(int i = 0; i < query; i++){
//		scanf("%d %d",&f,&s);
//		int common = 0, distinct = 0;
//		for(int j = 1; j <= 1000; j++){
//			if(maze[f][j] && maze[s][j]){
//				common++;
//			}
//			if(maze[f][j] || maze[s][j]){
//				distinct++;
//			}
//		}
//		printf("%.1f%\n",(double)common*100.0/(double)distinct);
//	}
//	
//	return 0;
//}
//#include<string>
//#include<stack>
//#include<unordered_set>
//#include <sstream>
//#include "func.h"
//#include <list>
#include <iomanip>
#include<unordered_map>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include <algorithm>
#include<stdio.h>
#include<iostream>
#include<string>
#include<memory.h>
#include<limits.h>
#include<stack>
using namespace std;
 
int main(void)
{
	int total;
	scanf("%d", &total);
	vector<map<int, int>> m(total);
	vector<vector<int>> ele(total);
	for (int i = 0; i < total; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (m[i][tmp] == 0)
			{
				m[i][tmp] = 1;
				ele[i].push_back(tmp);
			}
		}
	}
	int querySum;
	scanf("%d", &querySum);
	for (int i = 0; i < querySum; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		vector<int> cal(ele[a].size() + ele[b].size());
		for (int i = 0; i < ele[a].size(); i++)
		{
			cal[i] = ele[a][i];
		}
		for (int i = ele[a].size(); i < ele[a].size() + ele[b].size(); i++)
		{
			cal[i] = ele[b][i - ele[a].size()];
		}
		double same = 0;
		sort(cal.begin(), cal.end());
		for (int i = 0; i < cal.size()-1; i++)
		{
			if (cal[i] == cal[i + 1])
				same++;
		}
		double ans = same / (cal.size() - same) * 100;
		printf("%.1lf%\n", ans);
	}
	return 0;
}

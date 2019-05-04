#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
int n,rt,maxn;//节点数量，根，树的最大深度 
int in[55],post[55];
int t[35][2];
vector<int>ans[55];//存放每一层的结点信息
 
void dfs(int &x,int l,int r,int ll,int rr)
{
	if(l>r)return;
	x=rr;//存放的是下标
	
	for(int i=l;i<=r;i++)
	{
		if(in[i]==post[rr])
		{
			dfs(t[x][0],l,i-1,ll,ll+i-1-l);
			dfs(t[x][1],i+1,r,ll+i-l,rr-1);
		}
	 } 
	
}
struct node{
	int index,depth;
};
void bfs()
{
	queue<node>q;
	q.push(node{rt,0});
	while(!q.empty())
	{
		node tt=q.front();q.pop();
		maxn=max(maxn,tt.depth); 
		ans[tt.depth].push_back(tt.index);
		if(t[tt.index][0])q.push({t[tt.index][0],tt.depth+1});
		if(t[tt.index][1])q.push({t[tt.index][1],tt.depth+1});
	}
 }
 int flag; 
 void output()
 {
 	for(int deep=0;deep<=maxn;deep++)
 	{
 		if(deep&1)
		for(int i=0;i<ans[deep].size();i++){
			if(!flag)cout<<post[ans[deep][i]];
			else cout<<" "<<post[ans[deep][i]];
			flag=1;
		}
		else 
		for(int i=ans[deep].size()-1;i>=0;i--){
			if(!flag)cout<<post[ans[deep][i]];
			else cout<<" "<<post[ans[deep][i]];
			flag=1;
		}
	 }
 }
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>in[i];
	for(int i=1;i<=n;i++)cin>>post[i];
	
	dfs(rt,1,n,1,n);//建树 
	bfs();//存储每层节点 
	output();//按照规则输出 
	putchar(10);
	return 0;
 } 

#include<bits/stdc++.h>

using namespace std;
int n,m;
map<string,int>si;
map<int,string>is;
const int N=251;
int weight[N];
int mp[N][N];
const int inf=0x3f3f3f3f;
int dis[N];
bool vis[N];
int num[N];
int w[N];
int past[N];
int path[N];
void Dijkstra(int v)
{
    fill(vis,vis+N,false);
    fill(dis,dis+N,inf);
    fill(w,w+N,0);
    fill(num,num+N,0);
    fill(past,past+N,0);
    fill(path,path+N,0);
    //for(int i=0;i<=n-1;i++) dis[i]=mp[v][i];
    dis[v]=0;
    num[v]=1;
    for(int i=0;i<n;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<n;j++){
            if(!vis[j]&&minn>dis[j]){
                u=j;
                minn=dis[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(!vis[j]&&mp[u][j]!=inf){
                if(dis[j]>dis[u]+mp[u][j]){//第一标尺: 最短路径
                    dis[j]=dis[u]+mp[u][j];
                    num[j]=num[u];
                    w[j]=w[u]+weight[j];
                    past[j]=past[u]+1;//s->j顶点个数等于s->u顶点个数+1
                    path[j]=u;//更新路径
                }
                else if(dis[j]==dis[u]+mp[u][j]){
                    num[j]+=num[u];
                    if(w[u]+weight[j]>w[j]){//第二标尺:结点的值
                        w[j]=w[u]+weight[j];
                        past[j]=past[u]+1;
                        path[j]=u;
                    }
                    else if(w[u]+weight[j]==w[j]){
                        double uAvg=1.0*(w[u]+weight[j])/(past[u]+1);
                        double vAvg=1.0*w[j]/past[j];
                        if(uAvg>vAvg){//第三标尺:平均结点值
                            past[j]=past[u]+1;
                            path[j]=u;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(mp[0],mp[0]+N*N,inf);
    fill(weight,weight+N,0);
    cin>>n>>m;
    string t;
    cin>>t;
    si[t]=0;
    is[0]=t;
    for(int i=1;i<=n-1;i++){
        string temp;
        cin>>temp;
        cin>>weight[i];
        si[temp]=i;
        is[i]=temp;
    }
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        int num;
        cin>>num;
        int a1=si[a];
        int b1=si[b];
        mp[a1][b1]=mp[b1][a1]=num;
    }
    Dijkstra(0);
    int rom=si["ROM"];
    cout<<num[rom]<<" "<<dis[rom]<<" "<<w[rom]<<" "<<w[rom]/past[rom]<<endl;
    int tt=rom;
    vector<int>vec;
    while(tt!=0){
        vec.push_back(tt);
        tt=path[tt];
    }
    reverse(vec.begin(),vec.end());
    cout<<t<<"->";
    for(int i=0;i<vec.size();i++){
        if(i) cout<<"->";
        cout<<is[vec[i]];
    }
    cout<<endl;
    return 0;
}

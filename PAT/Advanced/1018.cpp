#include <iostream>
#include <vector>
using namespace std;
const int inf=999999999;
int full,n,sp,m,rsend=inf,rtake=inf,tempsend,temptake;
std::vector<int> result,temp;
int w[505],e[505][505],dis[505];
bool visit[505];
std::vector<int> pre[505];
void dfs(int index){
    if(index==0){
        temptake=0;tempsend=0;
        for(int j=temp.size()-1;j>=0;j--){
            temptake+=(w[temp[j]]-full);
            if(temptake<0){
                tempsend-=temptake;
                temptake=0;
            }
        }
        if(tempsend<rsend){
            rtake=temptake;
            rsend=tempsend;
            result=temp;
        }
        else if(tempsend==rsend&&temptake<rtake){
            rtake=temptake;
            rsend=tempsend;
            result=temp;
        }
        return;
    }
    temp.push_back(index);
    for(int i=0;i<pre[index].size();i++)
        dfs(pre[index][i]);
    temp.pop_back();
}
int main(){
    scanf("%d %d %d %d",&full,&n,&sp,&m);
    full/=2;
    fill(e[0],e[0]+505*505,inf);
    fill(dis,dis+505,inf);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<m;i++){
        int a,b,temp;
        scanf("%d %d %d",&a,&b,&temp);
        e[a][b]=temp;e[b][a]=temp;
    }
    dis[0]=0;
    for(int i=0;i<=n;i++){
        int u=-1,min=inf;
        for(int j=0;j<=n;j++){
            if(visit[j]==false&&dis[j]<min){
                u=j;
                min=dis[j];
            }
        }
        if(u==-1)
            break;
        visit[u]=true;
        for(int v=0;v<=n;v++){
            if(visit[v]==false&&e[v][u]!=inf){
                if(dis[u]+e[u][v]<dis[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    dis[v]=dis[u]+e[u][v];
                }
                else if(dis[u]+e[u][v]==dis[v])
                    pre[v].push_back(u);
            }
        } 
    }
    dfs(sp);
    printf("%d 0",rsend);
    for(int i=result.size()-1;i>=0;i--)
        printf("->%d",result[i]);
    printf(" %d",rtake);
}

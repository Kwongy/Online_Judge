#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
struct arc{
    int u,v,w;
    bool operator<(const arc &t)const{
        return w < t.w;
    }
}e[maxn];
int uf[maxn],n,m;
int Find(int x){
    if(x != uf[x]) uf[x] = Find(uf[x]);
    return uf[x];
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        for(int i = 0; i < m; ++i)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e,e+m);
        int ret = 0;
        for(int i = 0; i <= n; ++i) uf[i] = i;
        for(int i = 0; i < m; ++i){
            int x = Find(e[i].u);
            int y = Find(e[i].v);
            if(x == y) continue;
            ret += e[i].w;
            uf[x] = y;
        }
        printf("%d\n",ret);
    }
    return 0;
}

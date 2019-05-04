#include <bits/stdc++.h>
using namespace std;
const int maxn=10000;
 
int n,k;
 
typedef struct node
{
    string name;
    int h;
}node;
 
bool cmp(node a,node b)
{
    if(a.h==b.h)
        return a.name>b.name;
    else
        return a.h<b.h;
}
 
int main()
{
    cin>>n>>k;
    node a[10005];
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].h;
    }
    sort(a,a+n,cmp);
 
    int i=n;
 
    while(i>0){
        vector<node> v;
        int m;
        if(i==n){
            m=n/k+n%k;
            for(int j=n-m;j<n;j++)
                v.push_back(a[j]);
        }
        else{
            m=n/k;
            for(int j=i-m;j<i;j++)
                v.push_back(a[j]);
        }
 
        vector<string> ans(m);
 
        ans[m/2]=v[m-1].name;
        int pl,pr,f=1;//f=1Íù×ó£¬f=0ÍùÓÒ
        pl=m/2-1;
        pr=m/2+1;
        for(int j=m-2;j>=0;j--)
        {
            if(f){
                ans[pl]=v[j].name;
                pl--;
                f=0;
            }
            else{
                ans[pr]=v[j].name;
                pr++;
                f=1;
            }
 
        }
        cout<<ans[0];
        for(int j=1;j<m;j++){
            cout<<" "<<ans[j];
        }
        cout<<endl;
        i=i-m;
    }
 
    return 0;
}

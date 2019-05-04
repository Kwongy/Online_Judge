#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int maxn = 26*26*26*10+10;
vector<int> check[maxn];
int hashfunc(string s)
{
    int ans = 0;
    for(int i = 0 ; i < 3; i++)
    {
        ans = ans *26 + s[i]-'A';
    }
    ans = ans*10 + s[3] - '0';
    return ans;
}
int main(){
    int n,z;
    scanf("%d%d",&n,&z);
    string name;
    map <int,string> m;
    for(int i = 0 ; i < n ;i++)
    {
        cin>>name;
        int k;
        scanf("%d",&k);
        for(int i = 0 ; i < k ; i++)
        {
            int temp;
            scanf("%d",&temp);
            check[temp].push_back(hashfunc(name));
            m[hashfunc(name)]=name;
        }
    }
    vector<string> temp;
    for(int i = 1 ; i <= z; i++)
    {
        temp.clear();
        printf("%d %d\n",i,check[i].size());
        for(int j = 0 ; j < check[i].size(); j++)
        {
            temp.push_back(m[check[i][j]]);
        }
        sort(temp.begin(),temp.end());
        for(int j = 0 ; j < temp.size(); j++)
        {
            printf("%s\n",temp[j].c_str());//用printf否则最后一个测试点超时
        }
    }
}

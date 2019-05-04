#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int val;
    int next,id;
};
node Link[100100];
int main()
{
    int head,n,id,val,next;
    scanf("%d%d",&head,&n);
    for(int i = 0 ;i < n ;++i)
    {
        scanf("%d%d%d",&id,&val,&next);
        Link[id].val = val;
        Link[id].next = next;
        Link[id].id = id;
    }
    int p = head;
    set<int> ss;
    vector<node> vv,vv2;
    while(p != -1)
    {
        int tem = abs(Link[p].val);
        if(ss.count(tem) == 0)
        {
            ss.insert(tem);
            vv.push_back(Link[p]);
        }
        else vv2.push_back(Link[p]);
        p = Link[p].next;
    }
    p = head;
    for(int i = 0 ; i < (int)vv.size() - 1;++i)
    {
        printf("%05d %d %05d\n",vv[i].id,vv[i].val,vv[i+1].id);
    }
    if(vv.size() > 0)
        printf("%05d %d -1\n",vv[vv.size()-1].id,vv[vv.size()-1].val);

    for(int i = 0 ;i < (int)vv2.size() -1;++i)
    {
        printf("%05d %d %05d\n",vv2[i].id,vv2[i].val,vv2[i+1].id);
    }
    if(vv2.size() > 0)
        printf("%05d %d -1\n",vv2[vv2.size()-1].id,vv2[vv2.size()-1].val);
    return 0;
}

#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node
{
    int val,cnt;
    bool operator < (const node & a)const{
        return cnt != a.cnt ? cnt > a.cnt : val < a.val;
    }    
};
int main(){
    int n, k, temp, cnt = 0;
    cin>>n>>k;
    scanf("%d",&temp);
    set<node>s;
    std::vector<int> valuecnt(n + 1, 0);
    s.insert({temp,1});
    valuecnt[temp]++;
    for(int i = 1; i < n; ++ i){
        scanf("%d", &temp);
        printf("%d:",temp);
        cnt = 0;
        for(auto it = s.begin(); cnt < k && it != s.end(); ++it){
            printf(" %d",it->val);
            cnt++;
        }
        printf("\n");
        if(valuecnt[temp] > 0)
            s.erase({temp,valuecnt[temp]});
        valuecnt[temp]++;
        s.insert({temp,valuecnt[temp]});
    }
}

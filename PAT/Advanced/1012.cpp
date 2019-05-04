#include <iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct node{
	int id,best;
	int score[4],rank[4];
}stu[2005];
int flag = -1;
bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}
int main(){
	int n,m,a,b,c,d;
	map<int,int> s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){				//四舍五入平均分 
		cin >> a >> b >> c >> d;
		stu[i].id = a;
		stu[i].score[1] = b;
		stu[i].score[2] = c;
		stu[i].score[3] = d;
		stu[i].score[0] = (int)((b+c+d+0.5)/3);
	}
	for(flag = 0; flag <= 3; flag++) {			//排序 
        sort(stu, stu + n, cmp1);
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i = 0; i < n; i++) {			//排名 
        stu[i].best = 0;
        s[stu[i].id] = i;
        int minn = stu[i].rank[0];
        for(int j = 1; j <= 3; j++) {
            if(stu[i].rank[j] < minn) {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char ch[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &a);
        if(s.find(a) != s.end()) {
            a = s.find(a)->second;
            cout << stu[a].rank[stu[a].best] << " " << ch[stu[a].best] << endl;
        } else {
            printf("N/A\n");
        }
    }
	return 0; 
}

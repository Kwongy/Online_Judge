#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct cus{
	int start,end;
	int during;
};
cus cs[1590];
queue<cus> que[30];
int main(){
	int a, n, m, k, q; cin >> n >> m >> k >> q;
	int now[30];
	for(int i = 0; i < k; i++){
		cin >> a;
		cs[i].during = a;
	}
	int cur = 0;
	for(int i = 0; i < n; i++){
		now[i] = 480;
	}
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(cur < k){
				cs[cur].start = now[i];
				cs[cur].end = cs[cur].during + now[i];
				now[i] = cs[cur].end;
				que[i].push(cs[cur]);
				cur++;
			}
		}
	}
	for(int i = 480; i <= 1020; i++){
		for(int j = 0; j < n; j++){
			if(!que[j].empty() && que[j].front().end == i)  {
				que[j].pop();
				if(cur < k){
					cs[cur].start = now[j];
					cs[cur].end = cs[cur].during + now[j];
					now[j] = cs[cur].end;
					que[j].push(cs[cur]);
					cur++;
				}
			}
		}
	}
	for(int i = 0; i < q; i++){
		cin >> a;
		int h = cs[a-1].end;
		int w = h%60,e = h/60;
		if((e<17)||(e==17&&w==0))
			printf("%02d:%02d\n",e,w);
		else{
			cout << "Sorry" << endl;
		}
	}
	return 0;
}

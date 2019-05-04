#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int start,end,key;
};
bool cmp(const struct node &a,const struct node &b){
	return a.key < b.key;
}
vector<node> vec;
int main(){
	int n; cin >> n;
	int a, b, c;
	int st; cin >> st;
	node nd[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d %d",&a,&b,&c);
		nd[i] = {a,c,b};
	}
	while(st != -1){
		for(int i = 0;i < n; i++){
			if(nd[i].start == st){
				st = nd[i].end;
				vec.push_back(nd[i]);
			}
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	st = vec.size();
    if(st == 0){
		cout << 0 << " " << -1 << endl;
		return 0;
	}
	printf("%d %05d\n",st,vec[0].start);
	for(int i = 0; i < st;i++){
		if(i != st-1){
			printf("%05d %d %05d\n",vec[i].start,vec[i].key,vec[i+1].start);
		}else{
			printf("%05d %d %d\n",vec[i].start,vec[i].key,-1);
		}
	}
} 

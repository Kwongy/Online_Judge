#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, l, h;
struct people{
	char name[10];
	int vir,tal,tot;
};
vector<people> sage,noble,fool,small;
bool cmp(const struct people &a,const struct people &b){
	if(a.tot != b.tot){
		return a.tot > b.tot; 
	}else if(a.vir != b.vir){
		return a.vir > b.vir;
	}else{
		return strcmp(a.name,b.name) < 0;
	}
}
int main(){
	scanf("%d %d %d\n",&n,&l,&h);
	for(int i = 0; i < n; i++){
		people p;
		scanf("%s %d %d\n",&p.name,&p.vir,&p.tal);
		p.tot = p.tal + p.vir;
		if(p.tal >= l && p.vir >= l){
			if(p.tal >= h && p.vir >= h){
				sage.push_back(p);
			}else if(p.vir >= h){
				noble.push_back(p);
			}else if(p.tal < h && p.vir < h && p.vir >= p.tal){
				fool.push_back(p);
			}else{
				small.push_back(p);
			}
		}
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(noble.begin(),noble.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(small.begin(),small.end(),cmp);
	int a1 = sage.size(), a2 = noble.size(), a3 = fool.size(), a4 = small.size();
	printf("%d\n",a1+a2+a3+a4);
	for(int i = 0; i < a1; i ++){
		printf("%s %d %d\n",sage[i].name,sage[i].vir,sage[i].tal);
	}
	for(int i = 0; i < a2; i ++){
		printf("%s %d %d\n",noble[i].name,noble[i].vir,noble[i].tal);
	}
	for(int i = 0; i < a3; i ++){
		printf("%s %d %d\n",fool[i].name,fool[i].vir,fool[i].tal);
	}
	for(int i = 0; i < a4; i ++){
		printf("%s %d %d\n",small[i].name,small[i].vir,small[i].tal);
	}	
	return 0;
}

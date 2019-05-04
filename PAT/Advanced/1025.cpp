#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct student{
	char name[20];
	int score, frank, locat, lrank;
};
vector <vector<student> > vec(300);
vector <student> tot;
bool cmp2(const student &a,const student &b){
	if(a.score != b.score) return a.score > b.score;
	else{
		return (strcmp(a.name,b.name) < 0);
	}
}
int main(){
	freopen("aa.txt","r",stdin);
	int t, k, s; cin >> t;
	int count = 0;
	char m[20];
	for(int i = 1; i <= t; i++){
		scanf("%d",&k);
		getchar();
		vec[i].resize(k);
		for(int j = 0; j < k; j++){
			scanf("%s %d\n",m,&s);
			student child;
			strcpy(child.name,m);
			child.score = s;
			child.locat = i;
			vec[i][j] = child;
		}
		sort(vec[i].begin(),vec[i].end(),cmp2);
		
		for(int j = 0; j < k; j++){
			if(j==0) vec[i][j].lrank = 1;
			else{
				if(vec[i][j-1].score == vec[i][j].score) vec[i][j].lrank = vec[i][j-1].lrank;
				else vec[i][j].lrank = j + 1;
			}
//			cout << vec[i][j].name << " " << vec[i][j].score << " " << vec[i][j].lrank <<endl;
			tot.push_back(vec[i][j]);
			count ++;
		}
	}
	sort(tot.begin(),tot.end(),cmp2);
	cout << count << endl;
	for(int i = 0; i < count; i++){
		if(i == 0){
			tot[i].frank = 1;
		}else{
			if(tot[i].score == tot[i-1].score) tot[i].frank = tot[i-1].frank;
			else tot[i].frank = i+1;
		}
		cout << tot[i].name << " "<< tot[i].frank << " " <<  tot[i].locat << " " << tot[i].lrank << endl;
	}
	return 0;
}

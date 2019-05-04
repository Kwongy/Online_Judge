#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int full_mark[6];
typedef struct {
	int rank;
	int num;
	int valid;
	int score[6];
	int total;
	int perfect;
}student;

student st[10005];

int cmp(const student &a, const student &b){
	if(a.total != b.total) return a.total > b.total;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.num < b.num;
}
int main(){
	freopen("aa.txt","r",stdin);
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 1; i <= k; i++) scanf("%d", &full_mark[i]);
	for(int i = 1; i <= n; i++){
		st[i].num = i;
		st[i].valid = 0;
		st[i].total = 0;
		st[i].perfect = 0;
		for(int j = 1; j <= k; j++) st[i].score[j] = -2;
	}
	int a, b, c;
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(st[a].valid == 0 && c != -1){
			if(c == full_mark[b]) st[a].perfect++;
			st[a].valid = 1;
			st[a].total = c;
			st[a].score[b] = c;
		}else{
			if(c == -1){
				if(st[a].valid == 0|| st[a].score[b] == -2) st[a].score[b] = 0;
			}else if(st[a].score[b] < c){
				if(st[a].score[b] == -2) st[a].total += c;
				else  st[a].total += c - st[a].score[b];
				st[a].score[b] = c;
				if(c == full_mark[b]) st[a].perfect++;
			}
		}
	}
	vector<student> vec;
	for(int i = 1; i <= n; i++){
		if(st[i].valid == 1) vec.push_back(st[i]);
	}
	int t = vec.size();
	sort(vec.begin(), vec.end(),cmp);
	printf("1 %05d %d", vec[0].num, vec[0].total);
	for(int j = 1; j <= k; j++){
		if(vec[0].score[j] == -2) printf(" -");
		else printf(" %d",vec[0].score[j]);
	}
	printf("\n");
	vec[0].rank = 1;
	for(int i = 1; i < t; i++){
		if(vec[i].total == vec[i-1].total){
			vec[i].rank = vec[i-1].rank;
		}else{
			vec[i].rank = i + 1;
		}
		printf("%d ", vec[i].rank);
		printf("%05d %d", vec[i].num, vec[i].total);
		for(int j = 1; j <= k; j++){
			if(vec[i].score[j] == -2) printf(" -");
			else printf(" %d",vec[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}


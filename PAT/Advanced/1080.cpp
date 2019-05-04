#include<bits/stdc++.h>
using namespace std;
const int maxn = 40010;
struct st{
	int ge, gi;
	int tot, id;
	int rank;
	int sch[5];
}student[maxn];

struct sc{
	int need;
	int stuN, last;
	int id[maxn];
}school[110];
bool cmpst(st a, st b){
	if(a.tot != b.tot) return a.tot > b.tot;
	else return a.ge > b.ge;
}
bool cmpid(int a, int b){
	return student[a].id < student[b].id;
}
int main(){
//	freopen("aa.txt","r",stdin);
	int n, m ,k; scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d", &school[i].need);
		school[i].last = -1;
		school[i].stuN = 0;
	}
	for(int i = 0; i < n; i++){
		student[i].id = i;
		scanf("%d %d", &student[i].ge, &student[i].gi);
		student[i].tot = student[i].ge + student[i].gi;
		for(int j = 0; j < k; j++){
			scanf("%d", &student[i].sch[j]);
		}
	}
	sort(student, student + n, cmpst);
	for(int i = 0; i < n; i++){
		if(i > 0 && (student[i].tot == student[i-1].tot && student[i].ge == student[i-1].ge)) student[i].rank = student[i-1].rank;
		else student[i].rank = i;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int choice = student[i].sch[j];
			int num = school[choice].stuN;
			int last = school[choice].last;
			if(num < school[choice].need || (last != -1 && student[i].rank == student[last].rank)){
				school[choice].id[num] = i;
				school[choice].last = i;
				school[choice].stuN++;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(school[i].stuN > 0){
			sort(school[i].id, school[i].id + school[i].stuN, cmpid);
			for(int j = 0; j < school[i].stuN; j++){
				printf("%d", student[school[i].id[j]].id);
				if(j < school[i].stuN - 1) printf(" ");
			} 
		}
		printf("\n");
	}
	
	return 0;
} 

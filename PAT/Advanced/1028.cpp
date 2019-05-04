#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct stu{
	char id[10],name[10];
	int grade;
};
vector<stu> vec;
bool cmp1(const struct stu &a,const struct stu &b){
	return strcmp(a.id,b.id) < 0;
}
bool cmp2(const struct stu &a,const struct stu &b){
	if(strcmp(a.name,b.name) != 0) return strcmp(a.name,b.name) < 0;
	else return strcmp(a.id,b.id) < 0;;
}
bool cmp3(const struct stu &a,const struct stu &b){
	if(a.grade != b.grade) return a.grade < b.grade;
	else return strcmp(a.id,b.id) < 0;
}
int main(){
	int n, m, score; cin >> n >> m; getchar();
	vec.resize(n);
	char n1[10],n2[10];
	for(int i = 0; i < n; i++){
		scanf("%s %s %d\n",n1,n2,&score);
		stu st;
		strcpy(st.id,n1);
		strcpy(st.name,n2);
		st.grade = score;
		vec[i] = st;
	}
	if(m == 1) sort(vec.begin(),vec.end(),cmp1);
	else if(m == 2) sort(vec.begin(),vec.end(),cmp2);
	else sort(vec.begin(),vec.end(),cmp3);
	for(int i = 0; i < n; i++){
		printf("%s %s %d\n", vec[i].id, vec[i].name, vec[i].grade);
	}
	return 0;
}

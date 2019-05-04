#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	string name;
	string lesson;
	int grade;
}student;

int cmp(const student &a, const student &b){
	return a.grade > b.grade;
} 
int main(){
//	freopen("aa.txt","r",stdin);
	vector<student> vec;
	int n;cin >> n;getchar();
	int begin, end;
	vec.resize(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i].name;
		cin >> vec[i].lesson;
		scanf("%d\n", &vec[i].grade);
	}
	scanf("%d %d", &begin, &end); 
	sort(vec.begin(), vec.end(), cmp);
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(vec[i].grade <= end && vec[i].grade >= begin){
			cout << vec[i].name << " " << vec[i].lesson << endl;
			flag = 1;
		}
	}
	if(!flag) cout << "NONE" << endl;
	return 0;
}

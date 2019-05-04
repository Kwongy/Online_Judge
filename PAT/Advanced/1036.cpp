#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string name,sex,css;
	int score;
};
vector<student> female;
vector<student> male;
bool cmp1(const struct student &a,const struct student &b){
	return a.score > b.score;
}
bool cmp2(const struct student &a,const struct student &b){
	return a.score < b.score;
}
int main(){
	int n; cin >> n;
	string N,S,C;
	int grade;
	for(int i = 0; i < n; i++){
		cin >> N >> S >> C >> grade;
		student st={N, S, C, grade};
		if(S == "F") female.push_back(st);
		else male.push_back(st);
	}
	if(female.size() == 0){
		cout<< "Absent" <<endl;
		cout << male[0].name << " " << male[0].css << endl;
		cout<< "NA" << endl;
	}else if(male.size() == 0){
		cout << female[0].name << " " << female[0].css << endl;
		cout<< "Absent" << endl << "NA" << endl;
	}else{
		sort(female.begin(),female.end(),cmp1);
		sort(male.begin(),male.end(),cmp2);
		cout << female[0].name << " " << female[0].css << endl;
		cout << male[0].name << " " << male[0].css << endl;
		cout << female[0].score - male[0].score << endl;
	}
	return 0;
} 

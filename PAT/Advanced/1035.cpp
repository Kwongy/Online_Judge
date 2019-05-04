#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<string,string> > vec;
bool change(string &a){
	bool result = false;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '1') {
			a[i] = '@';
			result = true;
		}
		else if(a[i] == '0') {
			a[i] = '%';
			result = true;
		}
		else if(a[i] == 'l') {
			a[i] = 'L';
			result = true;	
		}
		else if(a[i] == 'O') {
			a[i] = 'o';
			result = true;	
		}
	}
	
	return result;
}
int main(){
	int n; cin >> n;
	string s,t;
	for(int i = 0; i < n; i++){
		cin >> s >> t;
		if(change(t)) vec.push_back(make_pair(s,t));
	}
	if(vec.size() == 0) {	
		if(n == 1) {
		cout << "There is 1 account and no account is modified" << endl;}
		else{
		cout << "There are " << n << " accounts and no account is modified" << endl;
		}
	}else{
		cout << vec.size() << endl;
		for(int i = 0; i < vec.size(); i++){
			cout << vec[i].first << " " << vec[i].second << endl;
		}
	}
	return 0;
}

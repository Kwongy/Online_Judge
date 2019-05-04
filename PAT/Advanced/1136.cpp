#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prime(vector<char> a){
	bool isok = true;
	int n = a.size();
	for(int i = 0; i < n/2; i++){
		if(a[i] != a[n - i - 1]){
			isok = false;
			break;
		}
	}
	return isok;
}
int main(){
	freopen("aa.txt","r",stdin);
	vector<char> s;
	string str;
	cin >> str;
	for(int i = 0 ; i < str.length(); i++){
		s.push_back(str[i]);
	}
	for(int i = 0 ; i < 10; i++){
		int t = s.size();
		for(int q = 0; q < t; q++){
				cout << s[q];
		}
		cout << " + ";
		vector<char> r = s;
		reverse(r.begin(),r.end());
		for(int q = 0; q < t; q++){
				cout << r[q];
		}
		cout << " = ";
		vector<char> n(t,0);
		bool addn = false;
		for(int j = t - 1; j >= 0; j--){
			n[j] += r[j] + s[j] - '0';
			if(n[j] > '9'){
				if(j == 0){
					addn = true;
				}else{
					n[j-1] += 1;
				}
				n[j] -= 10;
			}
		}
		if(addn) n.insert(n.begin(),'1');
		s = n;
		for(int q = 0; q < s.size(); q++){
				cout << s[q];
		}
		cout << endl;
		if(prime(s)){
			for(int q = 0; q < s.size(); q++){
				cout << s[q];
			}
			cout << " is a palindromic number." << endl;
			return 0;
		}
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}

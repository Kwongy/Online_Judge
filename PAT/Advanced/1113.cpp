#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
	ll sum = 0;
	int n; cin >> n;
	int temp;
	vector<int> vec;
	vec.resize(n);
	for(int i = 0; i < n; i++){
		cin >> temp;
		vec[i] = temp;
		sum += temp;
	}
	sort(vec.begin(),vec.end());
	if(n % 2 == 0){
		cout << "0 ";
	}else{
		cout << "1 ";
	}
	ll s = 0;
	for(int i = 0; i < n / 2; i++){
		s += vec[i];
	}
	cout << sum - 2 * s;
	return 0;
}

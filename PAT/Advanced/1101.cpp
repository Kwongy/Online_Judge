#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int main(){
//	freopen("aa.txt","r",stdin);
	vector<ll> input, output, temp, cmp;
	int n, t; cin >> n;
	input.resize(n);
	temp.resize(n);
	cmp.resize(n);
	cmp[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> t;
		input[i] = t;
		temp[i] = t;
		if(i != 0) cmp[i] = cmp[i - 1] > t ? cmp[i-1] : t;
	}
	cmp[0] = input[0];
	sort(temp.begin(), temp.end());
	for(int i = 0; i < n; i++){
		if(input[i] == temp[i] && cmp[i] == temp[i]) output.push_back(input[i]);
	}
	if(output.size() == 0){
        printf("0\n\n");
    }else{
   		printf("%ld\n%ld", output.size(), output[0]);
		for(int i = 1; i < output.size(); i++) cout << " " << output[i]; 	
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n, m;
vector<int> arr(10050, 0);
vector<int> output;
bool isfind = false;
stack<int> st;
void dfs(int index, int sum){
	if(sum == m){
		isfind = true;
		while(st.size() != 0){
			output.push_back(st.top());
			st.pop();
		}
		return;
	}
	if(sum > m) return;
	for(int i = index; i <= m; i++){
		if(arr[i] != 0){
			arr[i]--;
			st.push(i);
			dfs(i, sum + i);
			if(isfind == true) return;
			st.pop();
			arr[i]++;
		}
	}
}
int main(){
//	freopen("aa.txt","r",stdin);
	cin >>  n >> m;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		arr[a]++;
	}
	for(int i = 1; i <= m; i++){
		if(arr[i] != 0){
			dfs(i, 0);
			if(isfind) break;
		}
	}
	a = output.size();
	if(a != 0){	cout << output[a - 1];
		for(int i = a - 2 ; i >= 0; i--){
			cout << " " << output[i];
		}
	}else{
		cout << "No Solution" << endl;
	}
	
	return 0;
}

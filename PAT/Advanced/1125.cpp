#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
	int n;  cin >> n;
	priority_queue<int, vector<int>, greater<int> > c;
	int t, a, b;
	for(int i = 0; i < n; i++){
		cin >> t;
		c.push(t);	
	}
	while(c.size() != 1){
		a = c.top();
		c.pop();
		b= c.top();
		c.pop();
		c.push((a + b)/2);
	}
	cout << c.top();
	
	return 0;
}

#include<iostream>
#include<vector>
#define DEBUG 1
using namespace std;

vector<int> vec;
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int n;
	cin >> n;
	vec.resize(n);
	int maxSum = 0, thisSum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		thisSum += vec[i];
		if(thisSum > maxSum){
			maxSum = thisSum;
		}else if(thisSum < 0){
			thisSum = 0;			//最大子序和的前缀一定不肯能是负的 
		}
	}
	cout << maxSum << endl;
	return 0;
}


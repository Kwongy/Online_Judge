#include<iostream>
#include<vector>
using namespace std;

int main(){
	int arr[100050] = {0};
	int n; scanf("%d", &n);
	int a;
	for(int i = 0; i < n; i++){
		int sum = 0;
		scanf("%d", &a);
		while(a){
			sum += a % 10;
			a = a / 10; 
		}
		arr[sum]++;
	}
	vector<int> vec;
	for(int i = 0; i < 100000; i++){
		if(arr[i] > 0) vec.push_back(i);
	}
	n = vec.size();
	printf("%d\n%d", n, vec[0]);
	for(int i = 1; i < n; i++){
		printf(" %d", vec[i]);
	}
	
	return 0;
}

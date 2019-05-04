#include<iostream>
#include<queue>
using namespace std;
int arr[1005];
int index[1005];
queue<int> q;
int out[1005];
int ls[1005];
int findmax(int l[],int begin,int end){
	int max = arr[l[begin]];
	int index = begin;
	for(int i = begin + 1; i <= end; i++){
		if(arr[l[i]] > max){
			max = arr[l[i]];
			index = i;
		}
	}	
	return ls[index];
}
int main(){
	int n, m, a; cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		q.push(a);
	}
	int s = q.size();
	int curRank;
	while(s != 1){
		int begin = 1;
		curRank = (s + m -1)/m + 1;
		for(int i = 1; i <= s; i++){
			ls[i] = q.front();
			q.pop();
			if(i % m == 0 || i == s){
				a = findmax(ls,begin,i);
				q.push(a);
				for(int j = begin; j <= i; j++){
					out[ls[j]] = curRank;
				}
				begin = i + 1; 
			}
		}
		s = q.size();
	}
	a = q.front();
	q.pop();
	out[a] = 1;
	for(int i = 0; i < n; i++){
		if(i != 0){
			printf(" %d",out[i]);
		}else{
			printf("%d",out[i]);
		}
	} 
	return 0;
} 

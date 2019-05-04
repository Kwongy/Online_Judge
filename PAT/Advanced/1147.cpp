#include<iostream>
#include<vector>
#define DEBUG 1
using namespace std;

int n;
vector<int> vec;
vector<int> output;
void postorder(int index){
	if(index > n) return;
	postorder(index * 2);
	postorder(index * 2 + 1);
	output.push_back(vec[index]);
}
bool maxheap, minheap;
void isheap(int k){
	int i = 2 * k;
	int j = i + 1;
	if(i <= n){
		if(vec[i] > vec[k]) maxheap = false;
		else if(vec[i] < vec[k]) minheap = false;
	}
	if(j <= n){
		if(vec[j] > vec[k]) maxheap = false;
		else if(vec[i] < vec[k]) minheap = false;
	}
}

int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	int t, a;
	scanf("%d %d", &t, &n);
	vec.resize(n+1);
	while(t--){
		vec.clear();
		vector<int>().swap(output);
		for(int i = 1; i <= n; i++){
			scanf("%d", &vec[i]);
		}	
		maxheap = minheap = true;
		for(int i = n/2; i > 0; i--){
			isheap(i); 
		}
		if(maxheap){
			printf("Max Heap\n");
		}else if(minheap){
			printf("Min Heap\n");
		}else{
			printf("Not Heap\n");
		}
		postorder(1);
		for(int i = 0; i < n; i++){
			if(i){
				printf(" %d",output[i]);
			}else{
				printf("%d",output[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tree,arr;
int n;
void buildTree(int root){
	static int index = 1;
	if(root > n) return;
	buildTree(root * 2);
	tree[root] = arr[index++];
	buildTree(root * 2 + 1);
}
int main(){
	cin >> n;
	arr.resize(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(),arr.end());
	tree.resize(n+1);
	buildTree(1);
	printf("%d",tree[1]);
	for(int i = 2; i <= n; i++){
		printf(" %d",tree[i]);
	} 
	cout << endl;
	return 0;
}

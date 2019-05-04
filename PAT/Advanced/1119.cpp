#include <iostream>
#include<vector>
using namespace std;

vector<int> pre, post, inorder;
bool unique = true;
int n;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
	if(preLeft == preRight) {
		inorder.push_back(pre[preLeft]);
		return;
	}
	if (pre[preLeft] == post[postRight]) {
		int i = preLeft + 1;
		while (i <= preRight && pre[i] != post[postRight-1]) i++;
		if (i - preLeft > 1)
			getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
		else
			unique = false;
		inorder.push_back(post[postRight]);
		getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
	}
}
int main(){
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for(int i = 0; i < n; i++){
		cin >> pre[i];
	}
	for(int i = 0; i < n; i++){
		cin >> post[i];
	}
	getIn(0, n-1, 0, n-1);
	printf("%s\n%d", unique == true ? "Yes" : "No" , inorder[0]);
	for(int i = 1; i < n; i++){
		cout << " " << inorder[i];
	}
	cout << endl;
	return 0;
}

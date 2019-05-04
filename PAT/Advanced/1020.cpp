#include<iostream>
#include<vector>
using namespace std;

vector<int> in(35),post(35),level(10000,-1);
void pre(int root, int start, int end, int index){	//根从后序遍历中找，用中序遍历分左右子树 
	if(start > end) return;
	int i = start;
	while(i < end && post[root] != in[i])	i++;		//在中序遍历中找根 
	level[index] = post[root];							//记录层次遍历位置
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);		//左子树，根节点为最后一个。 
	pre(root - 1, i + 1, end, 2 * index + 2);  
}
int main(){
	int n; cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    for(int cnt = 0, i = 0; i < level.size(); i++) {
        if (level[i] != -1) {
            if (cnt != 0) printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n) break;
    }
	return 0;
} 

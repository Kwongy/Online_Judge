#include<iostream>
#include<algorithm>
#include<set>
#define DEBUG 0
using namespace std;
int preorder[10500];
int inorder[10500];
int postorder[10500];
int n ,m;
int num = 0;
set<int> tree;
void post(int pre_l, int pre_r, int in_l, int in_r){
	if(pre_l > pre_r) return;
	int value = preorder[pre_l];
	int index;
	for(index = in_l; index <= in_r; index++){
		if(inorder[index] == value) break;
	}
	post(pre_l + 1, pre_l + (index - in_l), in_l , index);
	post(pre_l + (index - in_l) + 1, pre_r, index + 1, in_r);
	postorder[num] = value;
	num++;
}
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		scanf("%d", &inorder[i]);
		tree.insert(inorder[i]);
	}
	for(int i = 0; i < m; i ++){
		scanf("%d", &preorder[i]);
	}
	post(0, m-1, 0, m-1);
	int first,second;
	int pre_f,pre_s, pre_min;
	int in_f,in_s, in_min, in_max;
	int post_f,post_s, post_max;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &first, &second);
		bool ok1 = (tree.find(first) == tree.end());
		bool ok2 = (tree.find(second) == tree.end());
		if(ok1 && ok2){
			printf("ERROR: %d and %d are not found.\n", first, second);
			continue;
		}else if(ok1 || ok2){
			printf("ERROR: %d is not found.\n", ok1 ? first : second);
			continue;
		}else{
				for(int j = 0; j < m; j ++){
					if(preorder[j] == first) pre_f = j;
					if(inorder[j] == first) in_f = j;
					if(postorder[j] == first) post_f = j;
					if(preorder[j] == second) pre_s = j;
					if(inorder[j] == second) in_s = j;
					if(postorder[j] == second) post_s = j;
				}
				pre_min = min(pre_f, pre_s);
				in_min =  min(in_f, in_s);
				in_max = max(in_f, in_s);
				post_max = max(post_f, post_s);
				int ans;
				for(int j = pre_min; j >= 0 ;j--){
					ans = preorder[j];
					bool OK1 = false, OK2 = false;;
					for(int k = in_min; k <= in_max; k++){
						if(inorder[k] == ans) {
							OK1 = true;break;
						} 
					}
					for(int k = post_max; k < m; k++){
						if(postorder[k] == ans){
							OK2 = true; break;
						}
					}
					if(OK1 && OK2){
					  break;
					}
			    }
			    if(ans == first || ans == second){
			    	printf("%d is an ancestor of %d.\n", ans , ans == first ? second : first);
				}else{
					printf("LCA of %d and %d is %d.\n", first , second, ans);
				}
		}
	}
	return 0;
}

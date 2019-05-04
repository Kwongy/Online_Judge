#include<bits/stdc++.h>
using namespace std;
const int MAX = 50000 + 10;
int tree[MAX << 2];
int arr[MAX];
int n;
void push_up(int x){			// 更新当前节点值 
	tree[x] = tree[x*2] + tree[x*2 + 1];
}
void build(int l, int r, int x){
	if(l == r) {				// l区间左端点	r区间右端点	x当前节点位置。 
		tree[x] = arr[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(l, mid, 2*x);
	build(mid + 1, r, 2*x + 1);
	push_up(x);				//向上更新 
}

void update(int l, int r, int x, int node, int k){		//更新 
	if(l == r && l == node){
		tree[x] += k;
		return;
	}
	int mid = (l + r) >> 1;
	if(node <= mid) update(l, mid, x*2, node, k);		// 注意是等于号 
	else update(mid+1, r, x*2 + 1, node, k);
	push_up(x);
}

int query(int l, int r, int x, int q_l, int q_r){		//查询 
	int ans = 0;
	if(q_l <= l && r <= q_r) return tree[x];
	int mid = (r+l) >> 1;
	if(q_l <= mid) ans += query(l, mid, 2*x, q_l, q_r);		
	if(q_r>mid) ans += query(mid+1, r, 2*x+1, q_l, q_r);		//这里不能用else 必须两个if 
	return ans;	
}
int main(){
//	freopen("aa.txt","r",stdin);
//	freopen("bb.txt","w",stdout);
	int t; scanf("%d", &t);
	char s[10];
	int a, b, c;
	for(int q = 1; q <= t; q++){
		printf("Case %d:\n", q);
		scanf("%d", &n);
		memset(tree, 0, sizeof(0)); 
		for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		build(1, n, 1);
		while(true){
			getchar();
			scanf("%s", s);
			if(s[0] == 'E') break;
			scanf("%d %d", &a, &b);
			if(s[0] == 'Q') printf("%d\n", query(1, n, 1, a, b));
			else if(s[0] == 'A') update(1, n, 1, a, b);
			else update(1, n, 1, a, -b);
		}
	}
	return 0;
}

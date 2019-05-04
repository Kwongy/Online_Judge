#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
typedef long long ll;
int tree[MAX << 2];
int arr[MAX];

int n, m;
void update(int l, int r, int x, int node, int k){
	if(l == r && l == node){
		tree[x] = k;
		return;
	}
	int mid = (r + l) >> 1;
	if(mid >= node) update(l, mid, 2 *x, node, k);
	else update(mid+1, r, 2 * x + 1, node, k);
	tree[x] = max(tree[x*2], tree[x*2 + 1]);
}
void build(int l, int r, int x){
	if(l == r){
		tree[x] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, 2*x);
	build(mid+1, r, 2*x+1);
	tree[x] = max(tree[x*2], tree[x*2 + 1]);
}
int query(int l, int r, int x, int ql, int qr){
	if(l >= ql && r <= qr) return tree[x];
	int mid = (r + l) >> 1;
	int ans = 0;
	if(ql <= mid) ans = max(ans, query(l, mid, 2 * x, ql, qr));
	if(qr > mid) ans = max(ans, query(mid + 1, r, 2 * x + 1, ql, qr));
	return ans;
}

int main()
{
//	freopen("aa.txt","r",stdin);
	char s[10];
	int a, b, c;
	while(scanf("%d %d", &n, &m) != EOF){
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);		
		build(1, n, 1);
		for(int i = 0; i < m; i++){
			getchar();
			scanf("%s %d %d", s, &a, &b);
			if(s[0] == 'Q'){
				printf("%d\n", query(1, n, 1, a, b));
			}else{
				update(1, n, 1, a, b);
			}
		}
		
	}
	
	
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n;
int hb[1010] = { 0 };
int pnt[1010];
void uni(int x, int y);
int findroot(int x);
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		pnt[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		getchar();
		for (int j = 0; j < k; j++) {
			int h;
			scanf("%d", &h);
			if (hb[h] == 0)
				hb[h] = i;
			else uni(findroot(hb[h]), i);
		}
	}
	int cnt = 0;
	int count[1010] = { 0 };
	for (int i = 1; i <= n; i++) {
		count[findroot(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		if (count[i] != 0) cnt++;
	}
	printf("%d\n", cnt);
	sort(count + 1, count + n + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (i == 1) printf("%d", count[i]);
		else printf(" %d", count[i]);
	}
	return 0;
}
void uni(int x, int y) {
	int root1, root2;
	root1 = findroot(x);
	root2 = findroot(y);
	if (root1 != root2) pnt[root2] = root1;
}
int findroot(int x) {
	while (pnt[x] != x) {
		x = pnt[x];
	}
	return x;
}

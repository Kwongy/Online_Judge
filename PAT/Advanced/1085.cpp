#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
typedef unsigned long long ull;
using namespace std;
vector<ull> varr;
int binarysearch(ull x, int n);
int main() {
	int n;
	ull p, x;
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		varr.push_back(x);
	}
	sort(varr.begin(), varr.end());
	int maxrange = -1;
	for (int i = 0; i < varr.size(); ++i) {
		int pos = binarysearch(varr[i] * p, varr.size());
		if (maxrange < pos - i + 1) maxrange = pos - i + 1;
	}
	cout << maxrange;
	system("pause");
	return 0;
}
int binarysearch(ull x, int n) {
	int l = -1, r = n;
	int mid;
	while (l+1<r) {
		mid = (l + r) / 2;
		if (varr[mid] > x) r = mid;
		else l = mid;
	}
	return l;
}

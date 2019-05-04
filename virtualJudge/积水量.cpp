#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int arr[20005];
int lt[20005];
int rt[20005];
int main() {
	int t;cin >> t;
	while(t--){
		memset(lt, 0, sizeof(lt));
		memset(rt, 0, sizeof(rt));
		int a; cin >> a;
		int cnt = 0;
		for(int i = 1; i <= a; i++){
			cin >> arr[i];
			lt[i] = max(lt[i-1], arr[i]);		// 前缀最大值 
		}
		for(int i = a; i > 0; i--){
			rt[i] = max(rt[i+1], arr[i]);		// 后缀最大值 
		}
		for(int i = 1; i <= a; i++){
			cnt += min(lt[i], rt[i]) - arr[i];		// 前缀和后缀最大值中的最小值减去原有高度 
		}
		cout << cnt << endl;
	}
	return 0;
}

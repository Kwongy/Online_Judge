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
			lt[i] = max(lt[i-1], arr[i]);		// ǰ׺���ֵ 
		}
		for(int i = a; i > 0; i--){
			rt[i] = max(rt[i+1], arr[i]);		// ��׺���ֵ 
		}
		for(int i = 1; i <= a; i++){
			cnt += min(lt[i], rt[i]) - arr[i];		// ǰ׺�ͺ�׺���ֵ�е���Сֵ��ȥԭ�и߶� 
		}
		cout << cnt << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	int n, a;
	int arr[100005];
	int hash[100005];
	for(int i = 0; i < 100005; i++)	arr[i] = hash[i] = 0;
	cin >> n;
	arr[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a;
		arr[i] = (arr[i-1] * 2) % mod;			//dp 
		if(hash[a]) {							//������ͬ����֮ǰ���ĸ�λ���� 
			arr[i] = (arr[i] - arr[hash[a]-1] + mod) % mod;
			hash[a] = i;
		}
		else hash[a] = i;
	}
	cout << arr[n]-1 << endl;					//��ȥһ�����ַ��� 
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[10005];
int arr[202];
// �� 0 1����
// ��ÿ���������������������ȵ���Ʒ�� �����ܺ͵�һ�� sum/2 Ϊ�������
// ��������Ϊ sum/2 �ı���������ֵ 
int main()
{
	int sum = 0;
	int n;cin >> n; 
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
	int sz = sum / 2;
	for(int i = 0; i < n; i++){
		for(int j = sz; j >= arr[i]; j--){
			dp[j] = max(dp[j], dp[j-arr[i]] + arr[i]);
		}
	}
	cout << sum - dp[sz] * 2  << endl;
	return 0;
}

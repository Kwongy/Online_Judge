#include<bits/stdc++.h>
using namespace std;
/*
	ѭ������Ӷκ�
	1�������������ǿ�������ͨ����Ӷκ͵ķ������������⡣���Ǵ�ÿ��λ�á��Ͽ�������Ȼ����ͨ������Ӷκ͵ķ���ȥ�����������ĸ��Ӷ���O(n^2)��
	2�������ķ���������֮����Ҫ��ĳ��λ���п�����Ϊѭ��������ӶκͿ����ǿ�Խһ����ͷ��β 
*/ 
typedef long long ll;
ll maxn = 0;
ll maxm = 0;
vector<int> vec;
int main(){
	int n;cin >> n;
	vec.resize(n + 1);
	ll sum = 0;
	ll cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
		cnt += vec[i];
		if(sum > 0){
			maxn = max(maxn, sum);
		}else{
			sum = 0;
		}
	}
	sum = 0;
	for(int i = 0; i < n; i++){
		sum += vec[i];
		if(sum < 0){
			maxm = min(sum, maxm);
		}else{
			sum = 0;
		}
	}
	cout << max(maxn, (cnt - maxm)) << endl;
	return 0;
} 

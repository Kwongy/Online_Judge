#include<bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][2];		// dp[i][j]  i����λ��  j�����Ƿ���6 
int dfs(int depth, int pre, int state, bool limit){
	if(depth == -1) return 1;		// ö��������λ   ��ʾ�Ϸ� 
	
	if(!limit && dp[depth][state] != -1) return dp[depth][state];		// ���仯   ֱ�ӷ��� 
	
	int up = limit ? a[depth] : 9;				// ȡ��iλ��ȡֵ��Χ 
	int temp = 0;
	for(int i = 0; i <= up; i++){
		if(i == 4) continue;
		if(i == 2 && pre == 6) continue;
		temp += dfs(depth - 1, i, i==6, limit && i == a[depth]);
	}
	if(!limit) dp[depth][state] = temp;			// ���仯 
	return temp;
}
int solve(int x){		// �ֽ�ÿһλ 
	int pos = 0;
	while(x){
		a[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos - 1, -1, 0, true);
	
}
int main() {
	int l, r;
	while(true){
		cin >> l >> r;
		if(!l && !r) break;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(r) - solve(l - 1));
	}
    return 0;
}                

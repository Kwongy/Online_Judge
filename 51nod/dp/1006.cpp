#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
// array 1000 * 1000 can't compile in temporary space
// it must be in global variable 
char a[1005], b[1005];
int main(){
	scanf("%s %s", a+1, b+1);
	int len1 = strlen(a+1);
	int len2 = strlen(b+1);
	
	// initialition
	for(int i = 0; i <= len1; i++) dp[i][0] = 0;
	for(int j = 1; j <= len2; j++) dp[0][j] = 0; 
	
	// dp
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	char s[1005];
	int k = 0;
	while(len1 >= 1 && len2 >= 1){
		// search the first change character
		if(a[len1] == b[len2]){
			s[k++] = a[len1];
			len1--;
			len2--;
		}else if(dp[len1][len2] == dp[len1- 1][len2]) len1--;
		else len2--;
	}
	
	// inverted order output 
	
	for(int i = k - 1; i >= 0; i--){
		printf("%c", s[i]);
	}
	return 0;
}

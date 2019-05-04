#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int func(int n){
	int ans = (int)sqrt((double(n)));
	while(ans > 0){
		if(n % ans == 0)	return ans;
		else ans--;
	}
	return 1;
}
int cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("aa.txt","r",stdin);
	int n;
	cin >> n;
	int col = func(n);	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(), cmp);
	int row = n / col;
	int level = row / 2 + row % 2;			// 分奇偶   层级是奇数时  有最中间的单个    偶数时没有。 
	int t = 0;
	vector<vector<int> > b(row,vector<int>(col));
	for(int i = 0; i < level; i++){		//按层 按上右下左 转圈 
		for(int j = i; j <= col - 1 - i && t < n; j++)				//上面 
			b[i][j] = arr[t++];
		for (int j = i + 1; j <= row - 2 - i && t <= n - 1; j++)		//右面 
			b[j][col - 1 - i] = arr[t++];
		for (int j = col - i - 1; j >= i && t <= n - 1; j--)		//下面 
			b[row - 1 - i][j] = arr[t++];
		for (int j = row - 2 - i; j >= i + 1 && t <= n - 1; j--)	//左面 
			b[j][i] = arr[t++];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0 ; j < col; j++) {
			printf("%d", b[i][j]);
			if (j != col - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}


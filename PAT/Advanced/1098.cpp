#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;
typedef long long ll;

int a[105], b[105], c[105];

void adjust(int A[], int k, int len) {
	int i;
	A[0] = A[k];
	for (i = 2 * k; i <= len; i *= 2) {
		if (i<len&&A[i]<A[i + 1]) {		//找孩子结点中较大的一个
			i++;
		}
		if (A[0] >= A[i]) break;		
		else{
			A[k] = A[i];				//如果比双亲结点还大，则与双亲结点交换
			k = i;
		}
		A[k] = A[0];
	}
}
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	int flag = 0, t = 1;
	for(int i = 1; i < n; i++){
		if(c[i] <= c[i + 1]) t++;
		else break;
	}
	for(int i = t+1; i <= n; i++){
		if(c[i] != a[i]){
			flag = 1;
			break;
		}
	}
	if(flag){
		cout << "Heap Sort" << endl;
		t = 0;
		for(int i = n; i > 1; i--){
			if(c[i] >= c[i - 1]) t++;
			else break;
		}
		swap(c[1], c[n - t]);
		int len = n - t - 1;
		for (int i = len/2; i > 0; i--){
			adjust(c, i, len);			//调整以A[i]为双亲结点的子堆
		}
	}else{
		cout << "Insertion Sort" << endl;
		sort(c+1, c+t+2);
	}
	cout << c[1];
	for(int i = 2; i <= n; i++){
		cout <<" " << c[i];
	}
	return 0;
}

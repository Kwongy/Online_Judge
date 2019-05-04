#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int end[110], orgin[110];
	int n, m = 0; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &orgin[i]);
	for(int i = 0; i < n; i++) scanf("%d", &end[i]);
	while(end[m] <= end[m + 1]) m++;
	int cmp = ++m;
	while(cmp < n && end[cmp] == orgin[cmp]) cmp++;
	if(cmp == n){
		printf("Insertion Sort\n");
		sort(orgin,orgin + m + 1);
	}else{
		printf("Merge Sort\n");
		int flag = 1, k = 1;
		while(flag){
			flag = 0;
			for(int i = 0; i < n; i++) if(orgin[i] != end[i]) flag = 1;
			k *= 2;
			for(int i = 0; i < n / k; i++) sort(orgin + i * k, orgin + (i + 1) * k);
			sort(orgin + (n / k) * k, orgin + n);
		}
	}
	for(int i = 0; i < n; i++){
		if(i != n - 1) cout << orgin[i] << " ";
		else cout << orgin[i] << endl;
	} 
	return 0;
}

#include<iostream>
#include<vector>
#define DEBUG 1
using namespace std;
int main(){
	#if DEBUG
	freopen("aa.txt","r",stdin);
	#endif	
	vector<int> prime(50000,0);
	prime[0] = prime[1] = 1;
	for(int i = 2; i < 50000; i++){
		if(!prime[i]){
			for(int j = 2; i * j < 50000; j++)	prime[i * j] = 1;
		}
	}
	int n, m, size, a;
	scanf("%d %d %d", &size, &n, &m);
	if(prime[size])	while(prime[size]) size++;
	vector<int> hashtable(size, -1);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		int flag = 1;
		for(int j = 0; j <= size; j++){
			int v = (a + j * j) % size;
			if(hashtable[v] == -1){
				hashtable[v] = a;
				flag = 0;
				break;
			}
		}
		if(flag) printf("%d cannot be inserted.\n", a);
	}
	int cnt = 0;
	for(int i = 0; i < m; i++){
		scanf("%d", &a);
		for(int j = 0; j <= size; j++){
			cnt++;
			int v = (a + j * j) % size;
			if(hashtable[v] == a || hashtable[v] == -1) break;
		}
	}
	printf("%.1lf\n", cnt * 1.0 / m);
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
vector<pair<int, int> > p(60000);
int main(){
	
//	freopen("aa.txt","r",stdin);
	
	int n; cin >> n;
	int arr[100050] = {0};
	int a, b, m;
	p.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		pair<int, int> t = make_pair(a, b);
		p[i] = t;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a);
		arr[a]++;
	}
	for(int i = 0; i < n; i++){
		a = p[i].first;
		b = p[i].second;
		if(arr[a] && arr[b]){
			arr[a] = 0;
			arr[b] = 0;
			m -= 2;
		}
	}
	printf("%d\n", m);
	for(int i = 0; i < 100050; i++){
		if(arr[i]){
			if(m == 1){
				printf("%05d", i);
				break;
			}else{
				printf("%05d ", i);
				m--;
			}
		}
	}
	return 0;
}

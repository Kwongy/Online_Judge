#include<bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int a[MAX];
int ans; 
int s, t;
map<pair<int, int>, int> mp;
int gcd(int x, int y){
	return !(x%y) ? y : gcd(y, x % y);
}
int main(){
	int n; cin >> n;
	ans = s = t = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(!temp && !a[i]) s++;
		else if(!temp) t++;
		else if(!a[i]) continue;
		else{
			if(a[i] < 0){
				a[i] = -a[i];
				temp = -temp;
			}
			int gd = gcd(a[i], abs(temp));
			pair<int, int> p = make_pair(a[i]/gd, temp/gd);
			mp[p]++;
			ans = max(ans, mp[p]); 
		}
	}
	ans = max(t, ans);
	cout << ans + s << endl;
	
	
	return 0;
}

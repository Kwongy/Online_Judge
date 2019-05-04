#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
	freopen("aa.txt","r",stdin);
	int m, n, k, a, b; cin >> m >> n >> k;
	while(k--){
		bool ok = true;
		stack<int> st;
		queue<int> start;
		queue<int> end;
		for(int i = 1; i <= n; i++){
			scanf("%d",&a);
			end.push(a);
			start.push(i);
		}
		while(end.size() != 0){
			bool yes = false;
			a = end.front();
			end.pop();
			if(st.size() != 0){
				b = st.top();
				if(a == b){
					yes = true;
					st.pop();
				}else{
					while(start.size() != 0){
						b = start.front();
						start.pop();
						if(st.size() == m){
							ok = false;
							break;
						}else{
							if(a == b){
								yes = true;
								break;	
							}else{
								st.push(b);
							}
						}
					}
				} 
			}else{
				while(start.size() != 0){
						b = start.front();
						start.pop();
						if(st.size() == m){
							ok = false;
							break;
						}else{
							if(a == b){
								yes = true;
								break;	
							}else{
								st.push(b);
							}
						}
					}
			}
		}
		if (st.size() != 0){
			ok = false;
		} 
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 

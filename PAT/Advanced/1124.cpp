#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m, s; cin>> n >> m >> s;
    string t;
    set<string> st;
    int flag = 0; 
    for(int i = 1; i <= n; i++){
    	cin >> t;
    	if(st.find(t) != st.end()) s++;
    	if(st.find(t) == st.end() && i == s){
    		cout << t << endl;
    		st.insert(t);
    		flag = 1;
    		s += m;
		}
	}
	if(!flag) cout << "Keep going..." << endl;
    return 0;
}

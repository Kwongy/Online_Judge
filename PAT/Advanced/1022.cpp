#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
using namespace std;
void query(map<string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(set<int> ::iterator it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main(){
	map<string,set<int> > title,author,kw,pub,year;
	int n, m, id; cin >> n;
	string t,a,k,p,y;
	while(n--){
		scanf("%d\n",&id);
		getline(cin, t);
        title[t].insert(id);
        getline(cin, a);
        author[a].insert(id);
     	while(cin >> k) {
            kw[k].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, p);
        pub[p].insert(id);
        getline(cin, y);
        year[y].insert(id);
	}
	cin >> m;
	getchar();
	for(int i = 0; i < m; i++){
		getline(cin, a);
        n = a.at(0)- '0';
		t = a.substr(3,a.length());
		cout << a << endl;
		if(n == 1) query(title, t);
        else if(n == 2) query(author, t);
        else if(n == 3) query(kw, t);
        else if(n == 4) query(pub,t);
        else if(n == 5) query(year, t);
	}
	return 0;
}

//#include<iostream>
//#include<map>
//#include<set>
//using namespace std;
//map<string,set<int> > student;
//int main(){
//	int n, m; scanf("%d %d\n",&n, &m);
//	string input;
//	input.resize(4);
//	int k, num;
//	for(int i = 0; i < m; i++){
//		scanf("%d %d",&k, &num);
//		for(int j = 0; j < num; j++){
//			scanf("%s",&input[0]);
//			student[input].insert(k);
//		}
//	}
//	for(int i = 0; i < n; i++){
//		scanf("%s",&input[0]);
//		k = student[input].size();
//		printf("%s %d",input.c_str(),k);
//		if(k != 0){
//			for(set<int>::iterator it = student[input].begin(); it != student[input].end(); it++){
//				printf(" %d",*it);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//} 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int getid(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
 
int main() {
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for(int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for(int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}

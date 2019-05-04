//#include<iostream>
//#include<cstring>
//#include<map>
//using namespace std;
//int arr[10005];
//int list[10005];
//int point = 0;
//int main(){
////	freopen("aa.txt","r",stdin);
//	int n; cin >> n;
//	string pop = "Pop";
//	string peek = "PeekMedian";
//	string push = "Push";
//	string invalid = "Invalid";
//	string input;
//	int in;
//	map<int,int> mp;
//	while(n--){
//		cin >> input;
//		if(input.compare(push) == 0){
//			cin >> in;
//			arr[point] = in;
//			point ++;
//			mp[in] ++;
//		}else{
//			if(input.compare(pop) == 0){
//				if(point > 0){
//					printf("%d\n",arr[point - 1]);
//					point--;
//					mp[arr[point]] --;
//					if(mp[arr[point]] == 0){
//						mp.erase(arr[point]);
//					}
//				}else{
//					cout << invalid << endl;
//				}
//			}else{
//				int sz = (mp.size() + 1)/2;
//				if(sz != 0){
//					map<int,int>::iterator it = mp.begin(),it1 = mp.begin();
//					int i = 1;
//					for(;it != mp.end();it++){
//						list[i] = it->first;
//						i++;
//					}
//					printf("%d\n",list[sz]);
//				}else{
//					cout << invalid << endl;
//				}
//				
//			}
//		}
//	}
//	return 0;
//}
#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}

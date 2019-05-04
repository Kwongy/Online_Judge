//#include<iostream>
//#include<vector>
//using namespace std;
//long sum[20005];
//struct point{
//	int start,end,min;
//};
//vector<point> vec;
//vector<point> v;
//int main(){
//	long temp;
//	int n, m, b, index, min = 1 << 30; cin >> n >> m;
//	bool isfind = false;
//	for(int i = 1; i <= n; i++){
//		scanf("%d",&b);
//		sum[i] = sum[i - 1] + b;
//		for(int j = 0; j < i; j++){
//				temp = sum[i] - sum[j];
//				if(temp == m) {
//					isfind = true;
//					point p ={j + 1, i, temp};
//					vec.push_back(p);
//				}else if(temp > m){
//					if(temp <= min){
//						point p ={j + 1, i, temp};
//						v.push_back(p);
//					 	min = temp;
//					}
//				}
//			}
//	}
//	if(isfind){
//		for(int i = 0; i < vec.size(); i++){
//			printf("%d-%d\n",vec[i].start,vec[i].end);
//		}
//	}else{
//		for(int i = 0; i < v.size(); i++){
//			if(min == v[i].min)	printf("%d-%d\n",v[i].start,v[i].end);
//		}
//	}
//	return 0;
//} 
#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum) {
    int left = i, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if(sum[mid] - sum[i-1] >= m)
            right = mid;
        else
            left = mid + 1;
    }
    j = right;
    tempsum = sum[j] - sum[i-1];
}
int main() {
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = sum[n];
    for(int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if(tempsum > minans) continue;
        if(tempsum >= m) {
            if(tempsum < minans) {
                resultArr.clear();
                minans = tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    int c = resultArr.size();
    for(int i = 0; i < c; i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i+1]);
    return 0;
}

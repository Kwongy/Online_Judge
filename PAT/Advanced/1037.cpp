#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> in1,in2,out1,out2;
bool cmp1(int a,int b)  
{  
    return a>b;  
} 
int main(){
	int n, m, a; cin >> n;
	long long out = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		if(a > 0) in1.push_back(a);
		else in2.push_back(a);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		scanf("%d",&a);
		if(a > 0) out1.push_back(a);
		else out2.push_back(a);
	}
	sort(in1.begin(),in1.end(),cmp1);
	sort(in2.begin(),in2.end());
	sort(out1.begin(),out1.end(),cmp1);
	sort(out2.begin(),out2.end());
	n = min(in1.size(),out1.size());
	m = min(in2.size(),out2.size());
	for(int i = 0; i < n; i++) out += in1[i]*out1[i];
	for(int i = 0; i < m; i++) out += in2[i]*out2[i];
	printf("%lld\n",out);
}

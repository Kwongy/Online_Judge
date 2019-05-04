#include<iostream>
using namespace std;

int main(){
	freopen("aa.txt","r",stdin);
	int a, b, c;
	int o1, o2, o3;
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&o1,&o2,&o3);
	o3 += c;
	o2 += b + o3/29;
	o1 += a + o2/17;
	o3 = o3 % 29;
	o2 = o2 % 17;
	printf("%d.%d.%d",o1,o2,o3);
	return 0;
}

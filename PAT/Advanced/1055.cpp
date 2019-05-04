#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
struct rich{
	char name[9];
	int age;
	int worth;
	bool operator < (const rich &A) const{
		if (worth != A.worth)
			return worth > A.worth;
		else if (age != A.age)
			return age < A.age;
		else
			return strcmp(name, A.name) < 0;
	}
}num[100000];
 
int main(){
	//freopen("G:\\input.in", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i){
		scanf("%s%d%d", num[i].name, &num[i].age, &num[i].worth);
	}
	sort(num, num + n);
	int ageCount[201] = {0};
	int filter[100001];
	int filter_num = 0;
	for (int i = 0; i < n; i++){
		if (++ageCount[num[i].age] < 101){
			filter[filter_num++] = i;
		}
	}
	for (int i = 1; i <= k; i++){
		int m, amin, amax;
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i);
		int index = 0;
		for (int j= 0; j < filter_num; j++){
			int k = filter[j];
			if (num[k].age >= amin && num[k].age <= amax && index < m){
				printf("%s %d %d\n", num[k].name, num[k].age, num[k].worth);
				index++;
			}
		}
		if (index == 0)
			printf("None\n");
	}
	return 0;
}

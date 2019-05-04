#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct price{
	int number;
	double price;
	double per_p;
};
int cmp(const struct price &a,const struct price &b){
	return a.per_p > b.per_p;
}
int main() {
	vector<struct price> arr;
    double arr1[5555], temp, sum = 0;;
	int n, need;
    cin >> n >> need;
    arr.resize(n + 100);
    for(int i = 0; i < n; i++){
    	cin >> arr1[i];
	}
	
    for(int i = 0; i < n; i++){
    	cin >> temp;
    	arr[i].number = arr1[i];
    	arr[i].price = temp;
    	arr[i].per_p = temp / arr1[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	int i = 0;
	while(need > 0){
		if(i == n) break;
		if(need > arr[i].number){
			need -=  arr[i].number;
			sum += arr[i].price;
			i++;
		}else{
			sum += arr[i].per_p * need;
			need = 0;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}


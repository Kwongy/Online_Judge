#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int arr[3000];
    int t; scanf("%d", &t);
    while(t--){
    	int k; scanf("%d", &k);
    	int flag = 1;
    	for(int i = 1;i <= k; i++){
    		scanf("%d", &arr[i]);
    		if(flag){
    			for(int j = i-1; j > 0; j--){
    				if(arr[i] == arr[j] || abs(arr[i] - arr[j]) == abs(i - j)){
	    				flag = 0;break;
					}				
				}
			}
		}
    	
    	if(!flag) cout << "NO" << endl;
    	else cout << "YES" << endl;
	}
    return 0;
}

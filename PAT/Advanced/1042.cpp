#include<iostream>
using namespace std;
int main(){
	int n; cin >> n;
	int input[55];
	int output[55];
	for(int i = 1; i <= 54; i++) cin >> input[i];
	for(int i = 1; i <= 54; i++){
		int temp = i;
		for(int j = 0; j < n; j++){
			temp = input[temp];
		}
		output[temp] = i;
	}
	int first=1;
    for(int k=1;k<=54;k++)
    {
        if(first)first=0;
        else cout<<" ";
        if(output[k]>=1&&output[k]<=13)cout<<'S'<<output[k];
        else if(output[k]<=26)cout<<'H'<<output[k]-13;
        else if(output[k]<=39)cout<<'C'<<output[k]-26;
        else if(output[k]<=52)cout<<'D'<<output[k]-39;
        else cout<<'J'<<output[k]-52;
    }
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
//	freopen("input.txt","r",stdin);
	int a,b;
	cin>>a>>b;
	char output[100000];
	output[0]=a+'0';
	for(int i=0;i<b-1;i++){
		char temp[100000];
		int len =strlen(output);
		if(len==1){
			output[1]=1+'0';
			continue;
		}
		char c=output[0];
		int count=1;
		int index=0;int j;
		for(j=1;j<len;j++){
			if(output[j]==c){
				count++;
			}else{
				temp[index]=c;
				index++;
				temp[index]='0'+count;
				index++;
				c=output[j];
				count=1;
			}
		}
		temp[index]=c;
			index++;
		temp[index]='0'+count;
		
		strcpy(output,temp);
		
	}
	cout<<output;
	return 0;
}

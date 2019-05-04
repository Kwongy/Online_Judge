#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
	  string a;
	  cin>>a;
	  int len=a.size();
	  int y=(len+2)/3;
	  int x=len-y-y;
	  for(int i=0; i<y-1; i++){
	    cout<<a[i];
	    for(int j=0; j<x; j++) cout<<" ";
	    cout<<a[len-i-1];
	    cout<<endl;
	  }
	  for(int k=0; k<x+2; k++)cout<<a[y+k-1];
	  return 0;
}

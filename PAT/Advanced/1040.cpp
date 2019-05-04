#include<iostream>
using namespace std;
int n;
char s[2200];
int SymString(int l, int r){
  int left=l, right=r;
  while(left>=0 && right <= n && s[left]==s[right]){
    left--;
    right++;
  }
  return right-left-1;
}
int main(){
  n = 0;
  int max1 = 1;
  char c;
  while((c=getchar())!=EOF){
  	s[n++] = '#';
  	s[n++] = c ;
  }
  s[n] = '#';
  for(int i=0; i <= n; i++){
    int len=SymString(i, i);
    max1 = max(len,max1);
  }
  cout<<max1/2;
  return 0;
}

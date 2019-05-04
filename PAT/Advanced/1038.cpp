#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool cmp(const string &a,const string &b){
	return a + b< b + a;
//	int len1 = a.length();
//	int len2 = b.length();
//	int i,n = min(len1,len2),m = max(len1,len2);	
//	for(i = 0; i < n; i++){
//		if(a[i] != b[i]) return a[i] < b[i];
//	}
//	if(i == len1){
//		for(; i < m; i++){
//			if(a[i - n] != b[i]) return a[i - n] < b[i];
//		}
//	}else{
//		for(; i < m; i++){
//			if(b[i] != b[i - n]) return a[i] < b[i - n];
//		}
//	}
}
int main(){
	int n, i; cin >> n;
	vector<string> vec(n);
	for(i = 0; i < n; i++){
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end(),cmp);
	  string out;
	  for (i=0;i<n;i++)
	      out += vec[i];
	  for (i=0;i<out.size()&&out[i]=='0';i++);
	  if (i==out.size())
	      printf("0");
	  else 
	      printf("%s",out.c_str()+i);
	  printf("\n");
	return 0;
}

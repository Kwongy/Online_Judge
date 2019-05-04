#include <string>
#include<iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n,cnt = 0;
	cin>>n;
	string num;
	double sum = 0.0;
	for(int i=0;i<n;i++){
		cin>>num;
		char * pos;
		double value = strtod(num.c_str(),&pos);
		bool ok = true;
		if(*pos != '\0')ok = false;
		if(value<-1000 || value >1000)ok = false;
		int lpos = num.find_last_of(".");
		if(lpos != string::npos) if(num.size() - lpos > 3)ok = false;
		if(ok){
			cnt++;
			sum += value;
		}
		else
			printf("ERROR: %s is not a legal number\n",num.c_str());
	}
	if(cnt != 0){
		if(cnt != 1)printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
		else printf("The average of 1 number is %.2lf\n",sum);
	}
	else cout<<"The average of 0 numbers is Undefined\n";
	return 0;
}

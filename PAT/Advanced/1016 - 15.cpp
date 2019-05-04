#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct bill{
	char name[20];
	int month;
	int day;
	int hour;
	int min;
	int state;
};
char status[] = "on-line";
vector<bill> vec,output;
int daycost = 0;
int cost[24];
bool cmp(const struct bill &a,const struct bill &b){
	if(strcmp(a.name,b.name)){
		return (strcmp(a.name,b.name) < 0);
	}else{
		if(a.day != b.day) return a.day < b.day;
		else if(a.hour != b.hour) return a.hour < b.hour;
		else return a.min < b.min;
	}
}
double cal(const struct bill &a,const struct bill &b){
	double spend = 0;
	int time = 0, pay = 0;
	int d1 = a.day;int hh1=a.hour;int mm1=a.min;int d2=b.day;int hh2=b.hour;int mm2=b.min;
	for (; d1 < d2; ++d1) {
		time += (60 - mm1);
		pay += (60 - mm1) * cost[hh1++];
		for (mm1 = 0; hh1 < 24; ++hh1){
		pay += 60 * cost[hh1];
		time += 60;
		}
    hh1 = 0;
   }
	for (; hh1 < hh2; ++hh1) {
		time += (60 - mm1);
		pay += (60 - mm1) * cost[hh1];
		mm1 = 0;
	  }
  time += (mm2 - mm1);
  pay += (mm2 - mm1) * cost[hh1];
	spend = (double)pay/100;
	printf("%02d:%02d:%02d %02d:%02d:%02d %02d $%.2f\n",a.day,a.hour,a.min,b.day,b.hour,b.min,time,spend);
	return spend;
}
int main(){
//	freopen("aa.txt","r",stdin); 
	for(int i = 0; i < 24; i++){
		cin >> cost[i];
		daycost += cost[i];
	}
	daycost *= 60; 
	int n; cin >> n; getchar();
	vec.resize(n);
	char temp1[20],temp2[20];
	int a,b,c,d;
	for(int i = 0; i < n; i++){
		scanf("%s %d:%d:%d:%d %s",temp1,&a,&b,&c,&d,temp2);
		bill bl;
		bl.month = a; bl.day = b; bl.hour = c; bl.min = d;
		strcpy(bl.name,temp1);
		int q = strcmp(status,temp2);
		if(q) bl.state = 0;
		else bl.state = 1;
		vec[i] = bl;
	}
	sort(vec.begin(),vec.end(),cmp);
	int flag = 0, index = 0, yes = 0;
	for(int i = 0; i < vec.size(); i++){
		if(!yes){
			if(vec[i].state == 1){
				index = i; yes = 1; flag = vec[i].state; strcpy(temp1,vec[i].name);
			}
		}else{
			if(strcmp(vec[i].name,temp1)){
				if(vec[i].state == 1){
					index = i; yes = 1; flag = vec[i].state; strcpy(temp1,vec[i].name);
				}else yes = 0;
			}else{
				if(flag == 1){
					if(vec[i].state == 0){
						output.push_back(vec[index]);
						output.push_back(vec[i]);
						yes = 0;
					}else{
						index = i; yes = 1; flag = vec[i].state; strcpy(temp1,vec[i].name);
					}
				}
			}
		}
	}
	sort(output.begin(),output.end(),cmp);
	double total,now;
	bill l1,l2;
	flag = 0; temp1[0] = '@';
	for(int i = 0; i < output.size(); i += 2){
		l1 = output[i];
		l2 = output[i+1];
		if(strcmp(l1.name,temp1) != 0){
			if(temp1[0] == '@'){
				printf("%s %02d\n",l1.name,l1.month);  
			}else{
				printf("Total amount: $%.2f\n",total);  
                total = 0;  
                printf("%s %02d\n",l1.name,l1.month); 	
			}
			strcpy(temp1,l1.name);
		}
		total += cal(l1,l2);
	}
	printf("Total amount: $%.2f\n",total); 
	return 0;
} 

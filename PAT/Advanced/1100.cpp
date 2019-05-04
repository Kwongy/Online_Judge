#include<iostream>
#include<cstring>
#include <map>
#include <cstdlib>
using namespace std;
 
string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
	freopen("aa.txt","r",stdin);
	int n; cin >> n; getchar();
	map<string, int> maze1, maze2;
	for(int i=0;i<13;i++)
	{
		maze1[low[i]]=i;
		maze2[high[i]]=i;
	}
	for(int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		if(isdigit(s[0])){
			int num = atoi(s.c_str());
			int l = num%13, r = num / 13;
			if(l == 0 && r == 0) cout << "tret\n";
			else if(l == 0) cout << high[r] << endl;
			else if(r == 0) cout << low[l] << endl; 
			else cout << high[r] << " " << low[l] << endl;
		}else{
			int index = 0;
			while(s[index] != ' ' && index < s.size()) index++;
			int h = 0 ,l = 0;
			if(index == s.size()){
				if(maze1.find(s) != maze1.end()) l = maze1[s];
				else h = maze2[s];
			}else{
				h = maze2[s.substr(0, index)];
				l = maze1[s.substr(index+1)]; 
			}
			cout << h*13 + l << endl;
		}
	}
	return 0;
} 

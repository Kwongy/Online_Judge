#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
 
void findBMstr(string str0){
    string str;
    str += "$#";
    int n=str0.size();
    for(int i = 0; i < n; i++){
        str += str0[i];
        str += "#";
    }
    int len=str.size();
    int *p = new int[len + 1];
    memset(p, 0, sizeof(p));
    int mx = 0, id = 0;
    for(int i = 1; i <=  len; i++){
        if(mx > i){
            p[i] = (p[2*id - i] < (mx - i) ? p[2*id - i] : (mx - i));
        }
        else{
            p[i] = 1;
        }
        while(str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if(i + p[i] > mx){
            mx = i + p[i];
            id = i;
        }
    }
    int Max = 0, ii;
    for(int i = 1; i < len; i++){
        if(p[i] > Max){
            ii = i;
            Max = p[i];
        }
    }
    Max--;
    cout << Max << endl;
//    int s = ii - Max ;
//    int e = ii + Max;
//    for(int i = s; i <= e; i++){
//        if(str[i] != '#'){
//            cout << str[i];
//        }
//    }
//    cout << endl;
    delete  p;
}
int main()
{
	int n; cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		cout << "case #" << i << ": " << endl; 
    	findBMstr(str);
	}
    
    
    return 0;
}

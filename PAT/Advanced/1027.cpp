#include<iostream>

using namespace std;

int main(){
	int a, b ,c; cin >> a >> b >> c;
	char model[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	cout << "#" << model[a/13] << model[a%13] << model[b/13] << model[b%13]<< model[c/13] << model[c%13] << endl;
	return 0;
}

#include<iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int left = 0, right = 0, a = 1, now = 1;
	long out = 0;
	while(n / a){
		left = n / (a * 10);
		right = n % a;
		now = n / a % 10;
		if(now == 0) out += left * a;			//�����ǰλ==0�����Ϊ����1 ������ɸ���λ������= ����Ϊ����*��ǰλ��
		else if(now == 1) out += left * a + right + 1;//�����ǰλ==1�����Ϊ����1 ������ܸ���λ�Լ���λӰ�죬= ������Ϊ����*��ǰλ����+����λ����+1��
		else out += (left + 1) * a; //�����ǰλ>1�����Ϊ����1 ������ɸ���λ������= (����Ϊ����+1)*��ǰλ��
		a = a*10;
	}
	cout << out << endl;
	return 0;
} 

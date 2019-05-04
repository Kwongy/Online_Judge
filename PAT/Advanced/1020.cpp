#include<iostream>
#include<vector>
using namespace std;

vector<int> in(35),post(35),level(10000,-1);
void pre(int root, int start, int end, int index){	//���Ӻ���������ң�������������������� 
	if(start > end) return;
	int i = start;
	while(i < end && post[root] != in[i])	i++;		//������������Ҹ� 
	level[index] = post[root];							//��¼��α���λ��
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);		//�����������ڵ�Ϊ���һ���� 
	pre(root - 1, i + 1, end, 2 * index + 2);  
}
int main(){
	int n; cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    for(int cnt = 0, i = 0; i < level.size(); i++) {
        if (level[i] != -1) {
            if (cnt != 0) printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n) break;
    }
	return 0;
} 

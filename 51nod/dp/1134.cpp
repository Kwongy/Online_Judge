#include<bits/stdc++.h>
using namespace std;
int main(){
	/*
		�������һ������b����ĩβ����ҪС��
		��ô˵�����е���������һ�������ű�a[i]Ҫ�������
		��a[i]�ѵ�һ����a[i]Ҫ������滻���ǲ���Ӱ�������еĳ��ȵ�
	*/
	int n;
	// posʼ����һ��������������� 
	int pos[50005], arr[50005];
	scanf("%d",&n);
    
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	pos[0] = arr[0];
	int len = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] > pos[len-1]){
			pos[len++] = arr[i];
		}else{
			int p = lower_bound(pos, pos+len-1, arr[i]) - pos;
			pos[p] = arr[i];
		}
	}
	printf("%d\n", len);
	return 0;
}

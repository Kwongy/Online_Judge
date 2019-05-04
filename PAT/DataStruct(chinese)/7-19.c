#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int num;
	struct node *next;
}Node, *pNode;
int count = 0;
pNode headinsert(){
	pNode L = (pNode)malloc(sizeof(Node));
	L->next = NULL;
	pNode s;
	int temp;
	scanf("%d", &temp);
	if(temp != -1){
		//	头插法
		while(temp != -1){
			count++;
			s = (pNode)malloc(sizeof(Node));
			s->num = temp;
			s->next = L->next;
			L->next = s;
			scanf("%d", &temp);
		}
	}else{
		L = NULL;
	}
	return L;
}
void destroy(pNode L){
	pNode r;
	while(L){
		r = L;
		L = L->next;
		free(r);
	}
}
int main(){
//	freopen("aa.txt", "r", stdin);

// 直接头插法  第K个就是 
	int n; scanf("%d", &n);
	pNode L = headinsert();
	if(n > count) {
		printf("NULL\n");
	}else{
		while(n){
			L = L->next;
			n--;
		}
		printf("%d", L->num);
	}
	destroy(L);
	return 0;
}

#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int num;
	struct node *next;
}Node, *pNode;
pNode input(){
	pNode L = (pNode)malloc(sizeof(Node));
	pNode s, r = L;
	int temp;
	scanf("%d", &temp);
	if(temp != -1){
		while(temp != -1){
			s = (pNode)malloc(sizeof(Node));
			s->num = temp;
			r->next = s;
			r = s;
			scanf("%d", &temp);
		}
		r->next = NULL;
	}else{
		L = NULL;
	}
	return L;
}
int main(){
	freopen("aa.txt", "r", stdin);
	pNode n1 = input();
	pNode n2 = input();
	int index = 0;
	int flag = 0;
	if(n1) n1 = n1->next;
	else index++;
	if(n2) n2 = n2->next;
	else index++;
	while(n1 && n2){
		if(n1->num < n2->num){
			if(!flag){
				printf("%d", n1->num);
				flag = 1;
			}else{
				printf(" %d", n1->num);
			}
			n1 = n1->next;
		}else{
			if(!flag){
				printf("%d", n2->num);
				flag = 1;
			}else{
				printf(" %d", n2->num);
			}
			n2 = n2->next;
		}
	}
	while(n1){
		if(!flag){
				printf("%d", n1->num);
				flag = 1;
			}else{
				printf(" %d", n1->num);
			}
			n1 = n1->next;
	}
	
	while(n2){
		if(!flag){
				printf("%d", n2->num);
				flag = 1;
			}else{
				printf(" %d", n2->num);
			}
			n2 = n2->next;
	}
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node
{
	int v;//������� 
	int height;//���߶� 
	node *lchild;
	node *rchild;
} *root;
 
node *newnode(int v)//����һ���½�㣬�½��ĸ߶���Ϊ1 
{
	node *Node = new node;
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;
}
 
int getHeight(node *root)//��õ�ǰ���߶� 
{
	if(root==NULL)
	return 0;
	return root->height;
}
 
void updateHeight(node *root)//���µ�ǰ���ڵ�߶� 
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
 
int getBalanceFactor(node *root)//��ȡƽ�����ӣ�ͨ��������-�������߶� 
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
//������tempָ����ڵ���������������������� 
//1.��temp����������Ϊroot��������
//2.��root��Ϊtemp��������
//3.��temp����Ϊ�µ�root 
void L(node* &root)//����node* &root��Ϊ��ʹroot��Ϊһ��ָ����в��� 
{
	node *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
 
void R(node* &root)
{
	node *temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
//�����������ǻ�������������е�left����right��right����left������ 
void insert(node* &root,int v)//��BST������룬�������ʵ�����ʹ�ø���ʼ����AVL�� 
{
	if(root==NULL)
	{
		root=newnode(v);
		return;
	}
	if(v<root->v)
	{
		insert(root->lchild,v);
		updateHeight(root);//ע�ⲻҪ���Ǹ��½��߶� 
		if(getBalanceFactor(root)==2)
		{
			if(getBalanceFactor(root->lchild)==1)//LL
			{
				R(root);
			}
			else if(getBalanceFactor(root->lchild)==-1)//LR
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2)
		{
			if(getBalanceFactor(root->rchild)==-1)//RR
			{
				L(root);
			}
			else if(getBalanceFactor(root->rchild)==1)//RL
			{
				R(root->rchild);//RL�������һ���������ΪRR��Ȼ���������� 
				L(root);
			}
		}
	}
}
int main()
{
	int n,data;
	cin>>n;
	for(int i;i<n;i++)
	{
		cin>>data;
		insert(root,data);
	}
	cout<<root->v<<endl;
	return 0;
}

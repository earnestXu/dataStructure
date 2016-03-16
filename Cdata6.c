/*
 * Cdata6.c
 *ջ��ʵ��������㷨
 *  Created on: 2016��3��16��
 *      Author: Earnest
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node * pNext;
}Node,*pNode;

typedef struct stack{
	pNode pTop;
	pNode pBottom;
}Stack,*pStack;

//��������
void initStack(pStack pStk);		//��ʼ��ջ
void pushStack(pStack pStk, int val);	//��ջ����
void traverseStack(pStack pStk);		//����ջ
bool popStack(pStack pStk,int * pVal);		//��ջ����
bool isEmptyStack(pStack pStk);		//�ж�ջ�Ƿ�Ϊ��
void clearStack(pStack pStk);		//���ջ��Ԫ��


//��������
int main(void){
	//int m;
	Stack stk ;
	initStack(&stk);

	pushStack(&stk,3);
	pushStack(&stk,5);
	pushStack(&stk,9);
	pushStack(&stk,8);

	traverseStack(&stk);
	clearStack(&stk);
	/*
	popStack(&stk,&m);
	printf("ȡ����ֵΪ��%d\n",m);
	*/
	traverseStack(&stk);
	return 0;
}

void initStack(pStack pStk){
	//int length,i=0;
	pNode p=(pNode)malloc(sizeof(Node));
	if(NULL == p){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	pStk->pBottom=p;
	pStk->pTop=p;
	pStk->pBottom->pNext=NULL;
	/*
	printf("�������ʼ��ջ�Ľ�������\n");
	scanf("%d",&length);
	for(i=0;i<length;++i){
		pNode q=(pNode)malloc(sizeof(Node));
		if(NULL == q){
				printf("��̬�ڴ����ʧ�ܣ�");
				exit(-1);
			}
		printf("�������%d������ֵ��\n",(i+1));
		scanf("%d",&(q->data));
		pStk->pTop->pNext=q;
		pStk->pTop=q;
	}
	*/
	return;
}


void pushStack(pStack pStk, int val){
	pNode p=(pNode)malloc(sizeof(Node));
	if(NULL == p){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else
	{
		p->data=val;
		//pStk->pTop->pNext=p;  �������������ش��󣬳�ջ�������鷳�������ܴ�
		p->pNext=pStk->pTop;
		pStk->pTop=p;
	}
}

void traverseStack(pStack pStk){
	if(isEmptyStack(pStk))
	{
		printf("���������");
		return;
	}
	else
	{

		pNode p;
		p=pStk->pTop;
		while(p != pStk->pBottom){
			printf("%d\n",(p->data));
			p=p->pNext;
		}
		return;
	}

}

bool popStack(pStack pStk,int * pVal){
	if(isEmptyStack(pStk)){
		printf("��ջʧ�ܣ�");
		return false;
	}
	else{
		pNode p=pStk->pTop;
		*pVal=p->data;
		pStk->pTop=p->pNext;
		free(p);
		p=NULL;
		return true;
	}
}


bool isEmptyStack(pStack pStk){
	if(pStk->pBottom == pStk->pTop){
		printf("��ջΪ�գ�");
		return true;
	}
	else{
		printf("��ջ���գ�\n");
		return false;
	}
}

void clearStack(pStack pStk){
	if(isEmptyStack(pStk)){
		printf("��ջ�������");
		return;
	}
	else
	{
		pNode q=NULL;
		pNode p=pStk->pTop;
		while(p != pStk->pBottom){
			q=p->pNext;
			free(p);
			p=q;;
		}
		pStk->pTop=pStk->pBottom;   //һ�������٣���Ȼ��պ����������ѭ��
	}
}

/*
 * Cdata6.c
 *栈的实现与操作算法
 *  Created on: 2016年3月16日
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

//函数声明
void initStack(pStack pStk);		//初始化栈
void pushStack(pStack pStk, int val);	//入栈函数
void traverseStack(pStack pStk);		//遍历栈
bool popStack(pStack pStk,int * pVal);		//出栈函数
bool isEmptyStack(pStack pStk);		//判断栈是否为空
void clearStack(pStack pStk);		//清空栈内元素


//主函数区
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
	printf("取出的值为：%d\n",m);
	*/
	traverseStack(&stk);
	return 0;
}

void initStack(pStack pStk){
	//int length,i=0;
	pNode p=(pNode)malloc(sizeof(Node));
	if(NULL == p){
		printf("动态内存分配失败！");
		exit(-1);
	}
	pStk->pBottom=p;
	pStk->pTop=p;
	pStk->pBottom->pNext=NULL;
	/*
	printf("请输入初始化栈的结点个数：\n");
	scanf("%d",&length);
	for(i=0;i<length;++i){
		pNode q=(pNode)malloc(sizeof(Node));
		if(NULL == q){
				printf("动态内存分配失败！");
				exit(-1);
			}
		printf("请输入第%d个结点的值：\n",(i+1));
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
		printf("动态内存分配失败！");
		exit(-1);
	}
	else
	{
		p->data=val;
		//pStk->pTop->pNext=p;  ！！！！！严重错误，出栈操作很麻烦，开销很大
		p->pNext=pStk->pTop;
		pStk->pTop=p;
	}
}

void traverseStack(pStack pStk){
	if(isEmptyStack(pStk))
	{
		printf("无需遍历！");
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
		printf("出栈失败！");
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
		printf("此栈为空！");
		return true;
	}
	else{
		printf("此栈不空！\n");
		return false;
	}
}

void clearStack(pStack pStk){
	if(isEmptyStack(pStk)){
		printf("空栈无需清空");
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
		pStk->pTop=pStk->pBottom;   //一定不能少，不然清空后遍历出现死循环
	}
}

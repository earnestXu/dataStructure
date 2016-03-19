/*
 * Cdata.c
 *	静态循环队列的实现和操作算法【数组实现】
 *  Created on: 2016年3月19日
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//结构定义
typedef struct queue{
	int * pBase;
	int front;
	int rear;
}Queue,*pQueue;

//函数声明
void initQueue(pQueue pQ);
bool enterQueue(pQueue pQ, int val);
void traverseQueue(pQueue pQ);
bool isFullQueue(pQueue pQ);
bool exitQueue(pQueue pQ, int * pVal);
bool isEmptyQueue(pQueue pQ);


int main(){
	Queue q;
	int m;
	initQueue(&q);
	//isFullQueue(&q);
	enterQueue(&q,3);
	enterQueue(&q,4);
	enterQueue(&q,5);
	enterQueue(&q,6);
	enterQueue(&q,7);
	enterQueue(&q,8);
	enterQueue(&q,9);
	traverseQueue(&q);
	isFullQueue(&q);
	exitQueue(&q,&m);
	printf("出队元素是：%d\n",m);
	traverseQueue(&q);

	return 0;
}

void initQueue(pQueue  pQ){
	pQ->pBase=(int *)malloc(sizeof(int)*6);
	if(NULL == pQ->pBase){
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pQ->front=0;
	pQ->rear=0;
}

bool enterQueue(pQueue pQ, int val){
	if(isFullQueue(pQ)){
		printf("入队失败\n");
		return false;
	}else{
		pQ->pBase[pQ->rear]=val;
		//++pQ->rear;错误！
		pQ->rear=((pQ->rear+1)%6);
		printf("入队成功！\n");
		return true;
	}
}


void traverseQueue(pQueue pQ){
	int i=pQ->front;
	while((i%6) != pQ->rear){
		printf("%d\n",pQ->pBase[i]);
		i=((i+1)%6);
	}
}


bool isFullQueue(pQueue pQ){
	if(((pQ->rear+1)%6)==pQ->front){
		printf("队列已满！\n");
		return true;
	}
	else{
		printf("队列不满！\n");
		return false;
	}
}

bool exitQueue(pQueue pQ, int * pVal){
	if(isEmptyQueue(pQ)){
		printf("出队失败!\n");
		return false;
	}
	else{
		*pVal=pQ->pBase[pQ->front];
		pQ->front=((pQ->front+1)%6);
		return true;
	}

}

bool isEmptyQueue(pQueue pQ){
	if(pQ->front == pQ->rear){
		printf("队列为空！\n");
		return true;
	}
	else{
		printf("队列不空！\n");
		return false;
	}
}

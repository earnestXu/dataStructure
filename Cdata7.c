/*
 * Cdata.c
 *	��̬ѭ�����е�ʵ�ֺͲ����㷨������ʵ�֡�
 *  Created on: 2016��3��19��
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//�ṹ����
typedef struct queue{
	int * pBase;
	int front;
	int rear;
}Queue,*pQueue;

//��������
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
	printf("����Ԫ���ǣ�%d\n",m);
	traverseQueue(&q);

	return 0;
}

void initQueue(pQueue  pQ){
	pQ->pBase=(int *)malloc(sizeof(int)*6);
	if(NULL == pQ->pBase){
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	pQ->front=0;
	pQ->rear=0;
}

bool enterQueue(pQueue pQ, int val){
	if(isFullQueue(pQ)){
		printf("���ʧ��\n");
		return false;
	}else{
		pQ->pBase[pQ->rear]=val;
		//++pQ->rear;����
		pQ->rear=((pQ->rear+1)%6);
		printf("��ӳɹ���\n");
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
		printf("����������\n");
		return true;
	}
	else{
		printf("���в�����\n");
		return false;
	}
}

bool exitQueue(pQueue pQ, int * pVal){
	if(isEmptyQueue(pQ)){
		printf("����ʧ��!\n");
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
		printf("����Ϊ�գ�\n");
		return true;
	}
	else{
		printf("���в��գ�\n");
		return false;
	}
}

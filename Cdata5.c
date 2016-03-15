/*
 * Cdata5.c
 *	��ѭ���������ʵ�ּ��㷨
 *  Created on: 2016��3��15��
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct node{			//��������ṹ��
	int data;
	struct node * pNext;
}Node, *pNode;


//��������
pNode initList();			//��������
void traverseList(pNode pHead);// ��������
bool insertList(pNode pHead, int pos, int val);		//�ڵ�pos�����ǰ����val
void getElemList(pNode pHead, int pos,int * pVal);	//��ȡ��pos������ֵ
int locateElemList(pNode pHead, int val);		//��ȡ��һ����С����val�Ľ���λ��
bool isEmptyList(pNode pHead);			//�жϵ������Ƿ�Ϊ�գ����������������
int lengthList(pNode pHead);		//������ĳ���
void deleteElemList(pNode pHead,int pos, int * pVal);		//ɾ�������еĵ�pos����㣬������ֵ
void sortList(pNode pHead);			//��������ð�ݷ���



int main(void){
	int m;
	pNode pHead=NULL;
	pHead=initList();
	/*
	deleteElemList(pHead,3,&m);
	printf("%d\n",m);
	*/
	sortList(pHead);
	traverseList(pHead);
	/*
	m=lengthList(pHead);
	printf("����Ϊ��%d",m);
	*/
	/*
	if((isEmptyList(pHead)))
	{
		printf("true");
	}
	*/
	//m=locateElemList(pHead,1);
	//getElemList(pHead,8,&m);
	//printf("��ȡ��λ�ã�%d\n",m);
	//traverseList(pHead);
	//insertList(pHead,6,99);
	//traverseList(pHead);
	return 0;
}


pNode initList(){		//ͨ���������봴������
	int length,i;
	int val;	//��ʱ����û����������ֵ
	printf("��������Ҫ����������ĳ��ȣ�\n");
	scanf("%d",&length);			//һֱ���������scanf("%d\n",&x)
	pNode pHead = (pNode)malloc(sizeof(Node));
	if(NULL == pHead){
		printf("��̬�ڴ����ʧ�ܣ�1\n");
		exit(-1);
	}
	pHead->pNext=NULL;
	pNode q = pHead;

	for(i=0;i < length;++i)
	{

		printf("�������%d����ֵ��\n",(i+1));
		scanf("%d", &val);
		pNode p = (pNode)malloc(sizeof(Node));
		if(NULL == p)
		{
			printf("��̬�ڴ����ʧ�ܣ�2\n");
			exit(-1);
		}
		p->data = val;
		p->pNext=NULL;
		q->pNext=p;
		q=p;
	}
	return pHead;
}

void traverseList(pNode pHead){			//��������
	pNode p = pHead;
	while(p->pNext != NULL){
		printf("%d\n",(p->pNext->data));
		p=p->pNext;
	}
}

bool insertList(pNode pHead, int pos, int val){			//�ڵ�����ĵ�posλǰ����Ԫ��val
	pNode p=pHead->pNext;
	pNode r;
	pNode q=(pNode)malloc(sizeof(Node));
	q->data=val;
	q->pNext=NULL;
	int i=0;
	while(p != NULL)
	{
		++i;
		if(i == pos-1)
		{
			break;
		}
		p=p->pNext;
	}
	if(i != (pos-1))
		{
			printf("����λ�÷Ƿ�������ʧ�ܣ�\n");
			return false;
		}
	else
	{
		r=p->pNext;
		p->pNext=q;
		q->pNext=r;
		printf("����ɹ���\n");
		return true;
	}

	//return true;
}

void getElemList(pNode pHead,int pos, int * pVal){		//��ȡ�����е�pos������ֵ
	pNode p=pHead->pNext;
	int i=0;
	while(p != NULL)
	{
		++i;
		if(i == pos)
		{
			break;
		}
		p=p->pNext;
	}

	if(i != pos)
	{
		printf("��ȡԪ�ص�λ�÷Ƿ���getʧ�ܣ�");
	}
	else
	{
		*pVal=p->data;
	}
	return;
}

int locateElemList(pNode pHead, int val){		//��λԪ���������е�λ��
	pNode p = pHead->pNext;
	int i=0;
	while(p != NULL)
	{
		i++;
		if(p->data == val)
		{
			printf("���ڵ�%d\n",i);
			//break;
			return i;
		}

		p=p->pNext;
	}
	return 0;
}

bool isEmptyList(pNode pHead){				//�ж������Ƿ�Ϊ��
	if(pHead->pNext ==  NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int lengthList(pNode pHead){			//������ĳ���
	pNode p=pHead->pNext;
	int i=0;
	while(p != NULL){
		++i;
		p=p->pNext;
	}
	return i;
}

void deleteElemList(pNode pHead,int pos, int * pVal){		//ɾ�������е�pos����㣬������ֵ
	int i=0;
	pNode p=pHead;
	while(p->pNext != NULL){
		++i;
		if(i==pos){
			*pVal=p->pNext->data;
			p->pNext=p->pNext->pNext;
			break;
		}
		p=p->pNext;
	}
	return;
}

void sortList(pNode pHead){			//��������ð�ݷ���
	pNode p ,q;
	int len=lengthList(pHead);
	int i=0,j=0,r;
	for(i=0,p= pHead->pNext;i<len;++i,p=p->pNext){
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext){
			if(p->data >q->data){
				r=p->data;
				p->data=q->data;
				q->data=r;
			}
		}
	}

}

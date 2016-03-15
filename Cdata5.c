/*
 * Cdata5.c
 *	非循环单链表的实现及算法
 *  Created on: 2016年3月15日
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct node{			//单链表结点结构体
	int data;
	struct node * pNext;
}Node, *pNode;


//函数声明
pNode initList();			//创建链表
void traverseList(pNode pHead);// 遍历链表
bool insertList(pNode pHead, int pos, int val);		//在第pos个结点前插入val
void getElemList(pNode pHead, int pos,int * pVal);	//获取第pos个结点的值
int locateElemList(pNode pHead, int val);		//获取第一个大小等于val的结点的位置
bool isEmptyList(pNode pHead);			//判断单链表是否为空，链表不存在满的情况
int lengthList(pNode pHead);		//求链表的长度
void deleteElemList(pNode pHead,int pos, int * pVal);		//删除链表中的第pos个结点，并返回值
void sortList(pNode pHead);			//链表排序（冒泡法）



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
	printf("长度为：%d",m);
	*/
	/*
	if((isEmptyList(pHead)))
	{
		printf("true");
	}
	*/
	//m=locateElemList(pHead,1);
	//getElemList(pHead,8,&m);
	//printf("获取的位置：%d\n",m);
	//traverseList(pHead);
	//insertList(pHead,6,99);
	//traverseList(pHead);
	return 0;
}


pNode initList(){		//通过键盘输入创建链表
	int length,i;
	int val;	//临时存放用户输入结点的数值
	printf("请输入需要创建的链表的长度：\n");
	scanf("%d",&length);			//一直放这个错误！scanf("%d\n",&x)
	pNode pHead = (pNode)malloc(sizeof(Node));
	if(NULL == pHead){
		printf("动态内存分配失败！1\n");
		exit(-1);
	}
	pHead->pNext=NULL;
	pNode q = pHead;

	for(i=0;i < length;++i)
	{

		printf("请输入第%d结点的值：\n",(i+1));
		scanf("%d", &val);
		pNode p = (pNode)malloc(sizeof(Node));
		if(NULL == p)
		{
			printf("动态内存分配失败！2\n");
			exit(-1);
		}
		p->data = val;
		p->pNext=NULL;
		q->pNext=p;
		q=p;
	}
	return pHead;
}

void traverseList(pNode pHead){			//遍历链表
	pNode p = pHead;
	while(p->pNext != NULL){
		printf("%d\n",(p->pNext->data));
		p=p->pNext;
	}
}

bool insertList(pNode pHead, int pos, int val){			//在单链表的第pos位前插入元素val
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
			printf("插入位置非法，插入失败！\n");
			return false;
		}
	else
	{
		r=p->pNext;
		p->pNext=q;
		q->pNext=r;
		printf("插入成功！\n");
		return true;
	}

	//return true;
}

void getElemList(pNode pHead,int pos, int * pVal){		//获取链表中第pos个结点的值
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
		printf("获取元素的位置非法，get失败！");
	}
	else
	{
		*pVal=p->data;
	}
	return;
}

int locateElemList(pNode pHead, int val){		//定位元素在链表中的位置
	pNode p = pHead->pNext;
	int i=0;
	while(p != NULL)
	{
		i++;
		if(p->data == val)
		{
			printf("现在的%d\n",i);
			//break;
			return i;
		}

		p=p->pNext;
	}
	return 0;
}

bool isEmptyList(pNode pHead){				//判断链表是否为空
	if(pHead->pNext ==  NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int lengthList(pNode pHead){			//求链表的长度
	pNode p=pHead->pNext;
	int i=0;
	while(p != NULL){
		++i;
		p=p->pNext;
	}
	return i;
}

void deleteElemList(pNode pHead,int pos, int * pVal){		//删除链表中第pos个结点，并返回值
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

void sortList(pNode pHead){			//链表排序（冒泡法）
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

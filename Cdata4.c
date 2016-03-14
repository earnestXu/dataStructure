/*
 * Cdata4.c
 * 线性表——数组
 *  Created on: 2016年3月14日
 *      Author: Earnest
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Arr{
	int * pBase;    //数组的首地址
	int len;		//数组的长度
	int cnt;		//数组当前的实际个数
};

void initArr(struct Arr * pArr, int length);
bool appdentArr(struct Arr * pArr, int val);
bool insertArr(struct Arr * pArr, int pos, int val);//pos 为元素逻辑位置，非数组下表
bool deleteArr(struct Arr * pArr, int pos, int * pVal);
//int get();  没有必要写
bool isEmpty(struct Arr * pArr);
bool isFull(struct Arr * pArr);
void sortArr(struct Arr * pArr);
bool inverseArr(struct Arr * pArr);
void showArr(struct Arr * pArr);


int main(void){
	struct Arr array;
	//int val;

	initArr(&array, 6);

	appdentArr(&array,3);
	appdentArr(&array,4);
	appdentArr(&array,5);
	appdentArr(&array,1);
	appdentArr(&array,2);


	showArr(&array);
	//appdentArr(&array,6);
	//appdentArr(&array,7);
	//insertArr(&array,0,9);
	//deleteArr(&array,3,&val);
	//inverseArr(&array);
	sortArr(&array);
	showArr(&array);
	//printf("%d\n",val);
	//printf("%d",array.len);

	return 0;
}


void initArr(struct Arr * pArr, int length){		//初始化数组
	pArr->pBase=(int *)malloc(sizeof(int) * length);
	if(NULL == pArr->pBase){
		printf("动态内存分配失败，程序终止！\n");
		exit(-1);
	}
	else{
		printf("动态内存分配成功\n");
		pArr->cnt = 0;
		pArr->len = length;
	}
	return;
}

void showArr(struct Arr * pArr){		//显示数组内容
	if(isEmpty(pArr)){
		printf("数组为空，无输出！\n");
		//exit(0);
	}
	else{
		int i;
		for( i = 0;i < pArr->len; ++i){
			printf("%d\t",*(pArr->pBase+i));
		}
		printf("\n");
	}
	return;
}

bool isEmpty(struct Arr * pArr){		//判断数组是否为空，参数：数组首地址
	if(pArr->cnt == 0){
		return true;
	}
	else{
		return false;
	}
}

bool isFull(struct Arr * pArr){
	if(pArr->cnt >= pArr->len){
		return true;
	}
	else{
		return false;
	}
}

bool appdentArr(struct Arr * pArr, int val){
	if(isFull(pArr)){
		printf("数组已满，无法继续追加,追加失败！\n");
		return false;
	}
	else{
		pArr->pBase[pArr->cnt] = val;
		++(pArr->cnt);
		return true;
	}

}

bool insertArr(struct Arr * pArr, int pos, int val)
{
	if((pos>pArr->cnt+1) || (pos <= 0))
	{
		printf("插入位置非法，插入失败！\n");
		return false;
	}
	else{
			if(isFull(pArr))
			{
				printf("数组已满，无法插入，插入失败！\n");
				return false;
			}
			else{
				int i;
				for(i=(pArr->cnt)-1; i>= pos-1; --i){
					pArr->pBase[i+1]=pArr->pBase[i];
				}
				pArr->pBase[pos-1] = val;
				++pArr->cnt;
				return true;
				}
		}
}

bool deleteArr(struct Arr * pArr, int pos, int * pVal){
	if(isEmpty(pArr))
	{
		printf("数组为空，删除失败！\n");
		return false;
	}
	else
	{
		if((pos<1) || (pos>pArr->cnt))
		{
			printf("删除元素位置不合法，删除失败\n");
			return false;
		}
		else
		{
			*pVal=pArr->pBase[pos-1];
			int i;
			for(i=pos-1; i<pArr->cnt;++i)
			{
				pArr->pBase[i]=pArr->pBase[i+1];
			}
			--pArr->cnt;
			return true;
		}
	}
}

bool inverseArr(struct Arr * pArr){
	if(isEmpty(pArr))
	{
		printf("数组为空，倒置数组失败！");
		return false;
	}
	else
	{
		int i,j;
		for(i=1;i<=(int)(pArr->cnt/2);++i)
		{
			j=pArr->pBase[i-1];
			pArr->pBase[i-1]=pArr->pBase[pArr->cnt-i];
			pArr->pBase[pArr->cnt-i]=j;
		}
		return true;
	}
}

void sortArr(struct Arr * pArr){
	if(isEmpty(pArr))
	{
		printf("数组为空，无需排序！");
	}
	else
	{
		int i,j,k;
		for(i=0;i<pArr->cnt;++i)
		{
			for(j=i+1;j<pArr->cnt;++j)
			{
				if(pArr->pBase[i]>pArr->pBase[j])
				{
					k=pArr->pBase[i];
					pArr->pBase[i]=pArr->pBase[j];
					pArr->pBase[j]=k;
				}
			}
		}
	}
}

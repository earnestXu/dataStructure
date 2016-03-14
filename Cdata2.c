/*
 * Cdata2.c
 *malloc 动态内存分配
 *  Created on: 2016年3月13日
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>

int main(void){
	int len,i;
	printf("请输入需要动态分配数字的长度：");
	scanf("%d",&len);
	int * pArr = (int *)malloc( sizeof(int) * len);
	//*pArr=3;
	//*(pArr+2)=6;
	//printf("%d\n",*pArr);
	for(i=0;i<len;i++){
		*(pArr+i)=i;
		printf("%d\n",*(pArr+i));
		}
	free(pArr);
	return 0;
}

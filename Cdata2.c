/*
 * Cdata2.c
 *malloc ��̬�ڴ����
 *  Created on: 2016��3��13��
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>

int main(void){
	int len,i;
	printf("��������Ҫ��̬�������ֵĳ��ȣ�");
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

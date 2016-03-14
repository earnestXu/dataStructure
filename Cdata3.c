/*
 * Cdata3.c
 *跨函数使用内存
 *  Created on: 2016年3月13日
 *      Author: Earnest
 */
#include <stdio.h>
#include <malloc.h>

struct Student{
	int age;
	int sid;
};

struct Student * CreateStudent();
void PrintStudent(struct Student * ps);

int main(void){
	struct Student * pst;
	pst=CreateStudent();
	PrintStudent(pst);
	printf("跨函数使用内存成功！");
	return 0;
}

struct Student * CreateStudent(){
	struct Student * pst;
	pst=(struct Student *)malloc(sizeof(struct Student));
	pst->age=18;
	pst->sid=1002;
	return pst;
}

void PrintStudent(struct Student * ps){
	printf("%d\n%d\n",ps->age,ps->sid);

}

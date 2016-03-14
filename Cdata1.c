/*
 * Cdata1.c
 *
 *  Created on: 2016Äê3ÔÂ12ÈÕ
 *      Author: Earnest
 */
#include <stdio.h>
#include <string.h>

struct Student{
	int sid;
	char name[50];
	int age;
};
int main(void){
	//struct Student std={1002,"Xuping",22};
	struct Student std;
	struct Student * pstd;
	pstd = &std;

	pstd->age=23;
	strcpy(pstd->name,"earnest");
	pstd->sid=1005;
	//printf("%d\n%s\n%d",std.sid,std.name,std.age);
	//struct Student *pstd;
	//pstd->sid=1003;
	//pstd->name="earnet";  //error
	//strcpy(pstd->name,"earbest");
	//strcpy(std.name,"xuping1");
	//pstd->age=22;
	printf("%d\n%s\n%d",pstd->sid,pstd->name,pstd->age);
	return 0;
}


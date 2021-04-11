#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct _empInfo {
	int empNum;
	int age;
}EmpInfo;

int main(void) {
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	printf("사번과 나의 입력:");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("확인하고픈 직원의 사번 입력:");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("사번:%d 나이:%d", ei.empNum, ei.age);

	return 0;
}
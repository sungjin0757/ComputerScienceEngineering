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

	printf("����� ���� �Է�:");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("Ȯ���ϰ��� ������ ��� �Է�:");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("���:%d ����:%d", ei.empNum, ei.age);

	return 0;
}
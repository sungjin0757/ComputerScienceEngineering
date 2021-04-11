#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"person.h"
#include<stdlib.h>
#include<string.h>

int GetSSN(Person* p) {
	return p->ssn;
}
void showPerInfo(Person* p) {
	printf("주민등록번호:%d\n", p->ssn);
	printf("이름:%s\n", p->name);
	printf("주소:%s\n", p->addr);
}
Person* MakePersonData(int ssn, char* name, char* addr) {
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}
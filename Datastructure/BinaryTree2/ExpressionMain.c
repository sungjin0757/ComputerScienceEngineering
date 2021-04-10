#include<stdio.h>
#include"ExpressionTree.h"

int main(void) {
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("���� ǥ��:");
	showPrefixTypeExp(eTree);
	printf("\n");
	printf("���� ǥ��:");
	showInfixTypeExp(eTree);
	printf("\n");
	printf("���� ǥ��:");
	showPostfixTypeExp(eTree);
	printf("\n");
	printf("���:%d\n", EvaluateExpTree(eTree));
}
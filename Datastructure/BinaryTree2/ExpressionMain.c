#include<stdio.h>
#include"ExpressionTree.h"

int main(void) {
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("전위 표기:");
	showPrefixTypeExp(eTree);
	printf("\n");
	printf("중위 표기:");
	showInfixTypeExp(eTree);
	printf("\n");
	printf("후위 표기:");
	showPostfixTypeExp(eTree);
	printf("\n");
	printf("계산:%d\n", EvaluateExpTree(eTree));
}
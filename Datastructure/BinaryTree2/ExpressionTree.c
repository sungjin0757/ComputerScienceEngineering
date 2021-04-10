#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"BinaryTree2.h"
#include"ExpressionTree.h"
#include"ListBaseStack.h"

BTreeNode* MakeExpTree(char exp[]) {
	Stack stack;
	BTreeNode* pnode;
	StackInit(&stack);

	int explen = strlen(exp);
	int i;

	for (i = 0; i < explen; i++) {
		pnode = MakeBTreeNode();
		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');
		else {
			
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack,pnode);
	}
	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightsubTree(bt) == NULL)
		return GetData(bt);
	op1 = EvaluateExpTree(bt->left);
	op2 = EvaluateExpTree(bt->right);
	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	
	}
}
void show(int data)
{
	if (data >= 0 && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
void showPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, show);
}
void showInfixTypeExp(BTreeNode* bt) {
	if (bt == NULL)
		return;
	

	if (bt->left != NULL || bt->right != NULL)
		printf("(");
	showInfixTypeExp(bt->left);
	if (bt->data >= 0 && bt->data <= 9)
		printf("%d ", bt->data);
	else
		printf("%c ", bt->data);
	showInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");
}
void showPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, show);
}
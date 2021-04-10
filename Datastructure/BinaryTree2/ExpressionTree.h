#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include"BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);

void showPrefixTypeExp(BTreeNode* bt);
void showInfixTypeExp(BTreeNode* bt);
void showPostfixTypeExp(BTreeNode* bt);
#endif
#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"


BTreeNode* MakeBTreeNode(void) {
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->left = NULL;
	node->right = NULL;
}
BTData GetData(BTreeNode* bt) {
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}
BTreeNode* GetRightsubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}
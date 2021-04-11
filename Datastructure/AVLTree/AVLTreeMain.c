#include<stdio.h>
#include"AVLRebalance.h"
#include"BinarySearchTree3.h"
#include"BinaryTree2.h"

int main(void) {
	BTreeNode* avlRoot;
	BTreeNode* clNode;
	BTreeNode* crNode;
	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	printf("루트 노드:%d\n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightsubTree(avlRoot);
	printf("왼쪽:%d 오른쪽:%d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightsubTree(crNode);
	printf("왼쪽:%d 오른쪽:%d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightsubTree(crNode);
	printf("왼쪽:%d 오른쪽:%d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightsubTree(crNode);
	printf("왼쪽:%d 오른쪽:%d\n", GetData(clNode), GetData(crNode));

	return 0;
}
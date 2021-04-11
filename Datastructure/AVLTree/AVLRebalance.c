#include<stdio.h>
#include<stdlib.h>
#include"AVLRebalance.h"
#include"BinarySearchTree3.h"
#include"BinaryTree2.h"

int GetHeight(BTreeNode* bst) {
	int left;
	int right;

	if (bst == NULL)
		return 0;
	left = GetHeight(GetLeftSubTree(bst));
	right = GetHeight(GetRightsubTree(bst));

	if (right<left)
		return left + 1;
	else
		return right + 1;
	
}
int GetHeightDiff(BTreeNode* bst) {
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightsubTree(bst));

	return lsh - rsh;
}
BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightsubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}
BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightsubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}
BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	RotateRR(cNode);
	ChangeLeftSubTree(pNode, cNode);
	RotateLL(pNode);

	return pNode;
}
BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightsubTree(pNode);

	RotateLL(cNode);
	ChangeRightSubTree(pNode, cNode);
	RotateRR(pNode);

	return pNode;
}
BTreeNode* Rebalance(BTreeNode** proot) {
	int high = GetHeightDiff(*proot);

	if (high > 1) {
		if (GetHeightDiff(GetLeftSubTree(*proot)) > 0)
			*proot = RotateLL(*proot);
		else
			*proot = RotateLR(*proot);
	}
	if (high < -1) {
		if (GetHeightDiff(GetRightsubTree(*proot)) < 0)
			*proot = RotateRR(*proot);
		else
			*proot = RotateRL(*proot);
	}
	return *proot;
}


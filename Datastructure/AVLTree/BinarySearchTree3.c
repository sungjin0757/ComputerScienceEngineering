#include<stdio.h>
#include<stdlib.h>
#include"BinarySearchTree3.h"
#include"BinaryTree2.h"
#include"AVLRebalance.h"

void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;
		pNode = cNode;
		if (GetData(cNode) < data)
			cNode = GetRightsubTree(cNode);
		else
			cNode = GetLeftSubTree(cNode);
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if (pNode != NULL) {
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else {
		*pRoot = nNode;
	}
	*pRoot=Rebalance(pRoot);
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* sNode = bst;
	BSTData cd;

	while (sNode != NULL)
	{
		cd = GetData(sNode);

		if (cd == target)
			return sNode;
		else if (cd > target)
			sNode = GetLeftSubTree(sNode);
		else
			sNode = GetRightsubTree(sNode);
	}
	return NULL;
}
BTreeNode* BSTRemove(BTreeNode** proot, BSTData target) {
	BTreeNode* pVroot = MakeBTreeNode();
	BTreeNode* pNode = pVroot;
	BTreeNode* cNode = *proot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVroot, *proot);
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightsubTree(cNode);
	}
	if (cNode == NULL)
		return;

	dNode = cNode;
	if (GetRightsubTree(dNode) == NULL && GetLeftSubTree(cNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(dNode);
		else
			RemoveRightSubTree(dNode);
	}
	else if (GetRightsubTree(dNode) == NULL || GetLeftSubTree(cNode) == NULL) {
		BTreeNode* dcNode;
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightsubTree(dNode);
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else {
		BTreeNode* mNode = GetRightsubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightsubTree(mNode));
		else
			ChangeLeftSubTree(mpNode, GetRightsubTree(mNode));
	}
	if (GetLeftSubTree(pVroot) != *proot)
		*proot = GetRightsubTree(pVroot);

	free(pVroot);
	*proot=Rebalance(proot);
	return dNode;
}

void ShowInData(int data) {
	printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowInData);
}
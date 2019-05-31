#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"


int GetBinTreeSize(BTNode* pRoot) {
	if (pRoot == NULL)
		return 0;
	return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;
}

int GetKLevelNodeCount(BTNode* pRoot, int K) {
	if (pRoot == NULL||K<=0)
		return 0;
	if (K == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);

}

int GetLeafCount(BTNode* pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}
int GetBinTreeHeight(BTNode* pRoot) {
	if (pRoot == NULL)
		return 0;
	int maxleft = GetBinTreeHeight(pRoot->_pLeft);
	int maxright = GetBinTreeHeight(pRoot->_pRight);
	if (maxleft > maxright)
		return 1 + maxleft;
	return 1 + maxright;
}

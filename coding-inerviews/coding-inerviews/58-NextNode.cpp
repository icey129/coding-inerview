#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL){
		return NULL;
	}
	TreeLinkNode* pRes = NULL;
	if (pNode->right){
		TreeLinkNode* tNode = pNode->right;
		while (tNode->left){
			tNode = tNode->left;
		}
		pRes = tNode;
	}
	else{ //没有右孩子节点
		TreeLinkNode* tNode = pNode;
		while(tNode->next && tNode == tNode->next->right){  //该节点在对应父节点的右子树继续向上找
			tNode = tNode->next;
		}
		if (tNode->next == NULL){ //到达根节点
			return NULL;
		}
		else{
			pRes = tNode->next;
		}
	}
	return pRes;
}
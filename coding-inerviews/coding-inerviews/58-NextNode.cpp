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
	else{ //û���Һ��ӽڵ�
		TreeLinkNode* tNode = pNode;
		while(tNode->next && tNode == tNode->next->right){  //�ýڵ��ڶ�Ӧ���ڵ������������������
			tNode = tNode->next;
		}
		if (tNode->next == NULL){ //������ڵ�
			return NULL;
		}
		else{
			pRes = tNode->next;
		}
	}
	return pRes;
}
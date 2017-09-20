#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode* pNode1, TreeNode* pNode2);

bool isSymmetrical(TreeNode* pRoot){
	if (pRoot == NULL){
		return true;
	}
	bool res = isSame(pRoot->left, pRoot->right);
	return res;
}
bool isSame(TreeNode* pNode1, TreeNode* pNode2){
	if (pNode1 == NULL && pNode2 == NULL){
		return true;
	}
	else if (pNode1 == NULL || pNode2 == NULL || pNode1->val != pNode2->val){
		return false;
	}
	bool res = true;
	res &= isSame(pNode1->left, pNode2->right);
	res &= isSame(pNode1->right, pNode2->left);
	return res;
}
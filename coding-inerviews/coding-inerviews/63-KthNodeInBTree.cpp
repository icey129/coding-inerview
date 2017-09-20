#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

TreeNode* getKthNode(TreeNode* pRoot, int *k)
{
	if (pRoot == NULL){
		return NULL;
	}
	if (*k == 0){
		return pRoot;
	}
	TreeNode* res = NULL;
	if (pRoot->left)
		res = getKthNode(pRoot->left, k);
	*k -= 1;
	if (*k == 0){
		return pRoot;
	}
	if (!res && pRoot->right){
		res = getKthNode(pRoot->right, k);
	}
	return res;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == NULL){
		return NULL;
	}
	return getKthNode(pRoot, &k);
}
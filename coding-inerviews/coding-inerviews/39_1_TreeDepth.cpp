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

int TreeDepth(TreeNode* pRoot){
	if (pRoot == NULL){
		return 0;
	}
	int depth = 0;
	int left = 0;
	int right = 0;
	if (pRoot->left){
		left = TreeDepth(pRoot->left);
	}
	if (pRoot->right){
		right = TreeDepth(pRoot->right);
	}
	depth = left > right ? left : right;
	depth += 1;
	return depth;
}
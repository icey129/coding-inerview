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

bool searchTree(TreeNode* pNode, int* depth){
	if (!pNode){
		return true;
	}

	bool left_res = true, right_res = true;
	int left = *depth, right = *depth;
	if (pNode->left){
		left_res = searchTree(pNode->left, &left);
	}
	if (!left_res){
		return false;
	}
	if (pNode->right){
		right_res = searchTree(pNode->right, &right);
	}
	if (!right_res){
		return false;
	}
	if (left - right <= 1 && left - right >= -1){
		(*depth) += left > right ? left : right;
		(*depth) += 1;
		return true;
	}
	return false;
}

bool IsBalanced(TreeNode* pRoot){
	if (!pRoot){
		return true;
	}
	int depth = 0;
	return searchTree(pRoot, &depth);
}
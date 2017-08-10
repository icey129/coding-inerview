#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

// 递归实现
void Mirror(TreeNode *proot){
	if (proot == NULL){
		return;
	}
	if (proot->left == NULL && proot->right == NULL){//叶子节点
		return;
	}

	if (proot->left)
		Mirror(proot->left);
	if (proot->right)
		Mirror(proot->right);
	TreeNode * tmp = proot->left;
	proot->left = proot->right;
	proot->right = tmp;
	return;
}

// 循环实现
void Mirror_loop(TreeNode * pRoot){
	stack<TreeNode*> stk;
	TreeNode* tmp_node = NULL, *tmp = NULL;
	if (pRoot == NULL)
		return;
	if (pRoot->left == NULL && pRoot->right == NULL)
		return;
	stk.push(pRoot);

	while (!stk.empty()){
		tmp_node = stk.top();
		stk.pop();
		if (tmp_node->left == NULL && tmp_node->right == NULL){ //leaf node
			continue;
		}
		tmp = tmp_node->left;
		tmp_node->left = tmp_node->right;
		tmp_node->right = tmp;
		if (tmp_node->left){
			stk.push(tmp_node->left);
		}
		if (tmp_node->right){
			stk.push(tmp_node->right);
		}
	}
	return;
}
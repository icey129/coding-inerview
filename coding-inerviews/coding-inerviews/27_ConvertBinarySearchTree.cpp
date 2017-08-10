#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

TreeNode* convertLeft(TreeNode* root);
TreeNode* convertRight(TreeNode* root);

TreeNode* convertLeft(TreeNode* root){
	if (!root){
		return NULL;
	}
	TreeNode* pre = NULL, *last = root;
	if (root->left){
		pre = convertLeft(root->left);
		pre->right = root;
		root->left = pre;
	}
	if (root->right){
		last = convertRight(root->right);
		root->right = last;
		last->left = root;
	}
	return last;
}

TreeNode* convertRight(TreeNode* root){
	if (!root)
		return NULL;
	TreeNode* pre = root, *last = NULL;
	if (root->left){
		pre = convertLeft(root->left);
		pre->right = root;
		root->left = pre;
	}
	if (root->right){
		last = convertRight(root->right);
		root->right = last;
		last->left = root;
	}
	return pre;
}

TreeNode* convert(TreeNode* pRootOfTree){
	if (!pRootOfTree)
		return NULL;
	TreeNode* pre = NULL, *last = pRootOfTree, *res = pRootOfTree;
	if (pRootOfTree->left){
		pre = convertLeft(pRootOfTree->left);
		pre->right = pRootOfTree;
		pRootOfTree->left = pre;
	}
	if (pRootOfTree->right){
		last = convertRight(pRootOfTree->right);
		last->left = pRootOfTree;
		pRootOfTree->right = last;
	}
	while (res->left){
		res = res->left;
	}
	return res;
}

//方法二 参见剑指offer
void convertNode(TreeNode* root, TreeNode** lastNode){
	if (root == NULL){
		return;
	}
	if (root->left){
		convertNode(root->left, lastNode);
	}
	if (*lastNode){
		(*lastNode)->right = root;
	}
	root->left = (*lastNode);
	(*lastNode) = root;
	if (root->right)
		convertNode(root->right, lastNode);
	return;
}

TreeNode* convert1(TreeNode* pRootofTree){
	if (!pRootofTree)
		return NULL;
	TreeNode * lastNode = NULL;
	convertNode(pRootofTree, &lastNode);
	
	TreeNode* p = pRootofTree;
	while (p->left){
		p = p->left;
	}
	return p;
}

int convertBinarySearchTree(){
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(8);
	root->right = new TreeNode(12);
	TreeNode* p = root->left, *q = root->right;
	p->left = new TreeNode(5);
	p->right = new TreeNode(9);
	q->left = new TreeNode(11);
	q->right = new TreeNode(15);
	TreeNode* res = convert1(root);
	return 0;
}
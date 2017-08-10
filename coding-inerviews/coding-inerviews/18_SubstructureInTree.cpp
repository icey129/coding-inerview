#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

bool IsSubtree(TreeNode* pNode1, TreeNode* pNode2){
	if (pNode2 == NULL){
		return true;
	}
	else if (pNode1 == NULL){
		return false;
	}
	if (pNode1->val != pNode2->val){
		return false;
	}
	bool res = false;
	res = IsSubtree(pNode1->left, pNode2->left);
	if (res){
		res = IsSubtree(pNode1->right, pNode2->right);
	}	
	return res;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
	if (pRoot2 == NULL || pRoot1 == NULL){
		return false;
	}
	bool res = false;
	if (pRoot1->val == pRoot2->val)
		res = IsSubtree(pRoot1, pRoot2);
	if (!res){
		res = HasSubtree(pRoot1->left, pRoot2);
	}
	if (!res){
		res = HasSubtree(pRoot1->right, pRoot2);
	}
	return res;

}

int Judge_subtree(){
	TreeNode* pleft = NULL, *pright = NULL;
	TreeNode* head = new TreeNode(8);
	head->left = new TreeNode(8);
	head->right = new TreeNode(7);
	
	pleft = head->left;

	pleft->left = new TreeNode(9);
	pleft->right = new TreeNode(2);
	pright = pleft->right;

	pright->left = new TreeNode(4);
	pright->right = new TreeNode(7);

	TreeNode* subtree = new TreeNode(8);
	subtree->left = new TreeNode(9);
	subtree->right = new TreeNode(2);

	bool res = HasSubtree(head, subtree);
	cout << res << endl;

	return 0;
}
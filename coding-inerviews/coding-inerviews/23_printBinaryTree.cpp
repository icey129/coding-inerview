#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//Ñ­»·
vector<int> PrintFromTopToBottom(TreeNode* root){
	vector<int> res;
	if (root == NULL){
		return res;
	}
	queue<TreeNode*> qe;
	TreeNode *tmp = NULL;
	qe.push(root);
	while (!qe.empty()){
		tmp = qe.front();
		res.push_back(tmp->val);
		qe.pop();
		if (tmp->left)
			qe.push(tmp->left);
		if (tmp->right)
			qe.push(tmp->right);
	}
	return res;
}
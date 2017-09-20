#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<vector<int>> Z_Print(TreeNode* pRoot) {
	vector<vector<int>> res;
	if (pRoot == NULL){
		return res;
	}
	stack<TreeNode*> level[2];
	int cur = 0, next = 1;
	int num1 = 1, num2 = 0;
	level[cur].push(pRoot);
	vector<int> ll;
	while (!level[0].empty()||!level[1].empty()){
		TreeNode* node = level[cur].top();
		level[cur].pop();  //µ¯³ö
		ll.push_back(node->val);
		if (cur == 0){
			if (node->left)
				level[next].push(node->left);
			if (node->right)
				level[next].push(node->right);
		}
		else if (cur == 1){
			if (node->right)
				level[next].push(node->right);
			if (node->left)
				level[next].push(node->left);
		}

		if (level[cur].empty()){
			cur = 1 - cur;
			next = 1 - next;
			res.push_back(ll);
			ll.clear();
		}
	}
	return res;
}

int Zprint_test(){
	TreeNode* pleft = NULL, *pright = NULL;
	TreeNode* head = new TreeNode(8);
	head->left = new TreeNode(6);
	head->right = new TreeNode(10);

	pleft = head->left;

	pleft->left = new TreeNode(5);
	pleft->right = new TreeNode(7);
	pright = head->right;

	pright->left = new TreeNode(9);
	pright->right = new TreeNode(11);

	vector<vector<int>> res = Z_Print(head);
	return 0;
}
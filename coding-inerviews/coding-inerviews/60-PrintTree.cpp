#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<vector<int>> Print(TreeNode* pRoot){
	vector<vector<int>> res;
	if (pRoot == NULL){
		return res;
	}
	queue<TreeNode*> lst;
	lst.push(pRoot);
	vector<int> tmp;
	int cur = 1, next = 0;
	while (!lst.empty()){
		TreeNode* node = lst.front();
		tmp.push_back(node->val);
		lst.pop();
		cur -= 1;
		if (node->left){
			lst.push(node->left);
			next++;
		}
		if (node->right){
			lst.push(node->right);
			next++;
		}
		if (cur == 0){
			res.push_back(tmp);
			tmp.clear();
			cur = next;
			next = 0;
		}
	}
	return res;
}
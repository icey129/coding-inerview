#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

void getPath(TreeNode * root, int n, int sum, vector<int>& path, vector<vector<int>> & resPath){ //变量path使用引用与不使用引用的优势在哪？不使用path不需要pop，执行析构函数
	if (root == NULL){
		return;
	}
	sum += root->val;
	path.push_back(root->val);

	if (root->left == NULL && root->right == NULL){ //leaf node
		if (sum == n){
			resPath.push_back(path);
		}
	}

	if (root->left){
		getPath(root->left, n, sum, path, resPath);
	}
	if (root->right){
		getPath(root->right, n, sum, path, resPath);
	}
	path.pop_back();
	return;
}

vector<vector<int>> FindPath(TreeNode * root, int expectNumber){
	vector<vector<int>> res;
	if (root == NULL){
		return res;
	}
	vector<int> path;
	getPath(root, expectNumber, 0, path, res);
	return res;
}
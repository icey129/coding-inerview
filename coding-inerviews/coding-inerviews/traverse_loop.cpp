#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//使用非递归方式实现先序遍历，中序遍历，后序遍历
//http://blog.csdn.net/zhangxiangdavaid/article/details/37115355

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//先序遍历
vector<int> preorder_loop(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode* > stk;
	TreeNode* node = root;
	while (!stk.empty() || node){
		if (node){ //找到最左边的节点
			res.push_back(node->val);
			stk.push(node);
			node = node->left;
		}
		else{ //栈顶是没有输出的最左边的节点
			node = stk.top();
			stk.pop();
			node = node->right;
		}
	}
	return res;
}

vector<int> preorder_loop2(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode* > stk;
	TreeNode* node = root;
	stk.push(root);
	while (stk.empty()){
		res.push_back(node->val);
		if (node->right){
			stk.push(node->right);
		}
		if (node->left){
			node = node->left;
		}
		else{
			node = stk.top();
			stk.pop();
		}
	}
	return res;
}

//中序遍历
vector<int> inorder_loop(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* node = root;
	while (!stk.empty()|| node){
		if (node){ //插入节点
			stk.push(node);
			node = node->left;
		}
		else{  //当前节点节点为空，栈顶出栈，节点的右孩子节点继续迭代
			node = stk.top();
			stk.pop();
			res.push_back(node->val);
			node = node->right;
		}
	}
	return res;
}

//后续遍历
vector<int> postorder_loop1(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* pCur = root, *pre = NULL; //使用pre标记上一个出栈的节点，根据pre判断是否访问了右孩子节点
	while (!stk.empty() || pCur){
		while (pCur){
			stk.push(pCur);
			pCur = pCur->left;
		}
		pCur = stk.top();
		if (pCur->right == NULL || pre == pCur->right){ //右节点已经被访问或右节点为空
			pre = pCur;
			res.push_back(pCur->val);
			stk.pop();
			pCur = NULL;
		}
		else{ //含有右节点且右节点还未被访问
			pCur = pCur->right;
		}
	}
	return res;
}

typedef pair<TreeNode*, int> PAIR;

//使用一个标识位，标识是左孩子还是右孩子
vector<int> postorder_loop2(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<PAIR> stk;
	TreeNode* node = root;
	while (!stk.empty() || node){
		while (node){
			stk.push(make_pair(node, 0));
			node = node->left;
		}
		PAIR tnode = stk.top();
		stk.pop();
		if (tnode.second == 0){ // 未访问右孩子
			tnode.second = 1; 
			stk.push(tnode);  //如果不重新入栈对second的修改不会变
			node = tnode.first->right;
		}
		else{
			res.push_back((tnode.first)->val);
			node = NULL;
		}
	}
	return res;
}

void setNodeChild(TreeNode* node, int* left, int* right){
	if (left){
		node->left = new TreeNode(*left);
	}
	if (right){
		node->right = new TreeNode(*right);
	}
}

int traverse_loop_test(){
	TreeNode* root = new TreeNode(1);
	int left = 2, right = 3;
	setNodeChild(root, &left, &right);
	left = 4;
	right = 5;
	setNodeChild(root->left, &left, &right);
	right = 7;
	setNodeChild(root->right, NULL, &right);
	TreeNode *node = root->left;
	left = 6;
	right = 8;
	setNodeChild(node->right, &left, &right);

	vector<int> res;
	res = postorder_loop2(root);

	for (int i = 0; i < res.size(); i++){
		cout << res[i];
	}
	return 0;
}
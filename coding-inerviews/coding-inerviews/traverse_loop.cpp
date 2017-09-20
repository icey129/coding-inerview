#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//ʹ�÷ǵݹ鷽ʽʵ���������������������������
//http://blog.csdn.net/zhangxiangdavaid/article/details/37115355

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//�������
vector<int> preorder_loop(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode* > stk;
	TreeNode* node = root;
	while (!stk.empty() || node){
		if (node){ //�ҵ�����ߵĽڵ�
			res.push_back(node->val);
			stk.push(node);
			node = node->left;
		}
		else{ //ջ����û�����������ߵĽڵ�
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

//�������
vector<int> inorder_loop(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* node = root;
	while (!stk.empty()|| node){
		if (node){ //����ڵ�
			stk.push(node);
			node = node->left;
		}
		else{  //��ǰ�ڵ�ڵ�Ϊ�գ�ջ����ջ���ڵ���Һ��ӽڵ��������
			node = stk.top();
			stk.pop();
			res.push_back(node->val);
			node = node->right;
		}
	}
	return res;
}

//��������
vector<int> postorder_loop1(TreeNode* root){
	if (root == NULL){
		return vector<int>();
	}
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* pCur = root, *pre = NULL; //ʹ��pre�����һ����ջ�Ľڵ㣬����pre�ж��Ƿ�������Һ��ӽڵ�
	while (!stk.empty() || pCur){
		while (pCur){
			stk.push(pCur);
			pCur = pCur->left;
		}
		pCur = stk.top();
		if (pCur->right == NULL || pre == pCur->right){ //�ҽڵ��Ѿ������ʻ��ҽڵ�Ϊ��
			pre = pCur;
			res.push_back(pCur->val);
			stk.pop();
			pCur = NULL;
		}
		else{ //�����ҽڵ����ҽڵ㻹δ������
			pCur = pCur->right;
		}
	}
	return res;
}

typedef pair<TreeNode*, int> PAIR;

//ʹ��һ����ʶλ����ʶ�����ӻ����Һ���
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
		if (tnode.second == 0){ // δ�����Һ���
			tnode.second = 1; 
			stk.push(tnode);  //�����������ջ��second���޸Ĳ����
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
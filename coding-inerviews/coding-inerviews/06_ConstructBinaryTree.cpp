#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int i): val(i), left(NULL), right(NULL){}
};

TreeNode * ConstructorCode(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator vin_begin, vector<int>::iterator vin_end);
//迭代时变换vector<int>
TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin){
	if (pre.empty() || vin.empty()){
		return NULL;
	}
	int len_pre = pre.size(), len_in = pre.size();
	int i = 0;
	if (len_pre != len_in){
		return NULL;
	}
	TreeNode * inNode = new TreeNode(pre[0]);
	for (i = 0; i < len_in; i++){
		if (vin[i] == pre[0]){
			break;
		}
	}
	if (i == len_in){
		return NULL;
	}
	auto p_begin = pre.begin();
	auto p_end = pre.end() - 1;
	auto in_begin = vin.begin();
	auto in_end = vin.end() - 1;
	vector<int> l_pre(p_begin + 1, p_begin + i + 1);
	vector<int> l_in(in_begin, in_begin + i);
	vector<int> r_pre(p_begin + i + 1, p_end + 1);
	vector<int> r_in(in_begin + i + 1, in_end + 1);
	inNode->left = reConstructBinaryTree(l_pre, l_in);
	inNode->right = reConstructBinaryTree(r_pre, r_in);
	return inNode;
}

//不更改vector，变化index
TreeNode * reConstructBinaryTree1(const vector<int> pre, const vector<int> vin, pair<int, int> pre_index, pair<int, int> in_index){
	if (pre.empty() || vin.empty()){
		return NULL;
	}
	if (pre_index.first >= pre_index.second || in_index.first >= in_index.second){
		return NULL;
	}
	int num = pre[pre_index.first];
	TreeNode * node = new TreeNode(num);
	int i = 0, count = 0;
	for (i = in_index.first; i < in_index.second; i++){
		count += 1;
		if (vin[i] == num){
			break;
		}
	}
	if (i == in_index.second){
		return NULL;
	}
	pair<int, int> l_pre = make_pair(pre_index.first + 1, pre_index.first + count);
	pair<int, int> r_pre = make_pair(pre_index.first + count, pre_index.second);
	pair<int, int> l_in = make_pair(in_index.first, i);
	pair<int, int> r_in = make_pair(i + 1, in_index.second);

	node->left = reConstructBinaryTree1(pre, vin, l_pre, l_in);
	node->right = reConstructBinaryTree1(pre, vin, r_pre, r_in);
	return node;
}

//使用迭代器
TreeNode * reConstructBinaryTree2(vector<int> pre, vector<int> vin){
	if (pre.empty() || vin.empty() || pre.size() != vin.size()){
		return NULL;
	}
	vector<int>::iterator pre_begin = pre.begin();
	vector<int>::iterator pre_end = pre.end() - 1;
	vector<int>::iterator vin_begin = vin.begin();
	vector<int>::iterator vin_end = vin.end() - 1;
	return ConstructorCode(pre_begin, pre_end, vin_begin, vin_end);
}
// pre_end，指向pre数组的最后一个元素，不是尾后指针
TreeNode * ConstructorCode(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator vin_begin, vector<int>::iterator vin_end){
	TreeNode * node = new TreeNode(*pre_begin);
	if ((pre_end - pre_begin) != (vin_end- vin_begin)){
		return NULL;
	}
	if (pre_begin == pre_end && *pre_begin == * vin_begin){
		return node;
	}
	vector<int>::iterator i = vin_begin;
	for (i = vin_begin; i != vin_end + 1; i++){
		if (*i == *pre_begin){
			int len = i - vin_begin;
			if (len > 0)
				node->left = ConstructorCode(pre_begin + 1, pre_begin + len, vin_begin, i - 1);
			if (vin_end - i > 0)
				node->right = ConstructorCode(pre_begin + len + 1, pre_end, i + 1, vin_end);
			return node;
		}
	}
	return NULL;
}

int ConstructorBT(){
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode * root = reConstructBinaryTree2(pre, vin);
	return 0;
}
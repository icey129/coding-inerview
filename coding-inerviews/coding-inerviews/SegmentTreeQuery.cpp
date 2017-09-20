#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   用整数数组建立线段树，根节点所代表的区间为0-n-1, 
   每个节点有一个额外的属性max，值为该节点所代表的数组区间start到end内的最大值。
   为SegmentTree设计一个 query 的方法，接受3个参数root, start和end，线段树root所代表的数组中子区间[start, end]内的最大值。
*/

struct SegmentTreeNode{
	int start, end;
	int max;
	SegmentTreeNode* left, *right;
	SegmentTreeNode(int x, int y, int z = 0) : start(x), end(y), max(z), left(NULL), right(NULL){}
};

static bool inValid = false;

void traverseBuildTree(SegmentTreeNode* pNode, const vector<int>& arr, int start, int end){
	if (start == end){
		pNode->max = arr[start];
		return;
	}
	int left = (start + end) / 2, right = left + 1;
	pNode->left = new SegmentTreeNode(start, left);
	pNode->right = new SegmentTreeNode(right, end);
	traverseBuildTree(pNode->left, arr, start, left);
	traverseBuildTree(pNode->right, arr, right, end);
	pNode->max = std::max(pNode->left->max, pNode->right->max);
	return;
}

SegmentTreeNode* buildSegTree(const vector<int>& arr){
	if (arr.empty()){
		return NULL;
	}
	SegmentTreeNode* root = new SegmentTreeNode(0, arr.size()-1);
	traverseBuildTree(root, arr, 0, arr.size() - 1);
	return root;
}

void setMaxSegTree(SegmentTreeNode* root, const vector<int>& arr){
	if (root->start == root->end){
		root->max = arr[root->start];
		return;
	}
	else{
		int left, right;
		setMaxSegTree(root->left, arr);
		left = root->left->max;
		setMaxSegTree(root->right, arr);
		right = root->right->max;
		root->max = std::max(left, right);
	}
	return;
}

int querySegTree(SegmentTreeNode* root, int start, int end){
	if (root == NULL || start > end || start < root->start || end > root->end){
		inValid = true;
		return 0;
	}

	SegmentTreeNode* pNode = root;

	int maxval;
	if (start <= pNode->start && end >= pNode->end){
		maxval = pNode->max;
	}
	else{
		int left = pNode->left->end;
		int right = pNode->right->start;
		if (start > left){
			maxval = querySegTree(pNode->right, start, end);
		}
		else if (end < right){
			maxval = querySegTree(pNode->left, start, end);
		}
		else{
			maxval = querySegTree(pNode->left, start, left);
			maxval = std::max(maxval, querySegTree(root->right, right, end));
		}
	}
	return maxval;
}

int segQuery_1(){
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	SegmentTreeNode* root = buildSegTree(v);
	//setMaxSegTree(root, v);
	int start, end;
	cin >> start >> end;
	int res = querySegTree(root, start, end);
	if (!inValid){
		cout << res << endl;
	}
	return 0;
}
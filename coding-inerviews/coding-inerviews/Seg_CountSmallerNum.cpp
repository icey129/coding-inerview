#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//方法一：对有序(sort)的vector使用lower_bound()
// lower_bound()与upper_bound()使用的是二分查找
vector<int> countOfSmallerNumber1(vector<int> A, vector<int> queries) {
	// write your code here
	vector<int> res;
	sort(A.begin(), A.end());
	for (int x : queries){
		auto i = lower_bound(A.begin(), A.end(), x);
		if (i != A.end()){
			res.push_back(i - A.begin());
		}
		else{
			res.push_back(0);
		}
	}
	return res;
}

struct SegmentTreeNode{
	int start, end;
	int count;
	SegmentTreeNode* left, *right;
	SegmentTreeNode(int x, int y, int z = 0) : start(x), end(y), count(z), left(NULL), right(NULL){}
};

void BuildCountTree(SegmentTreeNode* pNode, int start, int end){
	if (pNode == NULL || start == end){
		return;
	}
	int left = (start + end) / 2;
	int right = left + 1;
	pNode->left = new SegmentTreeNode(start, left);
	pNode->right = new SegmentTreeNode(right, end);
	BuildCountTree(pNode->left, start, left);
	BuildCountTree(pNode->right, right, end);
	return;
}

SegmentTreeNode* BuildSegCountTree(int start, int end){
	if (start > end){
		return NULL;
	}
	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	BuildCountTree(root, start, end);
	return root;
}

void setSegCountTree(SegmentTreeNode* root, int n){
	if (n < root->start || n > root->end){
		return;
	}
	root->count += 1;
	if (n == root->start && n == root->end){
		return;
	}
	int left = root->left->end;
	int right = root->right->start;
	if (n <= left){
		setSegCountTree(root->left, n);
	}
	if (n >= right){
		setSegCountTree(root->right, n);
	}
	return;
}

int querySegCountTree(SegmentTreeNode* root, int n){
	if (n < root->start || n > root->end){
		return 0;
	}
	int cnt = 0;
	if (n == root->start && n == root->end){
		return 0;
	}
	int left = root->left->end;
	int right = root->right->start;
	if (n >= right){
		cnt += root->left->count;
		cnt += querySegCountTree(root->right, n);
	}
	else if(n <= left){
		cnt += querySegCountTree(root->left, n);
	}
	return cnt;
}

//方法二：使用segment tree
vector<int> countOfSmallerNumber2(vector<int> A, vector<int> queries) {
	SegmentTreeNode* root = BuildSegCountTree(0, 10000);
	vector<int> res;
	if (queries.empty()){
		return res;
	}
	for (int i = 0; i < A.size(); i++){
		setSegCountTree(root, A[i]);
	}
	for (int i = 0; i < queries.size(); i++){
		int tmp = querySegCountTree(root, queries[i]);
		res.push_back(tmp);
	}
	return res;
}

int countSmaller_test1(){
	int n, m;
	cin >> n >> m;
	vector<int> A(n);
	vector<int> Q(m);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	for (int i = 0; i < m; i++){
		cin >> Q[i];
	}
	vector<int> res;
	res = countOfSmallerNumber2(A, Q);
	for (int i = 0; i < m; i++){
		cout << res[i] << endl;
	}
	return 0;
}
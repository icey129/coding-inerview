#include <iostream>
using namespace std;
#include <vector>

/*
For an array, we can build a SegmentTree for it, each node stores an extra attribute count to denote the number of elements in the the array which value is between interval start and end. (The array may not fully filled by elements)
Design a query method with three parameters root, start and end, find the number of elements in the in array's interval [start, end] by the given root of value SegmentTree.
*/

struct SegmentTreeNode{
	int start, end;
	int count;
	SegmentTreeNode* left, *right;
	SegmentTreeNode(int x, int y, int z = 0) : start(x), end(y), count(z), left(NULL), right(NULL){}
};

void traverseBuildCTree(SegmentTreeNode* pNode, int start, int end){
	if (start == end){
		return;
	}
	int left = (start + end) / 2, right = left + 1;
	pNode->left = new SegmentTreeNode(start, left);
	pNode->right = new SegmentTreeNode(right, end);
	traverseBuildCTree(pNode->left,start, left);
	traverseBuildCTree(pNode->right, right, end);
	return;
}

SegmentTreeNode* buildCSegTree(int start, int end){
	if (start > end || start < 0){
		return NULL;
	}
	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	traverseBuildCTree(root, start, end);
	return root;
}

void setCount(SegmentTreeNode* node, int n){
	if (n < node->start || n > node->end){
		return;
	}
	node->count += 1;
	if (node->start == node->end){
		return;
	}
	int left = node->left->end;
	int right = node->right->start;
	if (n <= left)
		setCount(node->left, n);
	if (n >= right)
		setCount(node->right, n);
	return;
}

/** 6种情况
  查询段包含节点的start,end
  查询段是节点段的子集
  查询段的start在节点段中
  查询段的end在节点段中
  查询段不在节点段内

  注意：
  注意start与end的范围，可能会超过节点的范围
  对于节点范围内count为0的节点直接返回
*/
int querySegCount(SegmentTreeNode* root, int start, int end){
	if (root == NULL || start > end || start > root->end || end < root->start || root->count == 0){ //查询段不在节点段内
		return 0;
	}
	if (start <= root->start && end >= root->end){
		return root->count;
	}
	int cnt = 0;
	int left = root->left->end;
	int right = root->right->start;
	if (start > left){
		cnt =  querySegCount(root->right, start, end);
	}
	else if (end < right){
		cnt = querySegCount(root->left, start, end);
	}
	else{
		cnt = querySegCount(root->left, start, left);
		cnt += querySegCount(root->right, right, end);
	}
	return cnt;
}

int SegQuery_2(){
	int start, end;
	cin >> start >> end;
	SegmentTreeNode* root = buildCSegTree(start, end);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		setCount(root, arr[i]);
	}
	int x, y;
	while (1){
		cin >> x >> y;
		if (x == -1 && y == -1){
			break;
		}
		cout << querySegCount(root, x, y) << endl;
	}

	return 0;
}
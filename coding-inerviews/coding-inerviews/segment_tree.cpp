#include <iostream>

using namespace std;

/*
  segment tree，线段树又称区间树
  线段树是一棵二叉树，他的每个节点包含了两个额外的属性start和end用于表示该节点所代表的区间。start和end都是整数，并按照如下的方式赋值:
  	根节点的 start 和 end 由 build 方法所给出。
	对于节点 A 的左儿子，有 start=A.left, end=(A.left + A.right) / 2。
	对于节点 A 的右儿子，有 start=(A.left + A.right) / 2 + 1, end=A.right。
	如果 start 等于 end, 那么该节点是叶子节点，不再有左右儿子。
  实现一个 build 方法，接受 start 和 end 作为参数, 然后构造一个代表区间 [start, end] 的线段树，返回这棵线段树的根。
*/


struct SegmentTreeNode{
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int x, int y):start(x), end(y), left(NULL), right(NULL){}
};

void buildTree(SegmentTreeNode* pNode, int start, int end){
	if (start == end || !pNode){
		return;
	}
	int left = (start + end) / 2, right = left + 1;
	pNode->left = new SegmentTreeNode(start, left);
	pNode->right = new SegmentTreeNode(right, end);
	buildTree(pNode->left, start, left);
	buildTree(pNode->right, right, end);
	return;
}

SegmentTreeNode* buildSegmentTree(int start, int end){
	if (start > end){
		return NULL;
	}
	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	buildTree(root, start, end);
	return root;
}

void printSegmentTree(SegmentTreeNode* pNode){
	if (!pNode){
		return;
	}
	cout << "[" << pNode->start << "," << pNode->end << ")" << endl;
	if (pNode->left){
		printSegmentTree(pNode->left);
	}
	if (pNode->right){
		printSegmentTree(pNode->right);
	}
	return;
}

int segTree_test(){
	int start, end;
	cin >> start >> end;
	SegmentTreeNode* node = buildSegmentTree(start, end);
	printSegmentTree(node);
	return 0;
}





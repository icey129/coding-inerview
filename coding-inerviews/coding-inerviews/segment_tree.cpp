#include <iostream>

using namespace std;

/*
  segment tree���߶����ֳ�������
  �߶�����һ�ö�����������ÿ���ڵ�������������������start��end���ڱ�ʾ�ýڵ�����������䡣start��end�������������������µķ�ʽ��ֵ:
  	���ڵ�� start �� end �� build ������������
	���ڽڵ� A ������ӣ��� start=A.left, end=(A.left + A.right) / 2��
	���ڽڵ� A ���Ҷ��ӣ��� start=(A.left + A.right) / 2 + 1, end=A.right��
	��� start ���� end, ��ô�ýڵ���Ҷ�ӽڵ㣬���������Ҷ��ӡ�
  ʵ��һ�� build ���������� start �� end ��Ϊ����, Ȼ����һ���������� [start, end] ���߶�������������߶����ĸ���
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





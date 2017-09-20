#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
  ����һ���������飨�±��� 0 �� n-1�� n ��ʾ����Ĺ�ģ��ȡֵ��Χ�� 0 ��10000����
  ���������е�ÿ�� ai Ԫ�أ������ ai ǰ�����б���С��Ԫ�ص�������
*/

/*
  ����һ����֮ǰ��Ԫ������(��vector)��ʹ�ö��ֲ���(��lower_bound)�� ע��set����֧�֡�-������
  ���������߶���
  ����������״����
*/

//һ
vector<int> countOfSmallerNumberII_1(vector<int> &A) {
	vector<int> res;
	if (A.empty()){
		return res;
	}
	vector<int> lst;
	for (auto a : A){
		auto it = lower_bound(lst.begin(), lst.end(), a);
		res.push_back(it- lst.begin());
		lst.insert(it, a);
	}
	return res;
}

//��
struct SegmentTreeNode{
	int start, end;
	int count;
	SegmentTreeNode* left, *right;
	SegmentTreeNode(int x, int y, int z = 0) : start(x), end(y), count(z), left(NULL), right(NULL){}
};

void BuildCount1Tree(SegmentTreeNode* pNode, int start, int end){
	if (pNode == NULL || start == end){
		return;
	}
	int left = (start + end) / 2;
	int right = left + 1;
	pNode->left = new SegmentTreeNode(start, left);
	pNode->right = new SegmentTreeNode(right, end);
	BuildCount1Tree(pNode->left, start, left);
	BuildCount1Tree(pNode->right, right, end);
	return;
}

SegmentTreeNode* BuildSegCount1Tree(int start, int end){
	if (start > end){
		return NULL;
	}
	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	BuildCount1Tree(root, start, end);
	return root;
}

int insertVal(SegmentTreeNode* root, int n){
	if (n < root->start || n > root->end){
		return 0;
	}
	root->count += 1;
	if (n == root->start && n == root->end){
		return 0;
	}
	int left = root->left->end;
	int right = root->right->start;
	if (n <= left){
		return insertVal(root->left, n);
	}
	if (n >= right){
		int cnt = root->left->count;
		return cnt += insertVal(root->right, n);
	}
}

vector<int> countOfSmallerNumberII_2(vector<int> &A){
	SegmentTreeNode* root = BuildSegCount1Tree(0, 10000);
	vector<int> res;

	for (auto a : A){
		int tmp = insertVal(root, a);
		res.push_back(tmp);
	}
	return res;
}

//��
int len = 10000;
void add(vector<int>& arr, int num, int k){
	//����k=0�����
	while (k <= len){
		arr[k] += num;
		if (k == 0){
			k = 1;
		}
		else{
			k += k & (-k);
		}
	}
}

int read(vector<int>& arr, int k){ //��Ҫ����k=0��С��1��������Ҫ����0�ĸ���
	int sum = 0;
	if (k == 0){
		return arr[0];
	}
	while (k > 0){
		sum += arr[k];
		k -= k&(-k);
	}
	return sum;
}

vector<int> countOfSmallerNumberII_3(vector<int> &A){
	vector<int> res;
	if (A.empty()){
		return res;
	}
	vector<int> Tree(10001,0);
	for (auto a : A){
		res.push_back(read(Tree, a-1));
		add(Tree, 1, a);
	}
	return res;
}

int SegCountSmaller_test2(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> res = countOfSmallerNumberII_3(a);
	for (int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
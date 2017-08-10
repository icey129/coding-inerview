#include <iostream>
#include <vector>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence){
	if (sequence.empty()){
		return false;
	}

	bool res = true;
	int len = sequence.size() - 1, i = 0, j = 0;
	vector<int> lchild, rchild;

	for (i = 0; i < len; i++){ // left child
		if (sequence[i] > sequence[len]){
			break;
		}
		lchild.push_back(sequence[i]);
	}
	for (j = i; j < len; j++){ // right child
		if (sequence[j] < sequence[len]){
			return false;
		}
		rchild.push_back(sequence[j]);
	}
	if (i > 1){
		res &= VerifySquenceOfBST(lchild);
	}
	if (j > i + 1){
		res &= VerifySquenceOfBST(rchild);
	}
	return res;
}

bool VerifySquence(vector<int> sequence, size_t start_pos, size_t end_pos){
	if (start_pos > end_pos){
		return false;
	}

	int i = start_pos;
	for (i = start_pos; i < end_pos; i++){
		if (sequence[i] > sequence[end_pos]){
			break;
		}
	}
	int j = i;
	for (; j < end_pos; j++){
		if (sequence[j] < sequence[end_pos]){
			return false;
		}
	}
	bool res = true;
	if (i > start_pos + 1){
		res &= VerifySquence(sequence, start_pos, i - 1);
	}
	if (j > i + 1){
		res &= VerifySquence(sequence, i, end_pos - 1);
	}
	return res;
}

bool VerifySquenceOfBST2(vector<int> sequence) {
	int size = sequence.size();
	if (0 == size)return false;

	int i = 0;
	while (--size)
	{
		while (sequence[i++]<sequence[size]);
		while (sequence[i++]>sequence[size]);

		if (i<size)return false;
		i = 0;
	}
	return true;
}
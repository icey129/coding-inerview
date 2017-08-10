#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <functional>

using namespace std;

//方法一：二分法
void partitionNum(vector<int> input, int k, int start, int end);

vector<int> GetLeastKNumbers(vector<int> input, int k){
	vector<int> res;
	if (input.empty() || k <= 0){
		return res;
	}
	partitionNum(input, k, 0, input.size() - 1);
	for (int i = 0; i < k; i++){
		res.push_back(input[i]);
	}
	return res;
}

void partitionNum(vector<int> input, int k, int start, int end){
	int base = input[start];
	int i = start, j = end;
	vector<int> res;

	if (input.empty() || k <= 0 || start > end){
		return;
	}

	while (i < j){
		for (; j > i; j--){
			if (input[j] < base)
				break;
		}
		if (i < j){
			input[i] = input[j];
		}
		for (; i < j; i++){
			if (input[i] > base)
				break;
		}
		if (i < j){
			input[j] = input[i];
		}
	}
	input[i] = base;
	if (i == k - 1){
		return;
	}
	if (i < k - 1){
		partitionNum(input, k, i + 1, end);
	}
	else{
		partitionNum(input, k, start, i - 1);
	}
	return;
}

void swap_k(int & a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int partition_k(vector<int> input, int start, int end){
	int i = start, small = start - 1;
	uniform_int_distribution<unsigned> u(start, end);
	default_random_engine e;
	int index = u(e);
	swap_k(input[index], input[end]);
	for (; i < end; i++){
		if (input[i] <= input[end]){
			++small;
			if (small != i){
				swap_k(input[small], input[i]);
			}
		}
	}
	++small;
	swap_k(input[small], input[end]);
	return small;
}

//方法二：使用二叉树存储k个数，每次插入、删除、替换k个中最大的数，使用multiset（红黑树）或者最大堆O(logk)
vector<int> GetLeastKNumbers1(vector<int> input, int k){
	multiset<int, greater<int>> leastNumbers;
	vector<int> res;
	if (input.empty() || k <= 0)
		return res;
	for (auto iiter = input.cbegin(); iiter != input.cend(); iiter++){
		if (leastNumbers.size() < k){
			leastNumbers.insert(*iiter);
		}
		else{
			auto ite = leastNumbers.begin();
			if (*ite > *iiter){
				leastNumbers.erase(*ite);
				leastNumbers.insert(*iiter);
			}
		}
	}
	for (auto ite = leastNumbers.begin(); ite != leastNumbers.end(); ite++){
		res.push_back(*ite);
	}
	return res;
}

//大顶推
void BigHeapJust(vector<int>& data, int i, int len){
	if (len == 0 || len == 1){
		return;
	}
	for (int j = 2 * i + 1; j < len; j = 2 * i + 1){
		if (j < len - 1 && data[j + 1] > data[j]){
			j++;
		}
		if (data[j] > data[i]){
			data[i] = data[j] ^ data[i];
			data[j] = data[j] ^ data[i];
			data[i] = data[j] ^ data[i];
		}
		i = j;
	}
	return;
}

void LeastHeapSort(vector<int>& data, int len){
	if (len == 0 || len == 1){
		return;
	}
	for (int i = len / 2 - 1; i >= 0; i--){
		BigHeapJust(data, i, len);
	}
	for (int i = len - 1; i > 0; i--){
		data[i] = data[i] ^ data[0];
		data[0] = data[i] ^ data[0];
		data[i] = data[i] ^ data[0];
		BigHeapJust(data, 0, i);
	}
	return;
}


//方法三：使用堆排序存储k个数,考虑k=0的时候
vector<int> GetLeastKNumbers2(vector<int> input, int k){
	vector<int> kv;
	if (input.size() < k || k == 0){
		return kv;
	}
	int len = input.size(), i = 0;
	for (i = 0; i < k; i++){
		kv.push_back(input[i]);
	}
	for (int j = k / 2 - 1; j >= 0; j--){
		BigHeapJust(kv, j, k);
	}

	for (; i < len; i++){
		if (input[i] >= kv[0]){
			continue;
		}
		else{
			kv[0] = input[i];
			BigHeapJust(kv, 0, k);
		}
	}

	for (int j = k - 1; j > 0; j--){
		int tmp = kv[0];
		kv[0] = kv[j];
		kv[j] = tmp;
		BigHeapJust(kv, 0, j);
	}

	return kv;
}

int test30(){
	vector<int> d = { 2, 18, 27, 35, 40, 13, 24, 15, 10, 55, 39 };
	vector<int> res = GetLeastKNumbers2(d, 5);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
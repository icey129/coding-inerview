#include <iostream>
#include <vector>
#include <random>

using namespace std;

void cquicksort(vector<int>& arr, int start_pos, int end_pos){
	int i = start_pos, j = end_pos;
	if (start_pos >= end_pos){
		return;
	}
	int base = arr[start_pos];
	while (i < j){
		while (j > i && arr[j] > base){
			j--;
		}
		if (j > i)
			arr[i] = arr[j];
		while (j > i && arr[i] < base){
			i++;
		}
		if (i < j)
			arr[j] = arr[i];
	}
	arr[i] = base;
	cquicksort(arr, start_pos, i - 1);
	cquicksort(arr, i + 1, end_pos);
	return;
}

void swap(int & a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(vector<int>& arr, int length, int start_pos, int end_pos){
	if (arr.empty() || length <= 0 || start_pos < 0 || end_pos >= length){
		return -1;
	}
	uniform_int_distribution<unsigned> u(start_pos, end_pos);
	default_random_engine e;
	int index = u(e), small = start_pos-1; //small是小于arr[end]的数的下标
	swap(arr[index], arr[end_pos]);
	for (int i = start_pos; i < end_pos; i++){
		if (arr[i] <= arr[end_pos]){
			small++;
			if (small != i){
				swap(arr[small], arr[i]);
			}
		}
	}
	small++;
	swap(arr[small], arr[end_pos]);
	return small;
}

void cquicksort1(vector<int>& arr, int length, int start_pos, int end_pos){
	if (length <= 0 || start_pos < 0 || end_pos >= length){
		return;
	}
	int index = Partition(arr, length, start_pos, end_pos);
	if (index == -1){
		return;
	}
	if (index > start_pos)
		cquicksort1(arr, length, start_pos, index - 1);
	if (end_pos > index)
		cquicksort1(arr, length, index + 1, end_pos);
}

int CustomQuickSort(){
	vector<int> arr = { 34, 14, 25, 36, 47, 10, 45, 39};
	cquicksort1(arr,arr.size(), 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
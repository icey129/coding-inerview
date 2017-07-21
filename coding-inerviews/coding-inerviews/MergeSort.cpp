#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int>& a, int left, int mid, int right){
	int i = left, j = mid + 1;
	vector<int> c;
	while (i <= mid && j <= right){
		if (a[i] <= a[j]){
			c.push_back(a[i++]);
		}
		else{
			c.push_back(a[j++]);
		}
	}
	while (i <= mid){
		c.push_back(a[i++]);
	}
	while (j <= right){
		c.push_back(a[j++]);
	}
	int len = c.size();
	for (i = 0; i < len; i++){
		a[left + i] = c[i];
	}
	return;
}

void mergeSort(vector<int> &arr, int left, int right){
	int mid;
	if (left < right){
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		mergeArray(arr, left, mid, right);
	}
	return;
}

int merge_test(){
	vector<int> a = { 2, 4, 3, 7, 1, 5 };
	mergeSort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
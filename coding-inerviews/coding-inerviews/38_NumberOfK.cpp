#include <iostream>
#include <vector>

using namespace std;

int GetlastKPostion(vector<int> data, int k, int start, int end){
	if (start > end){
		return -1;
	}
	int res = -1, len = data.size();
	int mid = (start + end) / 2;
	if (data[mid] == k && (mid == end || data[mid + 1] != k)){
		res = mid;
	}
	else if (data[mid] == k){
		res = GetlastKPostion(data, k, mid + 1, end);
	}
	else if(data[mid] > k){
		res = GetlastKPostion(data, k, start, mid - 1);
	}
	else{
		res = GetlastKPostion(data, k, mid+1, end);
	}
	return res;
}

int GetfirstKposition(vector<int> data, int k, int start, int end){
	if (start > end){
		return -1;
	}
	int mid = (start + end) / 2;
	int res = 0;
	if (data[mid] == k && (mid == 0 || data[mid-1] != k)){
		res = mid;
	}
	else if(data[mid] == k){
		res = GetfirstKposition(data, k, start, mid - 1);
	}
	else if(data[mid] < k){
		res = GetfirstKposition(data, k, mid + 1, end);
	}
	else{
		res = GetfirstKposition(data, k, start, mid - 1);
	}
	return res;
}

int GetNumberOfK(vector<int> data, int k){
	int len = data.size();
	if (len == 0){
		return 0;
	}
	int left = 0, right = 0, res = 0;
	int start = 0, end = len - 1;

	left = GetfirstKposition(data, k, 0, len - 1);
	right = GetlastKPostion(data, k, 0, len - 1);
	if (left != -1 && right != -1){
		res = right - left + 1;
	}
	return res;
}

int test38(){
	vector<int> v = { 1, 2, 2, 3, 3, 3, 3, 3, 3, 5, 6, 7, 7 };
	cout << GetNumberOfK(v, 8);
	return 0;
}
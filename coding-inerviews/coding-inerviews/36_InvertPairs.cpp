#include <iostream>
#include <vector>

using namespace std;

int mergeInvertArr(vector<int>& data, int start, int end){
	int base = 1000000007;
	if (start == end){
		return 0;
	}

	int i = start, mid = (start + end) / 2;
	int j = mid + 1;
	unsigned int count = 0;
	vector<int> copy;

	while (i <= mid && j <= end){
		if (data[i] > data[j]){
			count += (mid - i + 1);
			count %= base;
			copy.push_back(data[j]);
			j++;
		}
		else{
			copy.push_back(data[i]);
			i++;
		}
	}
	while (i <= mid){
		copy.push_back(data[i++]);
	}
	while (j <= end){
		copy.push_back(data[j++]);
	}
	j = 0;
	for (i = start; i <= end; i++){
		data[i] = copy[j++];
	}
	return count % base;
}

int splitArr(vector<int>& data, int start, int end){
	int base = 1000000007;
	if (data.empty() || start == end){
		return 0;
	}
	int mid = (start + end) / 2;
	int count = 0;
	count += splitArr(data, start, mid);
	count %= base;
	count += splitArr(data, mid + 1, end);
	count %= base;
	count += mergeInvertArr(data, start, end);
	return count % base;
}

int InversePairs(vector<int> data){
	int len = data.size();
	if (len == 0 || len == 1){
		return 0;
	}
	return splitArr(data, 0, len - 1);
}

int test36(){
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 0 };
	cout << InversePairs(v) << endl;
	return 0;
}
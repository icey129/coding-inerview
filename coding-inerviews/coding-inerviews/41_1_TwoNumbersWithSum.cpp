#include <iostream>
#include <vector>

using namespace std;

/*
* 题目：求一个递增排序的数组中和为s的两个数
*/

bool FindSumKPairs(vector<int> v, int k, int* num1, int* num2){
	int len = v.size();
	if (len == 0){
		return false;
	}
	int i = 0, j = len - 1;
	while (i < j){
		if (v[i] + v[j] == k){
			*num1 = v[i];
			*num2 = v[j];
			return true;
		}
		if (v[i] + v[j] < k){
			i++;
		}
		else{
			j--;
		}
	}
	return false;
}

int test41_1(){
	vector<int> v = { 2, 5, 7, 9, 10, 19, 20 };
	int num1 = 0, num2 = 0;
	FindSumKPairs(v, 16, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}
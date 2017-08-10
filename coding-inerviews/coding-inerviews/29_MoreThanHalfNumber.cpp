#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> numbers, int left, int right);
bool MorethanHalf(vector<int> numbers, int num);

// 方案一：使用partition的方法
int MoreThanHalfNum_Solution(vector<int> numbers){
	int n = numbers.size();
	if (n == 0){
		return 0;
	}
	int res = partition(numbers, 0, n - 1);
	if (MorethanHalf(numbers, res)){
		return res;
	}
	else{
		return 0;
	}
}

int partition(vector<int> numbers, int left, int right){
	int n = numbers.size();
	int base = numbers[left];
	int i = left, j = right;

	while (i < j){
		for (; j > i; j--){
			if (numbers[j] < base){
				break;
			}
		}
		if (j > i)
			numbers[i] = numbers[j];
		for (; i < j; i++){
			if (numbers[i] > base){
				break;
			}
		}
		if (i < j)
			numbers[j] = numbers[i];
	}
	numbers[i] = base;
	if (i == n / 2){
		return base;
	}
	else if (i < n / 2){
		base = partition(numbers, i+1, right);
	}
	else{
		base = partition(numbers, left, i - 1);
	}
	return base;
}

bool MorethanHalf(vector<int> numbers, int num){
	int count = 0, n = numbers.size();
	for (int i = 0; i < n; i++){
		if (numbers[i] == num){
			count++;
		}
	}
	if (count > n / 2){
		return true;
	}
	else{
		return false;
	}
}

// 方案二：基于数组特点
int MoreThanHalfNum_Solution1(vector<int> numbers){
	int count = 0;
	int index = 0;
	int n = numbers.size();
	if (n == 0){
		return 0;
	}

	for(int i = 0; i < n; i++){
		if (count == 0){
			count = 1;
			index = i;
		}
		else if (numbers[i] != numbers[index]){
			count--;
		}
		else if(numbers[i] == numbers[index]){
			count++;
		}
	}
	if (MorethanHalf(numbers, numbers[index]))
		return numbers[index];
	else
		return 0;
}

int moreHalfNumber(){
	vector<int> v = { 1, 2, 3, 2, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution(v);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//需要考虑负数
int GreastSum(vector<int> input){
	int n = input.size();
	if (n == 0){
		return 0;
	}
	int sum = 0, max = 0x80000000;
	for (int i = 0; i < n; i++){
		if (input[i] > 0){
			sum += input[i];
			if (sum > max)
				max = sum;
		}
		else{
			sum += input[i];
			if (sum < 0){
				sum = 0;
			}
		}
	}
	return max;
}

/*
* 动态规划：用递归的方式分析，基于循环的方式实现
* 递归公式：
* f(i) = / pData[i]					i == 0 || f(i-1) < 0
*	     \ f(i-1) + pData[i]		i!=0 && f(i-1) > 0
* 求max(f(i))
*/

int GreastSum1(vector<int> input){
	int n = input.size();
	if (n == 0){
		return 0;
	}

	int sum = 0, max = 0;
	for (int i = 0; i < n; i++){
		if (sum <= 0){
			sum = input[i];
		}
		else{
			sum += input[i];
		}
		if (sum > max){
			max = sum;
		}
	}
	return max;
}
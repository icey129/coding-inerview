#include <iostream>
#include <vector>

using namespace std;

//��Ҫ���Ǹ���
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
* ��̬�滮���õݹ�ķ�ʽ����������ѭ���ķ�ʽʵ��
* �ݹ鹫ʽ��
* f(i) = / pData[i]					i == 0 || f(i-1) < 0
*	     \ f(i-1) + pData[i]		i!=0 && f(i-1) > 0
* ��max(f(i))
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
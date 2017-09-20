#include <iostream>
#include <vector>

using namespace std;

/*
* 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
* 找出这两个只出现一次的数字
* 
* 先简化问题，考虑一个数字只出现一次的情况，使用异或
* 再考虑两个数字出现一个的情况，对所有的数字异或，剩下这两个数字的异或值
* 这个异或值中肯定有一位为1，说明这两个数在这一位是不同的，使用这一位将数组划分为两部分
*/

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2){
	if (data.empty()){
		return;
	}
	int len = data.size();
	int x = 0;
	for (int i = 0; i < len; i++){
		x ^= data[i];
	}
	if (x == 0){
		return;
	}
	int bit = 0;
	while ((x | 1) != x){
		x = x >> 1;
		bit += 1;
	}
	x = 1 << bit;
	for (int i = 0; i < len; i++){
		if ((data[i] & x )== 0){
			(*num1) ^= data[i];
		}
		else{
			(*num2) ^= data[i];
		}
	}
	return;
}

int test40(){
	vector<int> v = { 1, 2, 3, 1, 4, 2, 3, 5, 6, 6 };
	int num1 = 0, num2 = 0;
	FindNumsAppearOnce(v, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}
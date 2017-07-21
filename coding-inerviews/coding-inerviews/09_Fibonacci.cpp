#include <iostream>
#include <vector>

using namespace std;

/*
* 解题思路：
* 1, 递归， f(n) = f(n-1) + f(n-1); n>= 2;
* 2, 循环 O(n)
* 3，数学公式求矩阵 
*  | 1 1 |^(n-2)
*  | 1 0 |
*/
int fibonacci(int n){
	if (n <= 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	int a[2] = { 0, 1 }, sum = 0;
	for (int i = 2; i <= n; i++){
		sum = a[0] + a[1];
		a[0] = a[1];
		a[1] = sum;
	}
	return a[1];
}


vector<vector<int>> matrix_multi(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> res = { { 0, 0 }, { 0, 0 } };
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			res[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		}
	}
	return res;
}

vector<vector<int>> matrix_power(vector<vector<int>> a, int n){
	vector<vector<int>> res = { {1,0}, {0,1} }, tmp;
	if (n <= 0){
		return res;
	}
	if (n == 1){
		return a;
	}
	if (n % 2 == 0){
		tmp = matrix_power(a, n / 2);
		res = matrix_multi(tmp, tmp);
	}
	if (n % 2 == 1){
		tmp = matrix_power(a, n / 2);
		res = matrix_multi(tmp, tmp);
		res = matrix_multi(res, a);
	}
	return res;
}

vector<vector<int>> matrix_power1(vector<vector<int>> a, int n){
	vector<vector<int>> res = { { 1, 0 }, { 0, 1 } }, cur = a;
	if (n <= 0){
		return res;
	}
	if (n == 1){
		return a;
	}
	while (n){
		if (n & 1){ //奇数
			res = matrix_multi(res, cur);
		}
		cur = matrix_multi(cur, cur);
		n = n >> 1;
	}
	return res;
}

//矩阵乘积的方式
int fibonacci_1(int n){
	if (n <= 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	vector<vector<int>> res = { { 1, 1 }, { 1, 0 } };
	res = matrix_power(res, n - 1);
	return res[0][0];
}

/*
* Fabonicci的应用，
* 应用一：
* 青蛙跳台阶，每次跳1阶或2阶
* 应用二：
* 跳台阶进阶，可以跳1阶，2阶，...,n阶
* f(n) = f(n-1) + f(n-2) + ... + f(1) + 1;
* f(n) = 2f(n-1) = 2^(n-1)
* 应用三：
* 矩形覆盖，用n个2*1的小矩形覆盖2*n的大矩形，共有多少种方法？
*/
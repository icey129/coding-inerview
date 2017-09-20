#include <iostream>
#include <vector>

using namespace std;

/*
 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 不能使用除法。(若是使用除法，需要注意A[i]为0的情况)
*/
vector<int> multiply(const vector<int>& A){
	int len = A.size();
	vector<int> res(len, 1);
	if (len == 0)
		return res;
	int mul = 1;
	for (int i = 1; i < len; i++){
		mul *= A[i - 1];
		res[i] = mul;
	}
	mul = 1;
	for (int i = len - 2; i >= 0; i--){
		mul *= A[i + 1];
		res[i] = mul*res[i];
	}
	return res;
}

int test52(){
	vector<int> v = { 2, 5, 4, 7, 9 };
	vector<int> res = multiply(v);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
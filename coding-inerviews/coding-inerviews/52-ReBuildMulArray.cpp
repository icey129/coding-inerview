#include <iostream>
#include <vector>

using namespace std;

/*
 ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
 ����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
 ����ʹ�ó�����(����ʹ�ó�������Ҫע��A[i]Ϊ0�����)
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
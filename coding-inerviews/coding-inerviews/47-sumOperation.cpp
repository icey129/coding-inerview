#include <iostream>

using namespace std;

//使用位运算实现加法
int AddNum(int num1, int num2){
	int sum = 0, upper = 0;
	while (num2){
		sum = (num1 ^ num2);
		upper = (num1 & num2 )<< 1;
		num1 = sum;
		num2 = upper;
	}
	return num1;
}

int test47(){
	int m, n;
	cin >> m >> n;
	cout << AddNum(m, n) << endl;
	return 0;
}
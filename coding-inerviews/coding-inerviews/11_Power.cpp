#include <iostream>

using namespace std;

bool equal(double a, double b){
	if ( (a - b > -0.000001) && (a-b < 0.000001)){
		return true;
	}
	else{
		return false;
	}
}

//O(n)
double unsignedExpPower(double base, unsigned int exponent){
	double res = 1.0;

	for (unsigned int i = 1; i <= exponent; i++){
		res *= base;
	}
	return res;
}

//二分法求power O(logn)
double unsignedExpPower1(double base, unsigned int exponent){
	double res = 1.0;
	if (exponent == 0){
		return 1;
	}
	if (exponent == 1){
		return base;
	}
	res = unsignedExpPower(base, exponent >> 1);
	res *= res;
	if (exponent & 0x01){
		res *= base;
	}
	return res;
}

//二分法循环实现
double unsignedExpPower2(double base, unsigned int exponent){
	double res = 1.0, cur = base;
	while (exponent){
		if (exponent & 0x01){
			res *= cur;
		}
		cur *= cur;
		exponent = (exponent >> 1);
	}
	return res;
}

double Power(double base, int exponent){
	if (equal(base, 0)){
		return 0;
	}

	if (exponent == 0){
		return 1;
	}

	unsigned int times = exponent;
	if (exponent < 0){
		times = -exponent;
	}
	
	double res = unsignedExpPower2(base, times);

	if (exponent < 0){
		res = 1.0 / res;
	}
	return res;
}

int power_test(){
	int exp;
	double base;
	while (1){
		cin >> base;
		if (equal(base, -1)){
			break;
		}
		cin >> exp;
		cout << Power(base, exp) << endl;
	}
	return 0;
}
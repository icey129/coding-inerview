#include <iostream>
#include <vector>

using namespace std;

int numberOf1ToN(int n){
	int ntmp = n;
	int base = 1;
	int sum = 0;
	int rest = 1;
	while (ntmp){
		sum += (ntmp / 10 * base);
		if (ntmp % 10 > 1){
			sum += base;
		}
		if (ntmp % 10 == 1){
			sum += rest;
		}
		base *= 10;
		rest = n % base + 1;
		ntmp /= 10;
	}
	return sum;
}

//程序员面试宝典解法
int f(int n){
	int ntmp = n;
	int base = 1;
	int rest = 1;
	int sum = 0;
	while (ntmp){
		sum += ((ntmp - 1) / 10 + 1)*base;
		if (ntmp % 10 == 1){
			sum -= base;
			sum += rest;
		}
		base *= 10;
		ntmp /= 10;
		rest = n % base + 1;
	}
	return sum;
}

int NumOf1(char * strN);

//剑指offer解法
int NumberOf1between1AndN(int n){
	if (n <= 0){
		return 0;
	}
	char strN[50];
	sprintf_s(strN, "%d", n);

	return NumOf1(strN);
}

int NumOf1(char * strN){
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0'){
		return 0;
	}
	int first = *strN - '0';
	unsigned int length = strlen(strN);

	if (length == 1 && first == 0){
		return 0;
	}

	if (length == 1 && first > 0){
		return 1;
	}

	int numFirstDigist = 0;
	if (first > 1)
		numFirstDigist = pow(10, length - 1);
	else
		numFirstDigist = atoi(strN + 1) + 1;

	int numOtherDigit = 0;
	numOtherDigit = first * (length - 1) * pow(10, length - 2);

	int numRecursive = NumOf1(strN+1);

	return numFirstDigist + numOtherDigit + numRecursive;
}

int test32(){
	int n;
	cin >> n;
	cout << numberOf1ToN(n) << endl;
	cout << f(n) << endl;
	cout << NumberOf1between1AndN(n) << endl;
	return 0;
}
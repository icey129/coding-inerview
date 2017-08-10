#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int n){
	while (n % 2 == 0){
		n /= 2;
	}
	while (n % 3 == 0){
		n /= 3;
	}
	while (n % 5 == 0){
		n /= 5;
	}
	if (n == 1){
		return true;
	}
	else{
		return false;
	}
}

int GetUglyNum(int n){
	if (n <= 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	int i = 1;
	int num = 2;
	while (i != n){
		if (isUgly(num++)){
			i++;
		}
	}
	return num - 1;
}

int getMinNum(int x, int y, int z){
	int min = x < y ? x : y;
	return min < z ? min : z;
}

int GetUglyNum1(int n){
	vector<int> uglyNum;
	if (n <= 0){
		return 0;
	}
	int t2 = 0, t3 = 0, t5 = 0;
	int count = 1;
	uglyNum.push_back(1);

	while (count != n){
		int min = getMinNum(uglyNum[t2] * 2, uglyNum[t3] * 3, uglyNum[t5] * 5);
		uglyNum.push_back(min);
		while (uglyNum[t2] * 2 <= uglyNum[count])
			t2++;
		while (uglyNum[t3] * 3 <= uglyNum[count])
			t3++;
		while (uglyNum[t5] * 5 <= uglyNum[count])
			t5++;
		count++;
	}
	return uglyNum[n - 1];
}

int test34(){
	int n;
	cin >> n;
	cout << GetUglyNum(n) << endl;
	cout << GetUglyNum1(n) << endl;
	return 0;
}
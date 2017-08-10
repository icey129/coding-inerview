#include <iostream>

using namespace std;

void printNum(char * num, int len){
	int flag = 0;
	for (int i = 0; i < len; i++){
		if (!flag && num[i] != '0'){
			flag = 1;
		}
		if (flag){
			cout << num[i];
		}
	}
	if (flag)
		cout << endl;
	return;
}

void getPrintNum(char * num, int index, int len){
	if (index == len){
		num[index] = '\0';
		printNum(num, len);
		return;
	}
	for (int i = 0; i < 10; i++){
		num[index] = i + '0';
		getPrintNum(num, index + 1, len);
	}
	return;
}

bool addCharNum(char * num, int len){
	int overNum = 0;
	int sum = 0;
	bool end_flag = true;
	for (int i = len - 1; i >= 0; i--){
		sum = num[i] - '0' + overNum;
		if (i == len - 1){
			sum += 1;
		}
		if (sum >= 10){
			if (i == 0){
				end_flag = false;
			}
			else{
				overNum = 1;
				num[i] = sum - 10 + '0';
			}
		}
		else{
			num[i] = sum + '0';
			break;
		}
	}
	return end_flag;
}

//本题考查重点在大数的处理，使用字符串处理大数
void Print1ToMaxOfNDigits(int n){
	if (n <= 0){
		return;
	}

	char * num = new char[n + 1]{'0'}; //存储n位数
	num[n] = '\0';

	//getPrintNum(num, 0, n);
	while (addCharNum(num, n)){
		printNum(num, n);
	}
	delete[] num;
	return;
}

int print1ToMaxNNum_test(){
	int n;
	while (1){
		cin >> n;
		if (n == -1){
			break;
		}
		Print1ToMaxOfNDigits(n);
	}
	return 0;
}
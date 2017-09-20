#include <iostream>
#include <string>

using namespace std;

string reverseString(string str, int start, int end){
	if (start >= end){
		return string();
	}
	int i = start, j = end - 1;
	char ch;
	while (i < j){
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i++;
		j--;
	}
	string res(str, start, end - start);
	return res;
}

string LeftRotateString(string str, int n) {
	string res;
	int len = str.size();
	if (len == 0){
		return res;
	}
	int shift = n % len;
	res = reverseString(str, 0, shift) + reverseString(str, shift, len);
	res = reverseString(res, 0, len);
	return res;
}

int test42_2(){
	string str;
	cin >> str;
	int n;
	cin >> n;
	cout << LeftRotateString(str, n);
	return 0;
}
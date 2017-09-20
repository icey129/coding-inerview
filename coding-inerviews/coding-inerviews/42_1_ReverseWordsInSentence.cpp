#include <iostream>
#include <string>

using namespace std;

/*
* 方法一：划单词split
* 方法二：不划分单词，直接逆转
*/

void reverseStr(string& str, int start, int end){
	if (start >= end){
		return;
	}
	int i = start, j = end - 1;
	char ch;
	for (; i < j; i++, j--){
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
	return;
}

string ReverseSentence(string str) {
	if (str.empty()){
		return str;
	}
	int i = 0, len = str.size(), j = 0;
	reverseStr(str, 0, len);
	for (i = 0; i <= len; i++){
		if (i == len || str[i] == ' '){
			reverseStr(str, j, i);
			j = i + 1;
		}
	}
	return str;
}

int test42_1(){
	string str = "I am a student.";
	cout << ReverseSentence(str);
	return 0;
}
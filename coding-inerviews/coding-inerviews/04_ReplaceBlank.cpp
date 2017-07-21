/*
* 请实现一个函数，将一个字符串中的空格替换成“%20”。
* 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class ReplaceBlank {
public:
	//方法一，使用额外的内存，创建新的字符串
	//在clang编译器上需要添加#include<cstring>或#include<string.h>,否则strcpy_s显示为定义，在牛客网上不可用。
	void replaceSpace1(char *str, int length) {
		int sp_count = 0;
		for (int i = 0; i < length; i++){
			if (str[i] == ' '){
				sp_count += 1;
			}
		}
		char * new_str = (char*)malloc(sizeof(char)* (length + sp_count * 2 + 1));
		int i, j;
		for ( i = 0, j = 0; i < length; i++){
			if (str[i] == ' '){
				new_str[j++] = '%';
				new_str[j++] = '2';
				new_str[j++] = '0';
			}
			else{
				new_str[j++] = str[i];
			}
		}
		new_str[j] = '\0';
		strcpy_s(str, j+1, new_str);
		free(new_str);
		new_str = NULL;
	}
	//方法二，先确定转换后的字符串的总长，再从后向前复制变化。
	//注意这里的length的含义，length是字符数组的总容量
	void replaceSpace(char *str, int length) {
		int sp_count = 0, len = 0, rlen = 0;
		if (str == NULL || length <= 0){
			return;
		}
		while (str[len] != '\0'){
			if (str[len] == ' '){
				sp_count += 1;
			}
			len++;
		}
		rlen = len + sp_count * 2;
		if (rlen > length){
			return;
		}
		int p = len, q = rlen;
		while (p != q){
			if (str[p] == ' '){
				str[q--] = '0';
				str[q--] = '2';
				str[q--] = '%';
				p--;
			}
			else{
				str[q--] = str[p--];
			}
		}
	}
};

int RB_test(){
	ReplaceBlank rb;
	//char str[100];
	char * str = (char*)malloc(sizeof(char)* 100);
	gets_s(str, 99);
	rb.replaceSpace(str, 100);
	cout << str << endl;
	return 0;
}
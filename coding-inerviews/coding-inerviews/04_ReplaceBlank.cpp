/*
* ��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
* ���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class ReplaceBlank {
public:
	//����һ��ʹ�ö�����ڴ棬�����µ��ַ���
	//��clang����������Ҫ���#include<cstring>��#include<string.h>,����strcpy_s��ʾΪ���壬��ţ�����ϲ����á�
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
	//����������ȷ��ת������ַ������ܳ����ٴӺ���ǰ���Ʊ仯��
	//ע�������length�ĺ��壬length���ַ������������
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
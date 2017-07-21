#include <iostream>

using namespace std;

int count1num(int n){
	int count = 0;
	while (n){
		n = n & (n - 1);
		count += 1;
	}
	return count;
}

int count1num_2(int n){
	n -= (n >> 1) & 0x55555555; //ÿ��λ�ж���1
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);  //ÿ4λ�ж��ٸ�1
	n = (n + (n >> 4)) & 0x0f0f0f0f; //ÿ8λ�ж���1
	return (n * 0x01010101) >> 24;   //����x + (x << 8) + (x << 16) + (x << 24)��8bits
}

/** 033333333333��8���ƣ�ÿ��λΪһ�飬��ʾΪa*2^2+b*2+c,1�ĸ���Ϊa+b+c
* ����1λ��4a+2b+cΪ 2a+b
* ����2λ��4a+2b+cΪ a
* ��������4a+2b+c - (2a+b) - a = a+b+c ��Ӧ��һ��
* tmp+(tmp>>3)��������ӣ�������ظ���ӵĲ��֣�Ϊ����6bits 1�ĸ����� ���������λ
* &030707070707 �����ظ��ӵĲ���
* ��6bit��ʾ1�ĸ��������63��
*/
int BitCount5(unsigned int n)
{
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111); //����3bits 1�ĸ���
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}
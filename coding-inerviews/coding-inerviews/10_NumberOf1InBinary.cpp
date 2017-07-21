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
	n -= (n >> 1) & 0x55555555; //每两位有多少1
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);  //每4位有多少个1
	n = (n + (n >> 4)) & 0x0f0f0f0f; //每8位有多少1
	return (n * 0x01010101) >> 24;   //留下x + (x << 8) + (x << 16) + (x << 24)的8bits
}

/** 033333333333是8进制，每三位为一组，表示为a*2^2+b*2+c,1的个数为a+b+c
* 右移1位，4a+2b+c为 2a+b
* 右移2位，4a+2b+c为 a
* 做减法：4a+2b+c - (2a+b) - a = a+b+c 对应第一步
* tmp+(tmp>>3)相邻组相加，会产生重复相加的部分，为相邻6bits 1的个数， 不会产生进位
* &030707070707 消除重复加的部分
* 用6bit表示1的个数，最多63个
*/
int BitCount5(unsigned int n)
{
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111); //相邻3bits 1的个数
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}
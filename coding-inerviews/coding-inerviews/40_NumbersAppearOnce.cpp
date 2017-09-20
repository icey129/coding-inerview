#include <iostream>
#include <vector>

using namespace std;

/*
* һ�����������������������֮�⣬���������ֶ����������Ρ�
* �ҳ�������ֻ����һ�ε�����
* 
* �ȼ����⣬����һ������ֻ����һ�ε������ʹ�����
* �ٿ����������ֳ���һ��������������е��������ʣ�����������ֵ����ֵ
* ������ֵ�п϶���һλΪ1��˵��������������һλ�ǲ�ͬ�ģ�ʹ����һλ�����黮��Ϊ������
*/

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2){
	if (data.empty()){
		return;
	}
	int len = data.size();
	int x = 0;
	for (int i = 0; i < len; i++){
		x ^= data[i];
	}
	if (x == 0){
		return;
	}
	int bit = 0;
	while ((x | 1) != x){
		x = x >> 1;
		bit += 1;
	}
	x = 1 << bit;
	for (int i = 0; i < len; i++){
		if ((data[i] & x )== 0){
			(*num1) ^= data[i];
		}
		else{
			(*num2) ^= data[i];
		}
	}
	return;
}

int test40(){
	vector<int> v = { 1, 2, 3, 1, 4, 2, 3, 5, 6, 6 };
	int num1 = 0, num2 = 0;
	FindNumsAppearOnce(v, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}
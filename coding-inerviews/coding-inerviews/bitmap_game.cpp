#include <iostream>

using namespace std;
#define MASK 0x1f
#define SHIFT 5

/*
* ��Ϸ������
* ��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ���������һ����1024��������ID��Χ[1,1024]��
* ����32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ���ʼ״̬����δ��ɡ� 
* ����������������������ID����Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ� 
* ���һ������������ڶ���ID�������Ѿ�������1�����δ������0�������һ��ڶ���ID����[1,1024]��Χ�������-1��
*/

void set_bit(unsigned int* task, unsigned int x){
	task[x >> SHIFT] |= 1 << (x & MASK);
}

unsigned int get_bit(unsigned int* task, unsigned int x){
	return task[x >> SHIFT] & (1 << (x & MASK));
}

int bitmap_game(){
	unsigned int sval, gval;
	unsigned int task[32] = {0};
	cin>>sval>>gval;
	if (sval > 1024 || sval < 1 || gval > 1024 || gval < 1){
		cout << -1;
	}
	else{
		set_bit(task, sval-1);
		if (get_bit(task, gval-1))
			cout << 1;
		else
			cout << 0;
	}

	return 0;
}
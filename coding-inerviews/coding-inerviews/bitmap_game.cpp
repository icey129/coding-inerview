#include <iostream>

using namespace std;
#define MASK 0x1f
#define SHIFT 5

/*
* 游戏任务标记
* 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。
* 请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 
* 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 
* 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
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
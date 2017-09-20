#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.empty()){
		return false;
	}

	sort(numbers.begin(), numbers.end());

	int len = numbers.size();
	int count0 = 0, i = 0;
	bool res = true;
	for (i = 0; i < len - 1; i++){
		if (numbers[i] == 0){
			count0++;
		}
		else{
			int tmp = numbers[i + 1] - numbers[i];
			if (tmp == 1){
				continue;
			}
			else if (tmp == 0 || tmp-1 > count0){
				res = false;
				break;
			}
			else{
				count0 -= tmp - 1;
			}
		}
	}
	return res;
}

/*
* 方法二：使用Hash表统计所有的输入，除0外不能有重复的数字，且最大最小值的差小于5
*/
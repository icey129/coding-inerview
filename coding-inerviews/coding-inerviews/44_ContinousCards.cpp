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
* ��������ʹ��Hash��ͳ�����е����룬��0�ⲻ�����ظ������֣��������Сֵ�Ĳ�С��5
*/
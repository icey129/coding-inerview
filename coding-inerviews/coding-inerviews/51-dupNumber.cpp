#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication){
	if (length <= 0 || numbers == NULL){
		return false;
	}

	for (int i = 0; i < length; i++){
		if (numbers[i] < 0 || numbers[i] > length - 1){
			return false;
		}
	}

	//可以不需要使用cnt
	int* cnt = new int[length]{0};
	int i = 0;
	bool res = false;
	while (i < length){
		int tmp = numbers[i];
		if (tmp != i){
			if (cnt[tmp] != 0){
				*duplication = tmp;
				res = true;
				break;
			}
			else{
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
				cnt[tmp] += 1;
			}
		}
		else{
			cnt[tmp] += 1;
			i++;
		}
	}
	return res;
}

int test51(){
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	int dup = 0;
	bool res;
	res = duplicate(numbers, 7, &dup);
	if (res){
		cout << dup << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}
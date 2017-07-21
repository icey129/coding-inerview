/*
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <iostream>
#include <vector>

using namespace std;

class findInPatitiallySortedMatrix{
public:
	//方法一，时间复杂度O(n^2)
	bool Find1(int target, vector<vector<int> > array) {
		int k = array[0].size();
		for (int i = 0; i < array.size(); i++){
			for (int j = 0; j < k; j++){
				if (array[i][j] == target){
					return true;
				}
				if (array[i][j] > target){
					k = j;
					break;
				}
			}
		}
		return false;
	}

	//方法二，从右上角开始逐行逐列剔除,时间复杂度O(n),2n
	bool Find(int target, vector<vector<int> > array) {
		int ilen = array.size(), jlen = array[0].size();
		int i = 0, j = jlen - 1;
		while (i < ilen && j >= 0){
			if (array[i][j] == target){
				return true;
			}
			if (array[i][j] > target){
				j--;
			}
			else{
				i++;
			}
		}
		return 0;
	}
};
/*
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
* �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

#include <iostream>
#include <vector>

using namespace std;

class findInPatitiallySortedMatrix{
public:
	//����һ��ʱ�临�Ӷ�O(n^2)
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

	//�������������Ͻǿ�ʼ���������޳�,ʱ�临�Ӷ�O(n),2n
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
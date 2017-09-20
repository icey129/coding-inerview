#include <iostream>
#include <vector>

using namespace std;

/*
* ����һ����������ӡ�����к�Ϊs��������������
* �ⷨ����������ѧ���ʽ���
* (a1+an)*n/2=s
* n=an-a1+1
* x = a1+an, y = an - a1 + 1, xy = 2s
* an = (x+y-1)/2
* a1 = (x-y+1)/2
* Ȼ��ö��x,y,��2s������
*/

vector<int> buildArr(int start, int end){
	vector<int> res;
	if (start > end){
		return res;
	}
	for (int i = start; i < end; i++){
		res.push_back(i);
	}
	return res;
}

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> res;
	int num = 0;
	int i = 0, j = 1;
	if (sum == 0){
		return res;
	}
	while (i < j && j <= sum){
		if (num == sum){
			res.push_back(buildArr(i + 1, j));
			num += j;
			j++;
		}
		else if (num < sum){
			num += j;
			j++;
		}
		else{
			++i;
			num -= i;
		}
	}
	return res;
}

int test41_2(){
	int num;
	cin >> num;
	vector<vector<int>> vv;
	vv = FindContinuousSequence(num);
	for (int i = 0; i < vv.size(); i++){
		for (int j = 0; j < vv[i].size(); j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
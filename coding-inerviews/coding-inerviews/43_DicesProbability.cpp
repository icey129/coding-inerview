#include <iostream>
#include <vector>

using namespace std;

/*
* 方法一：递归，会有很多重复操作
* 方法二：循环
*/

void countDicesSum(vector<int>& counter, int n, int sum, int pos){
	if (n <= 0){
		return;
	}
	if (pos == n - 1){
		for (int i = 1; i <= 6; i++){
			counter[sum + i - n]++;
		}
		return;
	}
	else{
		for (int i = 1; i <= 6; i++){
			countDicesSum(counter, n, sum + i, pos + 1);
		}
	}
	return;
}

vector<double> PrintProbability(int n){
	vector<double> res;
	if (n <= 0){
		return res;
	}
	vector<double> pro;
	vector<int> counter(5 * n + 1, 0);
	double base = pow(6, n);
	countDicesSum(counter, n, 0, 0);
	for (int i = 0; i < 5 * n + 1; i++){
		pro.push_back(double(counter[i]) / base);
	}
	return pro;
}

int test43(){
	int n;
	cin >> n;
	vector<double> res = PrintProbability(n);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	return 0;
}
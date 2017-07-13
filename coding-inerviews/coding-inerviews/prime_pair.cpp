#include <iostream>
#include <vector>

using namespace std;

/*
* 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
* 如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
*/

void count_prime(vector<unsigned int>& prime, unsigned int n){
	int k = 0, flag = 0;
	prime.push_back(2);
	k++;

	for (int i = 3; i <= n; i += 2){
		for (int j = 1; j < k; j++){
			if (i % prime[j] == 0){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			prime.push_back(i);
			k++;
		}
		else{
			flag = 0;
		}
	}
}

int count_pair(const vector<unsigned int>& prime, unsigned int n){
	int len = prime.size();
	int count = 0;
	for (int i = 0, j = len - 1; i <= j;){
		if (prime[i] + prime[j] > n){
			j--;
		}
		else if (prime[i] + prime[j] < n){
			i++;
		}
		else{
			count++;
			i++;
			j--;
		}
	}
	return count;
}

int prime_pair(){
	unsigned int n;
	vector<unsigned int> v;
	cin >> n;
	count_prime(v, n);
	int count = count_pair(v, n);
	cout << count << endl;
	return 0;
}
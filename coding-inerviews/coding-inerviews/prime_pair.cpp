#include <iostream>
#include <vector>

using namespace std;

/*
* ����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
* �磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10,�ֱ�Ϊ(5,5),(3,7)�� 
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
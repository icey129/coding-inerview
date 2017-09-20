#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/*
* С�׷ǳ�ϲ��ӵ���������ʵ�����:
* 1�����еĳ���Ϊn
* 2�������е�ÿ��������1��k֮��(����1��k)
* 3������λ�����ڵ�������A��B(A��Bǰ),������(A <= B)��(A mod B != 0)(������һ����)
* ����,��n = 4, k = 7
* ��ô{1,7,7,2},���ĳ�����4,��������Ҳ��1��7��Χ��,�����������������,����С����ϲ��������е�
* ����С�ײ�ϲ��{4,4,4,2}������С�С�׸���n��k,ϣ�����ܰ�������ж��ٸ�������ϲ�������С�
*/

const int mode = 1000000007;
int db[11][100001];

int seq_test(){
	int n, k;
	cin >> n >> k;

	db[0][1] = 1;
	//db[i][j] = sum(db[i-1])-db[i-1][kj], k = 1,2,...
	for (int i = 1; i <= n; i++){ //ǰi������
		int sum = 0;
		for (int j = 1; j <= k; j++){
			sum += db[i - 1][j]; //ǰi-1�������ֵ������ܺ�
			sum %= mode;
		}
		for (int j = 1; j <= k; j++){
			int p = 2;
			int invalid = 0; //�����������������
			while (j*p <= k){
				invalid += db[i - 1][j*p]; //��iΪ����ȡj�ı��� ��A>B��AmodB==0
				p++;
				invalid %= mode;
			}
			db[i][j] = (sum - invalid + mode) % mode;
		}
	}
	int sum = 0;
	for (int i = 1; i <= k; i++){
		sum += db[n][i];
		sum %= mode;
	}
	cout << sum <<endl;

	return 0;
}
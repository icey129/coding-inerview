#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/*
* 小易非常喜欢拥有以下性质的数列:
* 1、数列的长度为n
* 2、数列中的每个数都在1到k之间(包括1和k)
* 3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
* 例如,当n = 4, k = 7
* 那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
* 但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。
*/

const int mode = 1000000007;
int db[11][100001];

int seq_test(){
	int n, k;
	cin >> n >> k;

	db[0][1] = 1;
	//db[i][j] = sum(db[i-1])-db[i-1][kj], k = 1,2,...
	for (int i = 1; i <= n; i++){ //前i个数列
		int sum = 0;
		for (int j = 1; j <= k; j++){
			sum += db[i - 1][j]; //前i-1个数出现的排列总和
			sum %= mode;
		}
		for (int j = 1; j <= k; j++){
			int p = 2;
			int invalid = 0; //求不满足条件的组合数
			while (j*p <= k){
				invalid += db[i - 1][j*p]; //第i为不能取j的倍数 即A>B且AmodB==0
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
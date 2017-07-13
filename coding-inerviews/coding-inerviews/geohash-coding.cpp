#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* geohash编码
* 此题考察纬度的二进制编码：算法对纬度[-90, 90]通过二分法进行无限逼近（取决于所需精度，本题精度为6）。注意，本题进行二分法逼近过程中只采用向下取整来进行二分，针对二分中间值属于右区间。算法举例如下： 针对纬度为80进行二进制编码过程：
* 1) 区间[-90, 90]进行二分为[-90, 0),[0, 90]，成为左右区间，可以确定80为右区间，标记为1；
* 2) 针对上一步的右区间[0, 90]进行二分为[0, 45),[45, 90]，可以确定80是右区间，标记为1；
* 3) 针对[45, 90]进行二分为[45, 67),[67,90],可以确定80为右区间，标记为1；
* 4) 针对[67,90]进行二分为[67, 78),[78,90]，可以确定80为右区间，标记为1；
* 5) 针对[78, 90]进行二分为[78, 84),[84, 90]，可以确定80为左区间，标记为0；
* 6) 针对[78, 84)进行二分为[78, 81), [81, 84)，可以确定80为左区间，标记为0；
*/

string geoencode(int n){
	string code(7,0);
	int left = -90, right = 90;
	int mid, i;
	for ( i = 0; i < 6; i++){
		mid = (left + right) / 2;
		if (n >= mid){
			left = mid;
			code[i] = 1+'0';
		}
		else{
			right = mid;
			code[i] = 0 + '0';
		}
	}
	code[i] = '\0';
	return code;
}

void geoencode1(vector<int>& v, int n){
	int left = -90, right = 90, mid;
	while (right - left >= 6){
		mid = (left + right) / 2;
		if (n >= mid){
			left = mid;
			v.push_back(1);
		}
		else{
			right = mid;
			v.push_back(0);
		}
	}
	return;
}

int geohash(){
	int n;
	cin >> n;
	cout << geoencode(n) << endl;
	vector<int> v;
	geoencode1(v, n);
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
	return 0;
}
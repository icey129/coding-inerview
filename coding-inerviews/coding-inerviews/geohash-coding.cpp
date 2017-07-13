#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* geohash����
* ���⿼��γ�ȵĶ����Ʊ��룺�㷨��γ��[-90, 90]ͨ�����ַ��������ޱƽ���ȡ�������辫�ȣ����⾫��Ϊ6����ע�⣬������ж��ַ��ƽ�������ֻ��������ȡ�������ж��֣���Զ����м�ֵ���������䡣�㷨�������£� ���γ��Ϊ80���ж����Ʊ�����̣�
* 1) ����[-90, 90]���ж���Ϊ[-90, 0),[0, 90]����Ϊ�������䣬����ȷ��80Ϊ�����䣬���Ϊ1��
* 2) �����һ����������[0, 90]���ж���Ϊ[0, 45),[45, 90]������ȷ��80�������䣬���Ϊ1��
* 3) ���[45, 90]���ж���Ϊ[45, 67),[67,90],����ȷ��80Ϊ�����䣬���Ϊ1��
* 4) ���[67,90]���ж���Ϊ[67, 78),[78,90]������ȷ��80Ϊ�����䣬���Ϊ1��
* 5) ���[78, 90]���ж���Ϊ[78, 84),[84, 90]������ȷ��80Ϊ�����䣬���Ϊ0��
* 6) ���[78, 84)���ж���Ϊ[78, 81), [81, 84)������ȷ��80Ϊ�����䣬���Ϊ0��
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
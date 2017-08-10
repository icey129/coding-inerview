#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

// ������ϵķ�ʽ��ÿ�δ�ʣ����ַ���ȷ��һλ������˳��ʣ��ļ�������
// �ѵ㣺ע�⺬���ظ��ַ�������������Ҫ�����ֵ����˳��
void getString(string str, int start, vector<string>& v);
void getString1(string str, int start, vector<string>& v);

// �ַ��д�Сд,���ظ��������ֵ�������
vector<string> Permutation(string str){
	vector<string> res;
	if (str.empty()){
		return res;
	}
	sort(str.begin(), str.end());
	getString(str, 0, res);
	return res;
}

//�����ַ����󲻻ָ�
void getString(string str, int start, vector<string>& v){
	if (start == str.size() - 1){
		v.push_back(str);
		return;
	}
	char ch;
	// �����󲻻ָ���abcd->bacd->cabd(c��b����)->dabc(d��c����)
	// ÿ�ν�����ָ�Ϊabcd��abcd->bacd(a��b����)->cbad(a��c����)->dbca(a��d����)
	for (int i = start; i < str.size(); i++){
		if (str[start] != str[i] || start == i){
			ch = str[start];
			str[start] = str[i];
			str[i] = ch;
			getString(str, start + 1, v);
		}
	}
	return;
}

//�����ַ�����ָ�,�����str����ʹ�����ã���Ϊ�ݹ�ĺ������ַ�����������������Ӱ��ָ�
void getString1(string str, int start, vector<string> &v){
	if (start == str.size() - 1){
		v.push_back(str);
		return;
	}
	char ch;
	map<char, int> mp;
	sort(str.begin() + start, str.end()); //����λ�ú��ַ�˳�򱻴��ң���������

	for (int i = start; i < str.size(); i++){
		if (mp[str[i]] != 1){
			mp[str[i]] = 1;
			ch = str[i];
			str[i] = str[start];
			str[start] = ch;
			getString1(str, start + 1, v);
			ch = str[i];
			str[i] = str[start];
			str[start] = ch;
		}
	}
}

int stringPermutation(){
	string str = "abcd";
	vector<string> v = Permutation(str);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}
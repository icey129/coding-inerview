#include <iostream>
#include <string>

using namespace std;

/* 
* ��ʱ���
* ��ʵı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰ���ʵı��밴�ֵ��������γ�һ���������£�
* a, aa, aaa, aaaa, aaab, aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy
* ����a��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ�
* ��дһ������������������һ�����룬����baca�������������Ӧ��Index��
* ��дһ������������������һ��Index������12345��������Index��Ӧ�ı��롣
*/
int factor[4] = { 25 * 25 * 25 + 25 * 25 + 25 + 1, 25 * 25 + 25 + 1, 25 + 1, 1 };

int wubiencode(string str){
	int index = 0;
	for (int i = 0; i < str.size(); i++){
		index += (str[i] - 'a')*factor[i] + 1;
	}
	return index - 1;
}

/*
* ������Ϸ�ʽ���
* ������dbc��index
* ��һλ ��(d-a)+1��ѡ��, 1��Ӧ��Ϊѡ��d
* �ڶ�λ ��(d-a)*25+(b-a)+1��ѡ�񣬵�һλѡ��(d-a)����ڶ�λ��ѡ(d-a)*25, ����һλѡd����ڶ�λ��ѡ(b-a),�ټ���db����
* ����λ ��(d-a)*25^2+(b-a)*25+(c-a)+1��ѡ�񣬶�Ӧ�ڶ�λǰ(d-a)*25+(b-a)����ѡ25�е�һ��,��ѡ��db,�����λ��ѡ(c-1),�ټ�dbc����
* ����λ ��(d-a)*25^3+(b-a)*25^2+(c-a)*25��ѡ�񣬶�Ӧ����λǰ(d-a)*25^2+(b-a)*25+(c-a)����ѡ25�е�һ������25���ַ�����������λ
* indexΪ�ۼ�����4�����
*/
int wubicode1(string str){
	int index = 0, tmp = 0;
	int len = str.size();
	for (int i = 0; i < 4; i++){
		tmp *= 25;
		if (i < len){
			tmp += (str[i] - 'a');
			index += tmp + 1;
		}
		else{
			index += tmp;
		}
	}
	return index - 1;
}

string wubidecode(int index){
	if (index < 0){
		return "wrong";
	}
	int i = 0;
	string str(5, 0);
	index += 1;
	while (index > 0){
		index--;
		str[i] = 'a' + index / factor[i];
		index = index % factor[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

int wubi(){
	int index;
	string str;
	cin >> str;
	cin >> index;
	cout << wubiencode(str) << endl;
	cout << wubicode1(str) << endl;
	cout << wubidecode(index) << endl;
	return 0;
}
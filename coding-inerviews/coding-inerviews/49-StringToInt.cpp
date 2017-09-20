#include <iostream>
#include <string>

using namespace std;
//��Ҫ���Ǵ�����ַ���Ϊ�գ��մ��������ţ�ֻ�������ţ���Ч���֣�������Խ�����

bool inValid = false;

int StrToInt(string str){
	int flag = 0;
	if (str.empty()){ //�����¿մ��Ϳ�
		inValid = true;
		return 0;
	}
	int len = str.size();
	int i = 0;
	if (str[0] == '-'){
		flag = 1;
		i = 1;
	}
	else if(str[0] == '+'){
		i = 1;
	}
	if (i == len){
		inValid = true;
		return 0;
	}
	long long num = 0;
	int tmp = flag ? -1 : 1;
	while (i < len){
		if (str[i] >= '0' && str[i] <= '9'){
			num = num * 10 + tmp * (str[i] - '0');
			i++;
			if ((!flag && num > 0x7fffffff) || (flag && num < (signed int)0x80000000)){
				inValid = true;
				break;
			}
		}
		else{
			inValid = true;
			break;
		}
	}
	if (inValid){
		return 0;
	}
	return num;
}

int test49(){
	string str;
	cin >> str;
	int x = StrToInt(str);
	if (inValid){
		cout << "error" << endl;
	}
	else{
		cout << x << endl;
	}
	return 0;
}
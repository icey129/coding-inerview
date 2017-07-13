#include <iostream>
#include <string>

using namespace std;

/* 
* 五笔编码
* 五笔的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把五笔的编码按字典序排序，形成一个数组如下：
* a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy
* 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。
* 编写一个函数，输入是任意一个编码，比如baca，输出这个编码对应的Index；
* 编写一个函数，输入是任意一个Index，比如12345，输出这个Index对应的编码。
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
* 按照组合方式求解
* 例如求dbc的index
* 第一位 有(d-a)+1种选择, 1对应的为选择d
* 第二位 有(d-a)*25+(b-a)+1种选择，第一位选择(d-a)，则第二位可选(d-a)*25, 若第一位选d，则第二位可选(b-a),再加上db本身
* 第三位 有(d-a)*25^2+(b-a)*25+(c-a)+1种选择，对应第二位前(d-a)*25+(b-a)，任选25中的一个,若选择db,则第三位可选(c-1),再加dbc本身
* 第四位 有(d-a)*25^3+(b-a)*25^2+(c-a)*25种选择，对应第三位前(d-a)*25^2+(b-a)*25+(c-a)，任选25中的一个乘以25，字符串不含第四位
* index为累加上述4中情况
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
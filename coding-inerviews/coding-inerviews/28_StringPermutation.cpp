#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

// 利用组合的方式，每次从剩余的字符串确定一位，交换顺序，剩余的继续迭代
// 难点：注意含有重复字符，并且排列需要按照字典序的顺序
void getString(string str, int start, vector<string>& v);
void getString1(string str, int start, vector<string>& v);

// 字符有大小写,有重复，按照字典序排列
vector<string> Permutation(string str){
	vector<string> res;
	if (str.empty()){
		return res;
	}
	sort(str.begin(), str.end());
	getString(str, 0, res);
	return res;
}

//调整字符串后不恢复
void getString(string str, int start, vector<string>& v){
	if (start == str.size() - 1){
		v.push_back(str);
		return;
	}
	char ch;
	// 交换后不恢复：abcd->bacd->cabd(c与b交换)->dabc(d与c交换)
	// 每次交换后恢复为abcd：abcd->bacd(a与b交换)->cbad(a与c交换)->dbca(a与d交换)
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

//调整字符串后恢复,这里的str不能使用引用，因为递归的函数对字符串进行了重新排序，影响恢复
void getString1(string str, int start, vector<string> &v){
	if (start == str.size() - 1){
		v.push_back(str);
		return;
	}
	char ch;
	map<char, int> mp;
	sort(str.begin() + start, str.end()); //调换位置后字符顺序被打乱，重新排序

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
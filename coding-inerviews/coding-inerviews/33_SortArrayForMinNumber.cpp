#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const string& strn1, const string& strn2){
	string rs1 = strn1 + strn2;
	string rs2 = strn2 + strn1;
	return rs1 < rs2;
}

vector<string> ForMinNumber(vector<int> number){
	vector<string> strNum;
	int len = number.size();
	char tmp[50];
	for (int i = 0; i < len; i++){
		sprintf_s(tmp, "%d", number[i]);
		strNum.push_back(string(tmp));
	}
	sort(strNum.begin(), strNum.end(), comp);
	return strNum;
}

int test33(){
	vector<int> v = { 3, 32, 321 };
	vector<string> res = ForMinNumber(v);
	for_each(res.begin(), res.end(), [](const string &s){cout << s; });
	return 0;
}
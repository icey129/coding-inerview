#include <iostream>
#include <vector>
#include <string>

using namespace std;

char FirstNotRepeatChar(string pstr){
	if (pstr.empty()){
		return '\0';
	}
	unsigned int hash[256] = {0};
	int len = pstr.size();
	int i = 0;
	if (len == 0){
		return NULL;
	}
	for (i = 0; i < len; i++){
		hash[pstr[i]] += 1;
	}
	for (i = 0; i < len; i++){
		if (hash[pstr[i]] == 1){
			break;
		}
	}
	return pstr[i];
}

int test35(){
	string str;
	cin >> str;
	cout << FirstNotRepeatChar(str) << endl;
	return 0;
}
#include <iostream>

using namespace std;

//[sign]integral-digits[.[fractional-digits]][e|E[sign]exponential-digits]
//小数点前的数可以省略

bool isInteger(char ** str){
	char* p = *str;
	while (**str >= '0' && **str <= '9'){
		(*str)++;
	}
	if (p == *str){
		return false;
	}
	else{
		return true;
	}
}

bool isNumeric(char* string){
	if (string == NULL){
		return false;
	}
	//[sign]
	if (*string == '+' || *string == '-'){
		string++;
	}
	if (*string == '\0'){
		return false;
	}
	bool res = true;
	int flag = 0;
	//integral
	if (isInteger(&string)){
		flag = 1;
	}
	
	if (*string == '.'){//fractional
		string++;
		isInteger(&string);
	}
	if ((*string == 'e' || *string == 'E') && flag){ //exponential
		string++;
		if (*string == '+' || *string == '-'){
			string++;
		}
		res &= isInteger(&string);
	}
	if (*string != '\0'){
		res = false;
	}
	return res;
}

int test54(){
	char str[100];
	while (1){
		cin >> str;
		if (strcmp(str, "-0") == 0){
			break;
		}
		cout << isNumeric(str) << endl;
	}
	return 0;
}
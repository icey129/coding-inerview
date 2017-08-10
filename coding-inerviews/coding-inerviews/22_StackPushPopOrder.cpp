#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//½èÖú¸¨ÖúÕ»
bool IsPopOrder(vector<int> pushV, vector<int> popV){
	stack<int> stk;
	unsigned int len_push = pushV.size(), len_pop = popV.size();
	int i = 0, j = 0;

	if (len_push == 0 || len_pop == 0){
		return false;
	}

	while (j < len_pop){
		if (stk.empty() || stk.top() != popV[j]){
			if (i > len_push){
				break;
			}
			stk.push(pushV[i++]);
		}
		else{
			j++;
			stk.pop();
		}
	}
	if (stk.empty()){
		return true;
	}
	else{
		return false;
	}
}

bool IsPopOrder1(vector<int> pushV, vector<int> popV){
	size_t lenpush = pushV.size(), lenpop = popV.size();
	size_t i = 0, j = 0;
	stack<int> stk;

	if (lenpush == 0 || lenpop == 0){
		return false;
	}
	for (i = 0; i < lenpop; i++){
		while (stk.empty() || stk.top() != popV[i]){
			if (j == lenpush){
				break;
			}
			stk.push(pushV[j++]);
		}
		if (stk.top() == popV[i]){
			stk.pop();
		}
		else{
			return false;
		}
	}
	return true;
}

//²»Ê¹ÓÃ¸¨ÖúÕ»
bool IsPopOrder2(vector<int> pushV, vector<int> popV){
	size_t stk_out = -1, stk_in = 0;
	size_t lenpush = pushV.size(), lenpop = popV.size();

	if (lenpush == 0 || lenpop == 0){
		return false;
	}
	for (int i = 0; i < lenpop; i++){
		while (stk_out == -1 || pushV[stk_out] != popV[i]){
			if (stk_in == lenpush){
				break;
			}
			pushV[++stk_out] = pushV[stk_in++];
		}
		if(pushV[stk_out] == popV[i]){
			stk_out--;
		}
		else{
			return false;
		}
	}
	return true;
}

int PushPopOrder(){
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 3, 2, 1, 4, 5 };
	cout << IsPopOrder(pushV, popV);
	return 0;
}
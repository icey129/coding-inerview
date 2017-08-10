#pragma once

#include <iostream>
#include <stack>

using namespace std;

//存每次的最小元素，即当前的value与smin的栈顶元素中较小的一个
//只要栈顶有数据，辅助栈的栈顶一定是最小值，移除数据栈顶同时移除辅助栈栈顶
template <typename T> class stackWithMin{
public:
	void push(const T& val);
	void pop();
	T top();
	T min();

private:
	stack<T> sdata;
	stack<T> smin;
};

template <typename T> void stackWithMin<T>::push(const T &val){
	T min;
	if (sdata.empty()){
		min = val;
	}
	else{
		min = val < smin.top() ? val : smin.top();
	}
	smin.push(min);
	sdata.push(val);
}

template <typename T> void stackWithMin<T>::pop(){
	sdata.pop();
	smin.pop();
}

template <typename T> T stackWithMin<T>::top(){
	return sdata.top();
}

template <typename T> T stackWithMin<T>::min(){
	return smin.top();
}
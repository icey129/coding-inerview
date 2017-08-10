#pragma once

#include <iostream>
#include <stack>

using namespace std;

//��ÿ�ε���СԪ�أ�����ǰ��value��smin��ջ��Ԫ���н�С��һ��
//ֻҪջ�������ݣ�����ջ��ջ��һ������Сֵ���Ƴ�����ջ��ͬʱ�Ƴ�����ջջ��
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
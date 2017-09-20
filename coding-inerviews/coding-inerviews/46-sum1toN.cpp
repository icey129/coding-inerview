#include <iostream>

using namespace std;

/*
* 方法一：利用类的构造函数
* 方法二：利用虚函数
* 方法三：利用函数指针
* 方法四：利用模板
*/

class SumN{
	static int n;
	static int sum;
public:
	static void reset(){
		n = 0;
		sum = 0;
	}
	static int getSum(){
		return sum;
	}
	SumN(){
		n += 1;
		sum += n;
	}
};
int SumN::n = 0;
int SumN::sum = 0;

//2
class Base;
Base* arr[2];

class Base{
public:
	virtual int getSum(int n){
		return 0;
	}
};

class Drived : public Base{
public:
	virtual int getSum(int n){
		return arr[!!n]->getSum(n - 1) + n;
	}
};

//3
typedef int(*func)(int);
func f[2];

int funcA(int n){
	return 0;
}

int funcB(int n){
	return f[!!n](n - 1) + n;
}

int SumN_test(){
	int n;
	cin >> n;
	SumN::reset();
	SumN *a = new SumN[n];
	delete [] a;
	cout << SumN::getSum() << endl;

	Base b;
	Drived d;
	arr[0] = &b;
	arr[1] = &d;
	cout << d.getSum(n) << endl;

	f[0] = funcA;
	f[1] = funcB;
	cout << funcB(n) << endl;

	return 0;
}
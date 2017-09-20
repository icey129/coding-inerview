#include <iostream>
using namespace std;

/*
* 方法一：使用循环列表（自定义或list）
* 方法二：推导递归公式
*/

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

int LastRemaining(int n, int m){
	if (n <= 0){
		return -1;
	}
	if (n == 1){
		return 0;
	}
	int i = 0, res = 0;
	ListNode* head = new ListNode(0), *p = head;
	for (i = 1; i < n; i++){
		p->next = new ListNode(i);
		p = p->next;
	}
	p->next = head;

	p = head;
	ListNode* q = head;
	int count = 0;
	while (p->next != p){
		if (count == m - 1){
			q->next = p->next;
			delete p;
			p = q->next;
			count = 0;
		}
		else{
			count += 1;
			q = p;
			p = p->next;
		}
	}
	res = p->val;
	delete p;
	p = NULL;
	return res;
}

/*
* 方法二：
* f(n,m)表示每次淘汰第m个后，最后剩余的一个
* k = (m-1)%n,即淘汰序号为k的数字
* f'(n-1,m)表示在			k+1,...,n-1,0,...,k-1中追个淘汰第m个数字剩余的结果，而f(n,m)=f'(n-1,m)
* 对剩余的数字做变换变为：	0,...,n-k-2,n-k-1,...,n-2. 即求f(n-1,m)
* 两个序列的变换关系为：p(x) = (x+k+1)%n,x为变换后的序列索引，p(x)为在原序列的索引
* 将f(n-1,m)的值转换为对应的f'(n-1,m)= (f(n-1,m)+k+1)%n
* 将k = (m-1)%n代入后，即为f'(n-1,m)-(f(n-1,m)+m)%n;
* 得到迭代公式 f(n,m)= /0;				  n = 1
*					   \(f(n-1),m)+m)%n;  n > 1
*/
int LastRemaining1(int n, int m){
	if (n < 1){
		return -1;
	}
	if (n == 1){
		return 0;
	}
	return (LastRemaining(n - 1, m) + m) % n;
}
// 循环实现
int LastRemaining2(int n, int m){
	if (n < 1){
		return -1;
	}
	if (n == 1){
		return 0;
	}
	int res = 0;
	for (int i = 2; i <= n; i++){
		res = (res + m) % i;
	}
	return res;
}

int test45(){
	int m, n;
	cin >> n;
	cin >> m;
	cout << LastRemaining2(n, m) << endl;
	return 0;
}
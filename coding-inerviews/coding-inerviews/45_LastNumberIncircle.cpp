#include <iostream>
using namespace std;

/*
* ����һ��ʹ��ѭ���б��Զ����list��
* ���������Ƶ��ݹ鹫ʽ
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
* ��������
* f(n,m)��ʾÿ����̭��m�������ʣ���һ��
* k = (m-1)%n,����̭���Ϊk������
* f'(n-1,m)��ʾ��			k+1,...,n-1,0,...,k-1��׷����̭��m������ʣ��Ľ������f(n,m)=f'(n-1,m)
* ��ʣ����������任��Ϊ��	0,...,n-k-2,n-k-1,...,n-2. ����f(n-1,m)
* �������еı任��ϵΪ��p(x) = (x+k+1)%n,xΪ�任�������������p(x)Ϊ��ԭ���е�����
* ��f(n-1,m)��ֵת��Ϊ��Ӧ��f'(n-1,m)= (f(n-1,m)+k+1)%n
* ��k = (m-1)%n����󣬼�Ϊf'(n-1,m)-(f(n-1,m)+m)%n;
* �õ�������ʽ f(n,m)= /0;				  n = 1
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
// ѭ��ʵ��
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
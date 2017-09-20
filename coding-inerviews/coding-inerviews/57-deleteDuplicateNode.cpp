#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL){
		return NULL;
	}
	ListNode* p = pHead, *q = pHead;
	ListNode* rHead = new ListNode(0), *rp = rHead;
	while (p){
		if (!p->next || p->val != p->next->val){
			rp->next = p;
			rp = rp->next;
			p = p->next;  // 切到下一个节点
			rp->next = NULL;  //断开连接
		}
		else{
			q = p->next;
			while (q && p->val == q->val){
				ListNode* t = q;
				q = q->next;
				delete t;
				t = NULL;
			}
			delete p;
			p = q;
		}
	}
	rp = rHead;
	rHead = rHead->next;
	delete rp;
	return rHead;
}

int test57(){
	int a[] = { 1, 2, 3, 3,3, 4, 4, 5 };
	int b[] = { 2, 2, 4, 4, 5, 5, 6, 6 };
	ListNode* la = new ListNode(1), *pa = la;
	ListNode* lb = new ListNode(2), *pb = lb;
	for (int i = 1; i < 8; i++){
		la->next = new ListNode(a[i]);
		la = la->next;
	}
	for (int i = 1; i < 8; i++){
		lb->next = new ListNode(b[i]);
		lb = lb->next;
	}
	pa = deleteDuplication(pa);
	pb = deleteDuplication(pb);
	la = pa;
	lb = pb;
	while (la){
		cout << la->val << " " << endl;
		la = la->next;
	}
	cout << endl;
	while (lb){
		cout << lb->val << " " << endl;
		lb = lb->next;
	}
	cout << endl;
	return 0;
}
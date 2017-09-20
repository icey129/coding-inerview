#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

/*
 先使用快慢指针找到环，以及环的长度
 再用一个指针先走环的长度，然后一个指针从头开始，两个同步移动
*/
ListNode* EntryNodeOfLoop(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL){
		return NULL;
	}
	ListNode* p = pHead->next, *q = pHead->next->next;

	//是否存在环
	while (q && p != q){
		p = p->next;
		if (!q->next || !q->next->next){
			break;
		}
		q = q->next->next;
	}
	if (q == NULL){
		return NULL;
	}

	q = p->next;
	int c_num = 1;
	while (p != q){
		c_num += 1;
		q = q->next;
	}

	p = pHead;
	q = pHead;
	while (c_num > 0){
		q = q->next;
		c_num--;
	}
	while (p != q){
		p = p->next;
		q = q->next;
	}
	return p;
}

/*
 牛客思路：
 第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，直到p1==p2找到在环中的相汇点。
 第二步，找环的入口。接上步，当p1==p2时，p2所经过节点数为2x,p1所经过节点数为x,设环中有n个节点,p2比p1多走一圈有2x=kn+x;
 再让p2指向链表头部，p1位置不变，p1,p2每次走一步直到p1==p2;
 此时p1指向环的入口。
 证明：
 设相遇时慢指针走了x，环长n，2x=x+kn,走了k圈，x=kn,
 设起点到入口的距离y，快慢指针距入口x-y时相遇，距离整个列表长len-x
 快针从起点重新开始以步长为1速度开始走，经过距离y到达环入口点，
 慢针走y步后距离环入口点距离为x-y+len-x+y-(len-x)=x=nr，即走到了环入口点，两个指针相遇
*/

ListNode* EntryNodeOfLoop2(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL){
		return NULL;
	}
	ListNode* p = pHead->next, *q = pHead->next->next;
	while (p != NULL && q != NULL){
		p = p->next;
		if (!q->next || !q->next->next){
			return NULL;
		}
		q = q->next->next;
		if (p == q){
			q = pHead;
			while (p != q){
				p = p->next;
				q = q->next;
			}
			if (p == q){
				return p;
			}
		}
	}
	return NULL;
}

int test56(){
	ListNode* pHead = new ListNode(1);
	ListNode* p = pHead, *q = NULL;
	for (int i = 2; i < 10; i++){
		p->next = new ListNode(i);
		p = p->next;
		if (i == 4){
			q = p;
		}
	}
	p->next = q;
	p = EntryNodeOfLoop(pHead);
	cout << p->val << endl;
	return 0;
}
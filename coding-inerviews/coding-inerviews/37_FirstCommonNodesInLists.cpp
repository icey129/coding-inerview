#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (!pHead1 || !pHead2)
		return NULL;
	int len1 = 0, len2 = 0;
	ListNode* p1 = pHead1, *p2 = pHead2;
	while (p1){
		len1 += 1;
		p1 = p1->next;
	}
	while (p2){
		len2 += 1;
		p2 = p2->next;
	}
	p1 = pHead1;
	p2 = pHead2;
	if (len1 < len2){
		int step = len2 - len1;
		while (step > 0){
			p2 = p2->next;
			step--;
		}
	}
	if (len1 > len2){
		int step = len1 - len2;
		while (step > 0){
			p1 = p1->next;
			step--;
		}
	}
	while (p1 && p2){
		if (p1 == p2){
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}
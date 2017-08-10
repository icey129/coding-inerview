#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int i) :val(i), next(NULL){}
};

//循环实现
ListNode* MergeTwoOrderList(ListNode* pHead1, ListNode* pHead2){
	ListNode* resHead = NULL, *res = NULL;
	ListNode* p1 = pHead1, *p2 = pHead2;

	while (p1 && p2){
		if (p1->val <= p2->val){
			if (resHead == NULL){
				resHead = p1;
				res = resHead;
			}
			else{
				res->next = p1;
				res = res->next;
			}
			p1 = p1->next;
		}
		else{
			if (resHead == NULL){
				resHead = p2;
				res = resHead;
			}
			else{
				res->next = p2;
				res = res->next;
			}
			p2 = p2->next;
		}
	}
	while (p1){
		if (resHead == NULL){
			resHead = p1;
			res = resHead;
		}
		else{
			res->next = p1;
			res = res->next;
		}
		p1 = p1->next;
	}
	while (p2){
		if (resHead == NULL){
			resHead = p2;
			res = resHead;
		}
		else{
			res->next = p2;
			res = res->next;
		}
		p2 = p2->next;
	}
	return resHead;
}

//迭代实现
ListNode* MergeTwoOrderList1(ListNode* pHead1, ListNode* pHead2){
	if (pHead1 == NULL){
		return pHead2;
	}
	if (pHead2 == NULL){
		return pHead1;
	}

	ListNode* ResHead = NULL;
	if (pHead1->val < pHead2->val){
		ResHead = pHead1;
		ResHead->next = MergeTwoOrderList1(pHead1->next, pHead2);
	}
	else{
		ResHead = pHead2;
		ResHead->next = MergeTwoOrderList1(pHead1, pHead2->next);
	}
	return ResHead;
}
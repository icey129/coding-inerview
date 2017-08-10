#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

//考察程序的鲁棒性，pListHead=NULL时，以及k=0时
ListNode * FindKthtotail(ListNode* pListHead, unsigned int k){
	ListNode* pk = pListHead, *pt = pListHead;
	if (pListHead == nullptr || k <= 0){
		return nullptr;
	}
	while (--k > 0 && pt != nullptr){
		pt = pt->next;
	}
	if (pt == nullptr){
		return nullptr;
	}
	while (pt->next != nullptr){
		pt = pt->next;
		pk = pk->next;
	}
	return pk;
}
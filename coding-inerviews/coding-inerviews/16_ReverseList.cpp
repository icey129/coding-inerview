#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL){}
};

ListNode* ReverseList(ListNode* pHead) {
	ListNode* cur = pHead;
	ListNode* pro = NULL;
	ListNode* next = pHead;

	while (cur != NULL){
		next = cur->next;
		cur->next = pro;
		pro = cur;
		cur = next;
	}
	return pro;
}
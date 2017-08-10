#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int i):val(i), next(NULL){}
};

/*
* 考虑
* 情况1：delete_node是否在链表中 (未处理)
* 情况2：删除的节点为头结点、尾节点、中间节点
* 情况3：只有一个节点
* 情况4：指针为空
*/
void DeleteNode(ListNode ** pHead, ListNode * delete_node){
	if (delete_node == nullptr || pHead == nullptr){
		return;
	}
	if ((*pHead) == delete_node && delete_node->next == NULL){
		delete delete_node;
		delete_node = nullptr;
		(*pHead) = nullptr;
		return;
	}
	ListNode * pp = nullptr;
	if (delete_node->next == nullptr){ //尾节点
		pp = (*pHead);
		while (pp->next != delete_node){
			pp = pp->next;
		}
		pp->next = nullptr;
		delete delete_node;
		delete_node = nullptr;
		return;
	}
	pp = delete_node->next;
	delete_node->val = pp->val;
	delete_node->next = pp->next;
	delete pp;
	pp = nullptr;
	return;
}

int DeleteNode_test(){
	ListNode * pHead = nullptr, *pp = nullptr;

	for (int i = 1; i < 10; i++){
		if (i == 1){
			pHead = new ListNode(i);
			pp = pHead;
		}
		else{
			pp->next = new ListNode(i);
			pp = pp->next;
		}
	}
	DeleteNode(&pHead, pHead);
	DeleteNode(&pHead, pp);

	pp = pHead;
	while (pp->val != 5){
		pp = pp->next;
	}
	DeleteNode(&pHead, pp);

	ListNode * pHead1 = new ListNode(1);
	DeleteNode(&pHead1, pHead1);

	return 0;
}
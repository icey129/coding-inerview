#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int i):val(i), next(NULL){}
};

/*
* ����
* ���1��delete_node�Ƿ��������� (δ����)
* ���2��ɾ���Ľڵ�Ϊͷ��㡢β�ڵ㡢�м�ڵ�
* ���3��ֻ��һ���ڵ�
* ���4��ָ��Ϊ��
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
	if (delete_node->next == nullptr){ //β�ڵ�
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
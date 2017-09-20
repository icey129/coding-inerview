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
 ��ʹ�ÿ���ָ���ҵ������Լ����ĳ���
 ����һ��ָ�����߻��ĳ��ȣ�Ȼ��һ��ָ���ͷ��ʼ������ͬ���ƶ�
*/
ListNode* EntryNodeOfLoop(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL){
		return NULL;
	}
	ListNode* p = pHead->next, *q = pHead->next->next;

	//�Ƿ���ڻ�
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
 ţ��˼·��
 ��һ�����һ������㡣�ֱ���p1��p2ָ������ͷ����p1ÿ����һ����p2ÿ���߶�����ֱ��p1==p2�ҵ��ڻ��е����㡣
 �ڶ������һ�����ڡ����ϲ�����p1==p2ʱ��p2�������ڵ���Ϊ2x,p1�������ڵ���Ϊx,�軷����n���ڵ�,p2��p1����һȦ��2x=kn+x;
 ����p2ָ������ͷ����p1λ�ò��䣬p1,p2ÿ����һ��ֱ��p1==p2;
 ��ʱp1ָ�򻷵���ڡ�
 ֤����
 ������ʱ��ָ������x������n��2x=x+kn,����kȦ��x=kn,
 ����㵽��ڵľ���y������ָ������x-yʱ���������������б�len-x
 �����������¿�ʼ�Բ���Ϊ1�ٶȿ�ʼ�ߣ���������y���ﻷ��ڵ㣬
 ������y������뻷��ڵ����Ϊx-y+len-x+y-(len-x)=x=nr�����ߵ��˻���ڵ㣬����ָ������
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
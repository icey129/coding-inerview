#include <iostream>
#include <map>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

/*
* 第一步，将复制的节点插入到原列表中，跟在复制的节点后面
* 第二步，复制random信息p->s, 对应p->next -> s->next
* 第三步，提出复制列表
*/
RandomListNode* clone(RandomListNode* pHead){
	RandomListNode * new_node = NULL, *rHead = NULL;
	RandomListNode * p = pHead, *q = NULL;
	if (!pHead){
		return NULL;
	}
	while (p){
		new_node = new RandomListNode(p->label);
		q = p->next;
		p->next = new_node;
		new_node->next = q;
		p = q;
	}

	p = pHead;
	while (p){
		if (p->random)
			p->next->random = p->random->next;
		p = p->next->next;
	}

	rHead = pHead->next;
	p = pHead;
	while (p->next){
		q = p->next;
		p->next = q->next;
		p = q;
	}
	return rHead;
}

//map
RandomListNode* clone1(RandomListNode* pHead){
	RandomListNode* rHead = NULL, *p = NULL, *new_node = NULL;
	RandomListNode* q = NULL;
	map<RandomListNode*, RandomListNode*> mp;
	if (!pHead){
		return NULL;
	}
	p = pHead;
	while (p){
		new_node = new RandomListNode(p->label);
		if (!rHead){
			rHead = new_node;
			q = rHead;
		}
		else{
			q->next = new_node;
			q = q->next;
		}
		mp.insert(make_pair(p, q));
		p = p->next;
	}

	p = pHead;
	q = rHead;
	while (p){
		if (p->random){
			q->random = mp[p->random];
		}
		p = p->next;
		q = q->next;
	}
	return rHead;
}


int copyComplexList(){
	RandomListNode * head = NULL, *p = NULL, * q2 = NULL, *q3 = NULL;
	head = new RandomListNode(1);
	p = head;
	for (int i = 2; i < 5; i++){
		p->next = new RandomListNode(i);
		p = p->next;
		if (i == 2){
			q2 = p;
		}
		if (i == 3){
			q3 = p;
		}
	}
	p->random = q2;
	head->random = q3;
	RandomListNode* res = clone(head);
	return 0;
}
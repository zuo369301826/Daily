#include <iostream>
#include <vector>
using namespace std;

#if 0
//1.有序链表的合成
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) 
	{}
};

class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		ListNode *ret = NULL;
		if (pHead1->val < pHead2->val) 
		{
			ret = new ListNode(pHead1->val);
			pHead1 = pHead1->next;
		}
		else 
		{
			ret = new ListNode(pHead2->val);
			pHead2 = pHead2->next;
		}

		ListNode *cur = ret;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				cur->next = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
			}
			else
			{
				cur->next = new ListNode(pHead2->val);;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		while (pHead1 != NULL)
		{
			cur->next = new ListNode(pHead1->val);
			pHead1 = pHead1->next;
			cur = cur->next;
		}
		while (pHead2 != NULL)
		{
			cur->next = new ListNode(pHead2->val);;
			pHead2 = pHead2->next;
			cur = cur->next;
		}
		return ret;
	}
};

#endif

#if 0
//复杂数组的拷贝
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) 
	{}
};

class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* cur = pHead;
		while (cur)
		{
			RandomListNode* New = new RandomListNode(cur->label);
			New->next = cur->next;
			cur->next = New;
			cur = New->next;
		}
		cur = pHead;
		RandomListNode* next = cur->next;
		while (cur)
		{
			next = cur->next;
			if (cur->random == NULL)
				next->random = NULL;
			else next->random = cur->random->next;
			cur = next->next;
		}
		cur = pHead;
		next = cur->next;
		RandomListNode* ret = cur->next;
		while (cur)
		{
			next = cur->next;
			cur->next = cur->next->next;
			if(next->next)
				next->next = next->next->next;
			cur = cur->next;
		}
		return ret;
	}
};
#endif
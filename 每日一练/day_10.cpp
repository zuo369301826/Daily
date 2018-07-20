#include <iostream>
#include <vector>
using namespace std;

#if 0
//合并两个单链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};

class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *pHead = NULL;
		if (pHead1 && pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				pHead = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
			}
			else 
			{
				pHead = new ListNode(pHead2->val);
				pHead2 = pHead2->next;
			}
		}
		else if (pHead1 == NULL && pHead2 == NULL)
			return NULL;
		else if (pHead1 == NULL)
			return pHead2;
		else return pHead1;
	
		ListNode *pCur= pHead;
		while (pHead1 && pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				pCur->next = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
				pCur = pCur->next;
			}
			else
			{
				pCur->next = new ListNode(pHead2->val);
				pHead2 = pHead2->next;
				pCur = pCur->next;
			}
		}

		if (pHead1 == NULL)
		{
			while(pHead2)
			{
				pCur->next = new ListNode(pHead2->val);
				pHead2 = pHead2->next;
				pCur = pCur->next;
			}
		}
		else 
		{
			while (pHead1)
			{
				pCur->next = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};

#endif


//2 .列表逆置
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};
class Solution {
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		ListNode *p1= pHead, *p2= pHead, *p3=NULL;
		while (p2)
		{
			p1 = p2->next;
			p2->next = p3;
			p3 = p2;
			p2 = p1;
		}
		return p3;
	}
};
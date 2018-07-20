#include <iostream>
using namespace std;

#if 0
/* µ¥Á´±íÅÅÐò  ¹é²¢ÅÅÐò  nlogn */
 struct ListNode {     
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * sortList(ListNode *head) {

		if (!head || !head->next) return head;

		ListNode* pCur = head;
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p2 && p2->next)
		{
			pCur = p1;
			p1 = p1->next;
			p2 = p2->next->next;
		}
		pCur->next = NULL;

		return sort(sortList( head ), sortList( p1 ));
	}

	ListNode* sort(ListNode* p1, ListNode* p2)
	{
		ListNode* phead = NULL;
		if (p1->val < p2->val)
		{
			phead = p1;
			p1 = p1->next;
		}
		else 
		{
			phead = p2;
			p2 = p2->next;
		}

		ListNode* pCur = phead;
		while (p1 && p2)
		{
			if (p1->val < p2->val)
			{
				pCur->next = p1;
				pCur = p1;
				p1 = p1->next;
			}
			else
			{
				pCur->next = p2;
				pCur = p2;
				p2 = p2->next;	
			}
		}
		while (p1) 
		{
			pCur->next = p1;
			pCur = p1;
			p1 = p1->next;
		}
		while (p2)
		{
			pCur->next = p2;
			pCur = p2;
			p2 = p2->next;
		}
		pCur->next = NULL;
		return phead;
	}
};

#endif


#if 0
 struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* partition(ListNode *head, int x) {

		if (!head || !head->next)
			return head;
		ListNode*  n1 = new ListNode(0);
		ListNode*  n2 = new ListNode(0);
		ListNode *pLess  = n1;
		ListNode *pGreat = n2;
		ListNode *pCur   = head;
		

		while (pCur)
		{
			if (pCur->val < x)
			{
				pLess->next = pCur;
				pLess = pCur;
			}
			else
			{
				pGreat->next = pCur;
				pGreat = pCur;
			}
			pCur = pCur->next;
		}

		pGreat->next = NULL;
		pLess->next = n2->next;

		return n1->next;
	}
};

#endif
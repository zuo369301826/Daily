#include <iostream>
using namespace std;

#if 0
//一个链表带环，找出入环点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};

class Solution {
public:
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		ListNode *p1 = pHead;
		ListNode *p2 = pHead;

		while (p2 && p2->next) 
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2)
				break;
		}
		if (p2 == NULL || p2->next == NULL)
			return NULL;
		
		ListNode *p3 = pHead;

		while (p3 != p1)
		{
			p3 = p3->next;
			p1 = p1->next;
		}
		return p1;
	}
};

int main()
{
	ListNode h0(0);
	ListNode h1(1);
	ListNode h2(2);
	ListNode h3(3);
	ListNode h4(4);
	ListNode h5(5);
	ListNode h6(6);
	ListNode h7(7);
	ListNode h8(8);

	h0.next = &h1;
	h1.next = &h2;
	h2.next = &h3;
	h3.next = &h4;
	h4.next = &h5;
	h5.next = &h6;
	h6.next = &h7;
	h7.next = &h8;
	
	h8.next = &h4;


	Solution s;
	ListNode *h = s.EntryNodeOfLoop(&h0);

	if (h)
		cout << h->val << endl;

	system("pause");
	return 0;
}

#endif


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};

class Solution {
public:
	ListNode * deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode * pPre = pHead;

		ListNode * pCur = pHead;
		ListNode * pNext = pHead->next;

		while (pNext)
		{
			if (pCur->val == pNext->val)
			{
				pHead = pNext->next;
				pPre = pHead;
				//delete pCur;
				while (pNext->next != NULL && pNext->val == pNext->next->val) {
					pCur = pNext;
					pNext = pNext->next;
					//delete pCur;
				}
				//delete pNext;
				if (pHead)
				{
					pCur = pHead;
					pNext = pHead->next;
				}
				else
					return pHead;
			}
			else
			{
				pCur = pNext;
				pNext = pNext->next;
				break;
			}
		}

		while (pNext)
		{
			if (pCur->val == pNext->val)
			{
				pPre->next = pNext->next;
				//delete pCur;
				while (pNext->next != NULL && pNext->val == pNext->next->val) {
					pCur = pNext;
					pNext = pNext->next;
					pPre->next = pNext->next;
					//delete pCur;
				}
				//delete pNext;

				pCur = pPre->next;
				if (pCur)
				{
					pNext = pCur->next;
				}
				else return pHead;
			}
			else
			{
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			}
		}

		return pHead;
	}
}; 

//int main()
//{
//	ListNode h0(3);
//	ListNode h1(3);
//	ListNode h2(4);
//	ListNode h3(4);
//	ListNode h4(4);
//	ListNode h5(5);
//	ListNode h6(5);
//	ListNode h7(5);
//	ListNode h8(5);
//
//	h0.next = &h1;
//	h1.next = &h2;
//	h2.next = &h3;
//	h3.next = &h4;
//	h4.next = &h5;
//	h5.next = &h6;
//	h6.next = &h7;
////	h7.next = &h8;
//
//	ListNode *h = &h0;
//	while (h)
//	{
//		cout << h->val << " - ";
//		h = h->next;
//	}
//	cout << endl;
//
//	Solution s;
//	h = s.deleteDuplication(&h0);
//
//	
//	while (h)
//	{
//		cout << h->val << " - ";
//		h = h->next;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

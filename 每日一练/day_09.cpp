#include <iostream>
#include <vector>
using namespace std;


#if 0
//1.逆序打印单链表  通过
struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {		
		vector<int> arr;
		Fun(head, arr);
		return arr;
	}
	void Fun(ListNode* head, vector<int> &arr)
	{
		if (head)
		{
			if (head->next != NULL)
				Fun(head->next, arr);
			arr.push_back(head->val);
		}
	}
};

//int main()
//{
//	Solution l;
//	int n = 10;
//	ListNode* head = new ListNode(n);
//	ListNode* pCur = head;
//	while (n--)
//	{
//		pCur->next = new ListNode(n);
//		pCur = pCur->next;
//	}
//	vector<int> arr = l.printListFromTailToHead(head);
//
//	for (int i = 0; i < arr.size(); i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	ListNode* pDel=head;
//	while (head != NULL)
//	{
//		head = head->next;
//		delete pDel;
//		pDel = head;
//	}
//
//	system("pause");
//	return 0;
//}

#endif


//复杂链表的拷贝
//struct RandomListNode {
//	int label;
//	struct RandomListNode *next, *random;
//	RandomListNode(int x) :
//		label(x), next(NULL), random(NULL) {
//		}
//};
//
//class Solution {
//public:
//	RandomListNode * Clone(RandomListNode* pHead)
//	{
//		if (pHead == NULL)
//			return NULL;
//
//		RandomListNode *ret = pHead;
//		RandomListNode *pCur = pHead;
//		RandomListNode *pPre = pHead;
//		RandomListNode *pNext = pHead;
//		RandomListNode *pNew = NULL;
//		
//		while (pCur != NULL)
//		{
//			pNew = new RandomListNode(pCur->label);
//			pNew->next = pCur->next;
//			pCur->next = pNew;
//			pCur = pNew->next;
//		}
//
//		pCur = pHead;
//		while (pCur != NULL)
//		{
//			pCur = pCur->next;
//			if (pPre->random)
//				pCur->random = pPre->random->next;
//			pCur = pCur->next;
//			pPre = pCur;
//		}
//
//
//		pCur = pHead;
//		pPre = pHead;
//		ret = ret->next;
//		while (pCur != NULL)
//		{
//			pCur = pCur->next;
//			pNext = pCur->next;
//			if(pNext)
//				pCur->next = pNext->next;
//			pCur = pNext;
//
//			pPre->next = pNext;
//			pPre = pNext;
//		}
//		return ret;
//	}
//};
//
//
//int main()
//{
//	Solution solu;
//	RandomListNode h1(1);
//	RandomListNode h2(2);
//	RandomListNode h3(3);
//	RandomListNode h4(4);
//	RandomListNode h5(5);
//
//	h1.next = &h2;
//	h2.next = &h3;
//	h3.next = &h4;
//	h4.next = &h5;
//
//	h1.random = &h4;
//	h2.random = &h5;
//	h3.random = &h3;
//	h4.random = &h1;
//	h5.random = NULL;
//
//
//	RandomListNode* head = solu.Clone(&h1);
//
//	system("pause");
//	return 1;
//}
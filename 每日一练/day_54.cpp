#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) 
	{}
};
class Solution {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		while (p1 && (k-- != 0))
			p1 = p1->next;
		
		if (k > 0)
			return NULL;
		
		while (p1)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
	ListNode * FindKthToTail2(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		int count = 0;
		ListNode* p = pListHead;
		while (p)
		{
			p = p->next;
			count++;
		}
		if (count < k)
			return NULL;
		p = pListHead;
		for (int i = 0; p && (i < count - (int)k); i++)
		{
			p = p->next;
		}
		return p;
	}
};

int main()
{
	ListNode p(6);
	ListNode* cur = &p;
	ListNode* cur2 = NULL;
	
	cur->next = new ListNode(5);
	cur = cur->next;
	cur->next = new ListNode(4);
	cur = cur->next;
	cur->next = new ListNode(3);
	cur = cur->next;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(1);
	cur = cur->next;

	Solution s;
	cur = s.FindKthToTail(&p, 10);
	cur2 = s.FindKthToTail2(&p, 10);
	return 0;
 }
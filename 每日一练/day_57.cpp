
#include<iostream>
using namespace std;

 //判断链表是否带环
#if 0
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return true;
		ListNode *p1 = head;
		ListNode *p2 = head;
		p1 = p1;
		p2 = p2->next;
		while (p2 && p2->next)
		{
			if (p1 == p2)
				return true;
			p1 = p1->next;
			p2 = p2->next->next;			

		}
		return false;
	}
};
#endif


#if 0
//删除重复的数组
#include <map>
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
		if (NULL == pHead)
			return NULL;
		map<int, int> m;
		ListNode* cur = pHead;
		while (cur) 
		{
			++m[cur->val];
			cur = cur->next;
		}

		cur = pHead;
		while (cur && m[cur->val] > 1)
		{
			cur = cur->next;
		}
		if (cur == NULL)
			return NULL;
		ListNode* ret = cur;

		ListNode* next = cur->next;
		while (next)
		{
			if (m[next->val] == 1)
			{
				cur->next = next;
				cur = next;
			}
			next = next->next;
		}
		cur->next = NULL;
		return ret;
	}
};
#endif
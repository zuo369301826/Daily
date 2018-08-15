#include <iostream>
using namespace std;
#include <vector>
 
//Given a singly linked list L : L 0→L 1→…→L n - 1→L n,
//reorder it to : L 0→L n →L 1→L n - 1→L 2→L n - 2→…

#if 0
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head != NULL)
		{
			vector<int> arr;
			ListNode *cur = head->next;
			while (cur)
			{
				arr.push_back(cur->val);
				cur = cur->next;
			}
			cur = head->next;
			auto start = arr.begin();
			auto end = arr.end();
			--end;
			while (cur)
			{
				cur->val = *end--;
				cur = cur->next;
				if (cur)
				{
					cur->val = *start++;
					cur = cur->next;
				}
			}
		}
	}
};
#endif 


//在常量空间复杂度下，用O(nlog)对链表进行排序
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * sortList(ListNode *head) {
		if (head == NULL)
			return NULL;
		ListNode *p1;
		ListNode *p2;
		for (int n = 1; ; n*=2)
		{
			p1 = head;
			p2 = head + 1;
			while (p2)
			{
				
			}
		}
	}
};














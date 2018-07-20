//ÓÒĞıÁ´±í
#include<iostream>
using namespace std;

#if 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode *head, int k) {
		if (head == NULL)
			return NULL;
		int len = 0;

		ListNode *pCur = head;
		
		while (pCur)
		{
			len++;
			pCur = pCur->next;
		}

		if (len < 2)
			return head;
		
		k %= len;

		ListNode *pEnd  = head;
		ListNode *plast = head;
		while (k--)
		{
			plast = plast->next;
		}
		while (plast && plast->next)
		{
			plast = plast->next;
			pEnd = pEnd->next;
		}
		plast->next = head;
		
		ListNode *pNext = pEnd->next;
		pEnd->next = NULL;
		head = pNext;
		return head;
	}
};

#endif



struct ListNode {
    int val;
    ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * sortedListToBST(ListNode *head) {
		
		return ToBST(head, NULL);
	}

	TreeNode* ToBST(ListNode *head, ListNode *tail)
	{
		if (head == tail)
			return NULL;

		ListNode *p1 = head;
		ListNode *p2 = head;
		while (p2 != tail && p2->next != tail)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}

		TreeNode* root = new TreeNode(p1->val);

		root->left = ToBST(head, p1);
		root->right = ToBST(p1->next, tail);

		return root;
	}

};

//class Solution {
//public:
//	TreeNode * sortedListToBST(ListNode *head) {
//		return BST(head, NULL);
//	}
//	TreeNode *BST(ListNode *head, ListNode *tail)
//	{
//		if (head == tail)
//			return NULL;
//		ListNode *s = head;
//		ListNode *f = head;
//		while (f != tail && f->next != tail)
//		{
//			s = s->next;
//			f = f->next->next;
//		}
//		TreeNode *root = new TreeNode(s->val);
//		root->left = BST(head, s);
//		root->right = BST(s->next, tail);
//
//		return root;
//	}
//};
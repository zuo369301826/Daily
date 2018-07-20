#include <iostream>
using namespace std;

#if 0
/*   删除倒数第n个结点      */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL && head->next == NULL)
			return NULL;
		if (n <= 0)
			return head;
		ListNode *pCur = head;
		ListNode *pPre = head;

		int len = 0;
		while (pCur)
		{
			len++;
			pCur = pCur->next;
		}
		pCur = head;

		if (n == len)
		{
			head = head->next;
			//delete pCur;
		}

		while (n-- > 0)
		{
			if(pCur->next)
				pCur = pCur->next;
			else return head;
		}
			
		
		while (pCur->next)
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}

		pCur = pPre->next;
		pPre->next = pCur->next;
		//delete pCur;

		return head;
	}
};

int main()
{
	ListNode h1(1);
	ListNode h2(2);
	ListNode h3(3);
	ListNode h4(4);
	ListNode h5(5);
	
	h1.next = &h2;
	h2.next = &h3;
	h3.next = &h4;
	h4.next = &h5;

	ListNode *p=&h1;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	Solution s;
	p = s.removeNthFromEnd(&h1,5);

	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("pause");
	return 0;
}

#endif
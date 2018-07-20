#include <iostream>

using namespace std;

//求链表倒数第K个结点
typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) 
	{}
}N;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k<0 )
		return NULL;

	ListNode* right = pListHead;
	ListNode* left  = pListHead;

	while (--k)
	{
		if (right != NULL && right->next != NULL)
			right = right->next;
		else
			return NULL;
	}

	while (right->next != NULL)
	{
		left  = left->next;
		right = right->next;
	}
	return left;
}

//int  main()
//{
//	N* p = new N(10);
//	N* pCur = p;
//	for (int i = 9; i > 0; i--)
//	{
//		pCur->next = new N(i);
//		pCur = pCur->next;
//	}
//
//	N* ret = FindKthToTail(p, 5);
//	cout << ret->val << endl;
//
//	while (p != NULL)
//	{
//		pCur = p;
//		p = p->next;
//		delete pCur;
//	}
//
//	system("pause");
//	return 0;	
//}

/* 求连续子数组的最大和 */

//int main()
//{
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	int max = arr[0];
//	int count = 0;
//	int j = 0;
//	for (int gep = 0; gep < n; gep++)
//	{
//		for (int i = 0; i < n-gep; i++)
//		{
//			count = arr[i];
//			j = i;
//
//			while (++j <= i+gep)
//				count += arr[j];
//			if (count > max)
//				max = count;
//		}
//	}
//
//	cout << max << endl;
//	
//	system("pause");
//	return 0;
//}
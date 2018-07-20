#include <iostream>
using namespace std;

#if 0
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length == 0)
			return false;
		char* count = new char[length];
		for (int i = 0; i < length; i++)
			count[i] = 0;

		for (int i = 0; i < length; i++)
		{
			if (count[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			else
				count[numbers[i]] = true;
		}
		return false;
	}
};

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
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || NULL == pHead2)
			return NULL;
		else if (pHead1 == pHead2)
			return pHead1;

		ListNode * pCur = pHead1;
		int len1 = 0;
		int len2 = 0;
		while (pCur)
		{
			len1++;
			pCur = pCur->next;
		}
		pCur = pHead2;
		while (pCur)
		{
			len2++;
			pCur = pCur->next;
		}

		if (len1 > len2)
		{
			int num=len1-len2;
			while (num--)
				pHead1 = pHead1->next;
		}
		else
		{
			int num = len2 - len1;
			while (num--)
				pHead2 = pHead2->next;
		}

		while (pHead1 && pHead2)
		{
			if (pHead1 == pHead2)
				return pHead1;
			else
			{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
		}
		return NULL;
	}
};
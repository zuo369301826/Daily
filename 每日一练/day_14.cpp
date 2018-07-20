#include <iostream>
using namespace std;

#if 0
/**
*	�������Ұ����ķ�ʽ������ϵ�����
*	���룺һ���������ͷ�ڵ�head
*	�������������ĿҪ�������
*
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	void relocateList(struct ListNode* head) {
		ListNode* pCur = head;
		int len = 0;
		while (pCur != NULL)
		{
			len++;
			pCur = pCur->next;
		}
		if (len < 3)
			return;
		int n = len / 2;

		ListNode* L_next = head;
		ListNode* L_end = head;
		ListNode* R_cur = NULL;
		ListNode* R_next = head;
		
		for (int i = 1; i < n; i++)
			L_end = L_end->next;
		R_next = L_end->next;


		for (int i = 0; i < n; i++)
		{
			pCur = L_next;
			L_next = pCur->next;
			R_cur = R_next;
			R_next = R_cur->next;
			L_end->next = R_next;
			R_cur->next = pCur->next;
			pCur->next = R_cur;
		}
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

	ListNode* pCur = &h1;
	while (pCur)
	{
		cout << pCur->val << "-";
		pCur = pCur->next;
	}
	
	cout << endl;

	Solution s;
	s.relocateList(&h1);

	pCur = &h1;
	while (pCur)
	{
		cout << pCur->val << "-";
		pCur = pCur->next;
	}

	system("pause");
	return 0;
}

#endif

//����������ת��Ϊ˫��ѭ������
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
		}
};

class Solution {
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pFirstNode;
		TreeNode* pLastNode;

		_Convert(pRootOfTree, pFirstNode, pLastNode);

		return pFirstNode;
	}
	void _Convert(TreeNode * pRoot, TreeNode * & pFirstNode, TreeNode * & pLastNode)
	{
		TreeNode * pFirst_Left, *pLast_Left, *pFirst_Rigth, *pLast_Rigth;
		if (pRoot == NULL)//����
		{
			pFirstNode = NULL;//�����ĵ�һ���ڵ�ΪNULL
			pLastNode = NULL;//���������һ���ڵ�ΪNULL
			return;
		}
		
		if (pRoot->left == NULL)
			pFirstNode = pRoot;//�����������ڣ���һ���ڵ����root
		else 
		{
			//����������
			_Convert(pRoot->left, pFirst_Left, pLast_Left);//��������������
			pFirstNode = pFirst_Left;//�����ĵ�һ���ڵ�����������ĵ�һ���ڵ�
			pRoot->left = pLast_Left;//���ӱ�������� -- �����������һ�����
			pLast_Left->right = pRoot;//ʹ�����������һ�����ָ��root 
		}

		if (pRoot->right == NULL)
			pLastNode = pRoot;//�����������ڣ����һ���ڵ����root
		else
		{
			//����������
			_Convert(pRoot->right, pFirst_Rigth, pLast_Rigth);//��������������
			pLastNode = pLast_Rigth;//���������һ���ڵ�������������һ���ڵ�
			pRoot->right = pFirst_Rigth;//����root���ұ�--��������һ���ڵ�
			pFirst_Rigth->left = pRoot;//��������һ���ڵ�ָ��root
		}
	}
};
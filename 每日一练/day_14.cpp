#include <iostream>
using namespace std;

#if 0
/**
*	按照左右半区的方式重新组合单链表
*	输入：一个单链表的头节点head
*	将链表调整成题目要求的样子
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

//搜索二叉树转化为双向循环链表
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
		if (pRoot == NULL)//空数
		{
			pFirstNode = NULL;//本树的第一个节点为NULL
			pLastNode = NULL;//本树的最后一个节点为NULL
			return;
		}
		
		if (pRoot->left == NULL)
			pFirstNode = pRoot;//左子树不存在，第一个节点就是root
		else 
		{
			//左子树存在
			_Convert(pRoot->left, pFirst_Left, pLast_Left);//继续处理左子树
			pFirstNode = pFirst_Left;//本树的第一个节点就是左子树的第一个节点
			pRoot->left = pLast_Left;//连接本树的左边 -- 左子树的最后一个结点
			pLast_Left->right = pRoot;//使左子树的最后一个结点指向root 
		}

		if (pRoot->right == NULL)
			pLastNode = pRoot;//右子树不存在，最后一个节点就是root
		else
		{
			//右子树存在
			_Convert(pRoot->right, pFirst_Rigth, pLast_Rigth);//继续处理右子树
			pLastNode = pLast_Rigth;//本树的最后一个节点就是右子树最后一个节点
			pRoot->right = pFirst_Rigth;//连接root的右边--右子树第一个节点
			pFirst_Rigth->left = pRoot;//右子树第一个节点指向root
		}
	}
};
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

#if 0
/* 1.二叉树层序遍历 */
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		
		vector<vector<int>> arr;
		if (pRoot == NULL)
			return arr;
		queue<TreeNode*> q;
		q.push(pRoot);

		int n1=1;
		int n2=0;
		int count = 1;
		int num = 0;
		arr.resize(count);

		TreeNode* pCur = NULL;

		while ( !q.empty() )
		{
			pCur = q.front();
			q.pop();
			n1--;
			if (pCur->left)
			{
				q.push(pCur->left);
				n2++;
			}
			if (pCur->right)
			{
				q.push(pCur->right);
				n2++;
			}
			arr[count - 1].push_back(pCur->val);

			if( n1 == 0 && n2 != 0)
			{
				count++;
				n1 = n2;
				n2 = 0;
				arr.resize(count);
			}
		}
		return arr;
	}
};

#endif


/*  二叉树的镜像  */
#if 0
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		TreeNode* p = mirror(pRoot);
		return cmp(p, pRoot);
	}
	//镜像
	TreeNode* mirror(TreeNode* pRoot)
	{
		if (pRoot)
		{
			TreeNode* p = new TreeNode(pRoot->val);
			p->left = mirror(pRoot->right);
			p->right = mirror(pRoot->left);
			return p;
		}
		else return NULL;
	}
	//比较
	bool cmp(TreeNode* p, TreeNode* pRoot)
	{
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		
		s1.push(p);
		s2.push(pRoot);
		TreeNode* p1;
		TreeNode* p2;

		while (!s1.empty() && !s2.empty())
		{
			p1 = s1.top();
			s1.pop();
			p2 = s2.top();
			s2.pop();
			if(p1!=NULL && p2!=NULL)
			{
				if (p1->val != p2->val)
					return false;
				s1.push(p1->right);
				s1.push(p1->left);
				s2.push(p2->right);
				s2.push(p2->left);
			}
			else if (p1 != NULL || p2 != NULL)
				return false;
		}
		if (s1.empty() && s2.empty())
			return true;
		else return false;	
	}
};

int main()
{
	Solution s;
	TreeNode n(0);
	TreeNode nL(1);
	TreeNode nR(1);
	TreeNode nLL(5);
	TreeNode nLR(5);
	TreeNode nRL(5);
	TreeNode nRR(5);

	n.left = &nL;
	n.right = &nR;

	nL.left = &nLL;
	nL.right = &nLR;

	nR.left = &nRL;
	nR.right = &nRR;
	if (s.isSymmetrical(&n))
		printf("是的\n");
	else printf("不是\n");
	system("pause");
	return 0;
}

#endif


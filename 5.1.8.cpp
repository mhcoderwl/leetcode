//判断两颗树是否相同,要求结构相同并且节点的值相同
#include<stack>
#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//迭代版
class Solution{
	bool IsSameTree(TreeNode *p,TreeNode *q){
		stack<TreeNode*> stk;
		stk.push(p);
		stk.push(q);
		while(!stk.empty()){
			p=stk.top();
			stk.pop();
			q=stk.top();
			stk.pop();
			if(!p&&!p)continue;
			if(!p||!q)return false;
			if(p->val!=q->val)return false;
			stk.push(p->left);
			stk.push(q->left);
			stk.push(p->right);
			stk.push(q->right);
		}
		return true;
	}
};
		


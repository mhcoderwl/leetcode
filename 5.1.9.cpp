//给一颗二插树,判断是不是对称的
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//迭代版
class Solution{
	bool IsSymmetirc(TreeNode* root){
		if(!root) return true;
		stack<TreeNode*> stk;
		stk.push(root->left);
		stk.push(root->right);
		while(!stk.empty()){
			auto p=stk.top();
			stk.pop();
			auto q=stk.top();
			stk.pop();
			if(!p&&!q)continue;
			if(!p||!q)return false;
			if(p->val!=q->val)return false;
			stk.push(p->left);
			stk.push(q->right);
			stk.push(p->right);
			stk.push(q->left);
		}
		return true;
	}
};


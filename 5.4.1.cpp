//给一个二叉树,找到他的最小深度//
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归版
class Solution{
public:
	int mindepth(TreeNode* root){
		return mindepth(root,false);
	}
	int mindepth(TreeNode* root,bool hasbrother){
		if(root==NULL)return hasbrother?INT_MAX:0;
		return min(mindepth(root->left,root->right!=NULL),mindepth(root->right,root->left!=NULL))+1;
		
	}
};

//迭代版:比递归版速度快,因为有剪枝//
class Solution{
public:
	int mindepth(TreeNode* root){
		int result=INT_MAX;
		stack<pair<TreeNode*,int> >  stk;
		stk.push(make_pair(root,1));
		while(!stk.empty()){
			auto p=stk.top();
			stl.pop();
		if(p->first->left==NULL&&p->first->right==NULL)
			result=min(result,p->second);
		if(result>p->second&&p->first->left!=NULL)
			stk.push(make_pair(p->first->left,p->second+1));
		if(result>p->second&&p->first->right!=NULL)
			stk.push(make_pair(p->first->right,p->second+1));
		}
		return result;
	}
};

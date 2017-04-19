//给一颗二叉树,判断有没有一条从根到叶子节点的路径和为给定的数值
//注:二叉树的数值可以为负数,用深搜不能剪枝
#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
	bool hasPathsum(TreeNode* root,int sum){
		if(root->left==NULL&&root->right==NULL)
			return root->val==sum;
		return hasPathsum(TreeNode* root->left,sum-root->val)||
			hasPathsum(TreeNode* root->right,sum-root->val);
	}
};

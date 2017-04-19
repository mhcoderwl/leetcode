//判断一个二叉树是不是平衡
#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//递归
class Solution{
	bool Isbalanced(TreeNode* root){
		return balancedHeight(root)>=0;
	}
	int balancedHeight(TreeNode* root){
		if(root==NULL)return 0;
		int left=balancedHeight(root->left);
		int right=balancedHeight(root->right);
		if(left<0||right<0||abs(left-right)>1)return -1;
		return max(left,right)+1;
	}
};


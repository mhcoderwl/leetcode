//给一颗二叉树,返回最大深度//
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
	int maxdepth(TreeNode* root){
		return max(maxdepth(root->left),maxdepth(root->right))+1;
	}
};

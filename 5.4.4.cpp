//给一个二叉树,返回所有从根到叶子节点路径和为给定数值的路径
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
	vector<vector<int> > pathsum(TreeNode* root,int sum){
		vector<vector<int> > result;
		vector<int> cur;
		if(root==NULL)return result;
		pathsum(TreeNode* root,sum,cur,result);
		return result;
	}
	void pathsum(TreeNode* root,int sum,vector<int>& cur,vector<vector<int> >& result){
		if(root==NULL)return;
		cur.push_back(root->val);
		if(root->left==NULL&&root->right==NULL){
				if(root->val==sum)
				result.push_back(cur);
		}
		pathsum(root->left,sum-root->val,cur,result);
		pathsum(root->right,sum-root->val,cur,result);
		cur.pop_back();

	}
};

		
			


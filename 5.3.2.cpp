//数值1-n的所有二叉查找树的结构
#include<iostream>
#include<vector>
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
	vector<TreeNode*> generateTrees(int n){
		return generate(1,n);
	}
	vector<TreeNode*> generate(int m,int n){
		vector<TreeNode*> result;
		if(m>n){
			result.push_back(NULL);
			return result;
		}
		for(int i=m;i<=n;i++){
			auto leftsub=generate(m,i-1);
			auto rightsub=generate(i+1,n);
		for(auto leftroot:leftsub)
		for(auto rightroot:rightsub){
			TreeNode* root=new TreeNode(i);
			root->left=leftroot;
			root->right=rightroot;
			result.push_back(root);
		}
		return result;
	}
};





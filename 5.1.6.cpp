//二叉树的zigzag型层次遍历
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归版
class Solution{
	vector<vector<int> > zigzaglevelOrder(TreeNode* root){
		vector<vector<int> > result;
		traverse(root,1,result,true);
		return result;
	}
	void traverse(TreeNode* root,size_t level,vector<vector<int> > result,bool left_to_right){
		if(root==NULL)
			return;
		if(level>result.size())
			result.push_back(vector<int>());
		if(left_to_right)
			result[level-1].push_back(root->val);
		else
			result[level-1].insert(result[level-1].begin(),root->val);
		traverse(root->left,level+1,result,!left_to_right);
		traverse(root->right,level+1,result,!left_to_right);
	}
};

int main(){
}
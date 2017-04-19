//证实一个二叉树为BST
#include<iostream>
#include<limits.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
	bool IsBST(TreeNode* root){
		return IsBST(root,INT_MIN,INT_MAX);
	}
	bool IsBST(TreeNode* root,int lower,int upper){
		if(root==NULL)return true;
		return root->val>lower&&root->val<upper&&IsBST(root->left,lower,root->val)&&IsBST(root->right,root->val,upper);
	}
};
		
int main(){
	Solution s;
	TreeNode* root=new TreeNode(2);
	root->left=new TreeNode(4);
	root->right=new TreeNode(3);
	if(s.IsBST(root))
		cout<<"yes"<<endl;
}

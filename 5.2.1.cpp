//给一颗二叉树的先序遍历和中序遍历.重构二叉树
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
	TreeNode* BuildTree(vector<int>& preorder,vector<int>& inorder){
		return BuildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
	}
	TreeNode* BuildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last,vector<int>::iterator in_first,vector<int>::iterator in_last){
		if(pre_first==pre_last)return NULL;
		if(in_first==in_last)return NULL;
		TreeNode* root=new TreeNode(*pre_first);
		auto inroot=find(in_first,in_last,*pre_first);
		auto leftsize=distance(in_first,inroot);
		root->left=BuildTree(next(pre_first),next(pre_first)+leftsize,in_first,inroot);
		root->right=BuildTree(next(pre_first)+leftsize,pre_last,next(inroot),in_last);
		return root;
	}
};

int main(){
	Solution s;
	vector<int>a={1,2,3,4};
	vector<int>b={2,1,4,3};
	TreeNode* root=s.BuildTree(a,b);
	cout<<root->val;
	cout<<root->left->val;
	cout<<root->right->val;
	cout<<root->right->left->val;
	cout<<endl;
}

//给定中序和后序遍历,重建二叉树//
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
public:
	TreeNode* BuildTree(vector<int>& inorder,vector<int>& postorder){
		return BuildTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
	}
template<typename T>
	TreeNode* BuildTree(T in_first,T in_last,T post_first,T post_last){
		if(in_first==in_last)return NULL;
		if(post_first==post_last)return NULL;
		TreeNode* root=new TreeNode(*prev(post_last));
		auto rootpos=find(in_first,in_last,*prev(post_last));
		auto length=distance(in_first,rootpos);
		root->left=BuildTree(in_first,rootpos,post_first,post_first+length);
		root->right=BuildTree(next(rootpos),in_last,post_first+length,prev(post_last));
		return root;
	}
};

int main(){
	Solution s;
	vector<int> a={2,1,3};
	vector<int> b={2,3,1};
	auto root=s.BuildTree(a,b);
	cout<<root->val;
	cout<<root->left->val;
	cout<<root->right->val;
	cout<<endl;
}


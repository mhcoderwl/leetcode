//将二叉树拉平变成链表
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归版
class Solution{
public:
	void flattenTree(TreeNode* root){
		if(root==NULL) return;
		flattenTree(root->left);
		flattenTree(root->right);
		if(root->left==NULL)return;
		//将左子树插入到根节点和右子树之间
		TreeNode *p=root->left;
		while(p->right!=NULL)
			p=p->right;
		p->right=root->right;
		root->right=root->left;
		root->left=NULL;
	}
};
//迭代版
class Solution{
public:
	void flattenTree(TreeNode* root){
		if(root==NULL)return;
		stack<TreeNode*> stk;
		stk.push(root);
		while(!stk.empty()){
			TreeNode *p=stk.top();
			stk.pop();
			if(p->right!=NULL)stk.push(p->right);
			if(p->left!=NULL)stk.push(p->left);
			p->left=NULL;
			if(!stk.empty())
			p->right=stk.top();










int main(){
	TreeNode root(1);
	root.left=new TreeNode(2);
	root.right=new TreeNode(3);
	Solution s;
	s.flattenTree(&root);
	cout<<root.val<<' ';
	cout<<root.right->val<<' ';
	cout<<root.right->right->val<<endl;
}

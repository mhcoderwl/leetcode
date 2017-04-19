/*给一颗二叉树,先序遍历.*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//第一种方法:用栈实现,类似于递归算法(递归栈帧)
/*
class Solution{
	vector<int> PreorderTraversal(TreeNode* root){
		vector<int> result;
		stack<const TreeNode*> s;
		if(root!=NULL) s.push(root);
		while(!s.empty()){
			const p=s.top();
			s.pop();
			result.push_back(p->val);
			if(p->right!=NULL)s.push(p->right);
			if(p->left!=NULL)s.push(p->left);
		}
		return result;
	}
};
*/
//第二种方法:Morris先序遍历
class Solution{
public:
	vector<int> PreorderTraversal(TreeNode* root){
		TreeNode* cur=root;
		TreeNode* prev;
		vector<int> result;
		while(cur!=NULL){
			if(cur->left==NULL){
				result.push_back(cur->val);
				cur=cur->right;
			}
			else {
				prev=cur->left;
				while(prev->right!=NULL&&prev->right!=cur)
					prev=prev->right;
				if(prev->right==cur){
				prev->right=NULL;
				cur=cur->right;
				}else if(prev->right==NULL){
					result.push_back(cur->val);
					prev->right=cur;
					cur=cur->left;
				}
			}
		}
		return result;
	}

};
				
int main(){
	Solution s;
	TreeNode root(1);
	root.left=new TreeNode(2);
	root.left->right=new TreeNode(5);
	root.right=new TreeNode(3);
	root.left->left=new TreeNode(4);
	auto result=s.PreorderTraversal(&root);
	for(auto val:result)
		cout<< val<<' ';
	cout<<endl;
}
			
			


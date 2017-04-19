//连接一颗二叉树的每层节点//
#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next;
	TreeNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};

class Solution{
	void connect(TreeNode* root){
		TreeNode dummy(-1);
		auto prev=&dummy;
		TreeNode* cur;
		for(cur=root;cur!=NULL;cur=cur->next){
			if(cur->left!=NULL){
				prev->next=cur->left;
				prev=prev->next;
			}
			if(cur->right!=NULL){
				prev->next=cur->right;
				prev=prev->next;
			}
		}
		connect(dummy.next);
	}
};

int main(){}
				

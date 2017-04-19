//将二叉树每层的节点向右连接成一个链表.
//思路1:每层节点的深度相同,可以用广搜.但空间复杂度O(n)
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode* next;
	TreeNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};
//广搜(层次遍历)
class Solution{
public:
	void connect(TreeNode* root){
		if(root==NULL) return;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			while(q.front()!=NULL){
				TreeNode *p=q.front();
				q.pop();
				p->next=q.front();
				if(p->left!=NULL)q.push(p->left);
				if(p->right!=NULL)q.push(p->right);
			}
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
	}
};
//递归
class Solution{
public:
	void connect(TreeNode* root){
		if(root==NULL)return;
		TreeNode dummy(-1);
		for(TreeNode *cur=root,*prev=&dummy;cur!=NULL;cur=cur->next){
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



int main(){
	Solution s;
	TreeNode root(1);
	root.left=new TreeNode(2);
	root.right=new TreeNode(3);
        s.connect(&root);	
	cout<<root.left->next->val<<endl;
}
			
			
			



/*一个BST的某两个值交换了,找到并恢复
 * 思路:中序遍历,然后找遍历后的数组中逆序的位置,先从前往后找到位置1,然后从后往前找到位置2,交换两个指针的值.
 * 另外,想要原址用Morris遍历*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),let(NULL),right(NULL){}
};
class Solution{
	void recoverBST(TreeNode* root){
		TreeNode *cur=root;
		TreeNode *prev=NULL;
		pair<TreeNode*,TreeNode*> broken;
		while(cur!=NULL){
			if(cur->left==NULL){
				detect(broken,prev,cur);
				prev=cur;
				cur=cur->right;
			}else{
				auto node=cur->left;
				while(node->right!=NULL&&node->right!=cur)
					node=node->right;
				if(node->right==NULL){
					node->right=cur;
					cur=cur->left;
				}else{
					detect(broken,prev,cur);
					node->right=NULL;
					prev=cur;
					cur=cur->right;
				}
			}
		}
		swap(broken.first->val,broken.second->val);
	}

	void detect(pair<TreeNode*,TreeNode*> broken,TreeNode* prev,TreeNode* cur){
		if(prev!=NULL&&prev->val>cur->val){
			if(broken.first==NULL){
				broken.first=prev;
			}else
				broken.second=current;
		}
	}
};

					



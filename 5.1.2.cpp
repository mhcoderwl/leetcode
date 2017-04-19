/*morris中序遍历*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
public:
	vector<int> InorderTraversal(TreeNode* root){
		TreeNode* prev=NULL;
		TreeNode* cur=root;
		vector<int> result;
		while(cur!=NULL){
			if(cur->left==NULL){
				result.push_back(cur->val);
				cur=cur->right;
			}else{
				prev=cur->left;
				while(prev->right!=NULL&&prev->right!=cur)
					prev=prev->right;
				if(prev->right==NULL){
					prev->right=cur;
					cur=cur->left;
				}else{
					result.push_back(cur->val);
					prev->right=NULL;
					cur=cur->right;
				}
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	TreeNode root(1);
	root.right=new TreeNode(2);
	root.right->left=new TreeNode(3);
	auto p=s.InorderTraversal(&root);
	for(auto val:p)
		cout<<val<<' ';
	cout<<endl;
}
					



/*二叉树后序遍历*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//第一种栈实现
class Solution{
public:
	vector<int> postorderTraversal(TreeNode* root){
		stack<const TreeNode*> stk;
		vector<int> result;
		const TreeNode* p=root;
		const TreeNode* q=NULL;
		do{
			if(p!=NULL){
				stk.push(p);
				p=p->left;
				}
			q=NULL;
			while(!s.empty()){
				p=s.top();
				if(p->right==q){
					s.pop();
					result.push_back(p->val);
					q=p;
			}else{
				s.push(p);
				p=p->right;
				break;
			}
		}while(!stk.empty());
		return result;
	}
};

int main(){
	Solution s;
	TreeNode root(1);
	root.left=new TreeNode(2);
	root.right=new TreeNode(3);
	root.right->left=new TreeNode(4);
	root.left->left=new TreeNode(5);
	auto p=s.postorderTraversal(&root);
	for(auto val:p)
		cout<<val<<' ';
	cout<<endl;
}

				





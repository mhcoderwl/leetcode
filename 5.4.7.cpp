//二叉树只含0-9数值,.每一从根到叶子节点路径代表一个数,求所有数的和//
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
	int sumPathNum(TreeNode* root){
		int result=0;
		int cur=0;
		sumPathNum(root,cur,result);
		return result;
	}
	void sumPathNum(TreeNode* root,int& cur,int& result){
		if(root==NULL)return;
		cur=cur*10+root->val;
		if(root->left==NULL&&root->right==NULL)
			result+=cur;
		sumPathNum(root->left,cur,result);
		sumPathNum(root->right,cur,result);
		cur=(cur-root->val)/10;
	}
};
int main(){
	Solution s;
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	cout<<s.sumPathNum(root)<<endl;
			
}


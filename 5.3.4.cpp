// 给一个升序数组,构建一个高平衡BST
// 思路:二分法
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
	TreeNode* BuildBST(vector<int>& nums){
		return BuildBST(nums.begin(),nums.end());
	}
template<typename Iterator>
	TreeNode* BuildBST(Iterator begin,Iterator end){
		if(begin==end)return NULL;
		auto mid=begin+distance(begin,end)/2;
		TreeNode* root=new TreeNode(*mid);
		root->left=BuildBST(begin,mid);
		root->right=BuildBST(next(mid),end);
		return root;
	}
};

int main(){
	Solution s;
	vector<int> a={1,2,3};
	auto root=s.BuildBST(a);
	cout<<root->val<<' ';
	cout<<root->left->val<<' ';
	cout<<root->right->val;
	cout<<endl;
}
	

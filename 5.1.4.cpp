/*二叉树的层次遍历*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归版.
class Solution1{
public:
	vector<vector<int> > levelOrder(TreeNode* root){
		vector<vector<int> > result;
		traverse(root,1,result);
		return result;
	}

	void traverse(TreeNode* root,size_t level,vector<vector<int> >& result){
		if(!root) return;
		if(level>result.size())
			result.push_back(vector<int>());
		result[level-1].push_back(root->val);
		traverse(root->left,level+1,result);
		traverse(root->right,level+1,result);
	}
};

//迭代版1,用两个队列,一个用来存要输出的该行,一个用来存下一行.
class Solution2{
public:
	vector<vector<int> > levelOrder(TreeNode* root){
		vector<vector<int> > result;
		queue<TreeNode*> current,next;
		if(root==NULL)
			return result;
		else 
			current.push(root);
		while(!current.empty()){
			vector<int> level;
			while(!current.empty()){
				TreeNode* node=current.front();
				current.pop();
				level.push_back(node->val);
				if(node->left!=NULL)next.push(node->left);
				if(node->right!=NULL)next.push(node->right);
			}
			swap(current,next);
			result.push_back(level);
		}
		return result;
	}
};
//迭代版2,用一个队列,在要换行的地方插入一个标记符,遍历时可以用来换行(本质上与1相同)
class Solution3{
public:
	vector<vector<int> > levelOrder(TreeNode* root){
		vector<vector<int> > result;
		queue<TreeNode*> q;
		TreeNode *ptr=new TreeNode(-1);
		if(!root)
			return result;
		else{
			q.push(root);
			q.push(ptr);
		}
		while(!q.empty()){
			vector<int> level;
			while(q.front()!=ptr){
				TreeNode* node=q.front();
				q.pop();
				level.push_back(node->val);
				if(node->left!=NULL)q.push(node->left);
				if(node->right!=NULL)q.push(node->right);
				}
			result.push_back(level);
			q.pop();
			if(q.empty())
				break;
			else
				q.push(ptr);
		}
		delete ptr;
		return result;
	}
};
			
			
		
//测试主函数
int main(){
	Solution1 s1;
	Solution2 s2;
	Solution3 s3;
	TreeNode p1(1);
	p1.left=new TreeNode(2);
	p1.right=new TreeNode(3);
	p1.left->right=new TreeNode(4);
	p1.right->right=new TreeNode(5);
	auto result1=s1.levelOrder(&p1);
	auto result2=s2.levelOrder(&p1);
	auto result3=s3.levelOrder(&p1);
	for(auto level:result1){
		for(auto val:level)
			cout<<val<<' ';
		cout<<endl;
	}
	for(auto level:result2){
		for(auto val:level)
			cout<<val<<' ';
		cout<<endl;
	}
	for(auto level:result3){
		for(auto val:level)
			cout<<val<<' ';
		cout<<endl;
	}
}
	


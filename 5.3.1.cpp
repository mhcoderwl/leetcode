//从1-n的n个数的二叉查找树有多少种结构
//思路:以某一个数为根节点,然后能够成的结构数为左子树的数量乘右子树的数量
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
	int numTrees(int n){
		vector<int> result(n+1,1);
		for(int i=2;i<n+1;i++){
			for(int j=0;j<i;j++)
				result[i]+=result[j]*result[i-j-1];
		}
		return result[n];
	}
};

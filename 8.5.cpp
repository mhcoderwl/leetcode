//返回从1-n的k个数的所有组合//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<vector<int>> combine(int n,int k){
		vector<vector<int>> result;
		vector<int> cur;
		dfs(result,cur,1,n,k);
		return result;

	}
	void dfs(vector<vector<int>>& result,vector<int> cur,int index,int n,int k){
		if(cur.size()==k){
			result.push_back(cur);
			return;
		}
		if(n-index+1<k-cur.size())
			return;
		dfs(result,cur,index+1,n,k);
		cur.push_back(index);
		dfs(result,cur,index+1,n,k);
		cur.pop_back();
	}
};
int main(){
	Solution s;
	auto result=s.combine(4,2);
	for(auto i:result){
		for(auto j:i)
			cout<<j<<' ';
		cout<<endl;
	}
}

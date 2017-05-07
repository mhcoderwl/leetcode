//给一组数和一个目标数,找到所有组合(可重复使用)加起来等于目标数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<vector<int>> cominationSum(vector<int> nums,int target){
		sort(nums.begin(),nums.end());
		vector<vector<int>> result;
		vector<int>cur;
		//dfs(nums,result,cur,0,0,target);
		dfs(nums,cur,result,target,0);
		return result;
	}

	void dfs(vector<int> &nums,vector<vector<int>> &result,vector<int> &cur,int step,int sum,int target){
		if(sum==target){
			result.push_back(cur);
			return;
		}
		if(step==nums.size()||sum>target)
			return;
		dfs(nums,result,cur,step+1,sum,target);
		int count=0;
		while(sum<target){
			cur.push_back(nums[step]);
			sum+=nums[step];
			dfs(nums,result,cur,step+1,sum,target);
			count++;
		}
		for(;count>0;count--)
			cur.pop_back();
	}
	void dfs(vector<int>& nums,vector<int>& path,vector<vector<int>>& result,int gap,int start){
		if(gap==0){
			result.push_back(path);
			return;
		}
		int previous=-1;
		for(int i=start;i<nums.size();i++){
			if(previous==nums[i])continue;

			if(gap<nums[i])return;
			previous=nums[i];
			path.push_back(nums[i]);
			dfs(nums,path,result,gap-nums[i],i+1);
			path.pop_back();
		}
	}
};
int main(){
	Solution s;
	vector<int> nums={10,1,2,7,6,1,5};
	int target=8;
	auto result=s.cominationSum(nums,target);
	for(auto i:result){
		for(auto j:i)
			cout<<j<<' ';
		cout<<endl;
	}
}


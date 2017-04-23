//给一个数组没有重复数字,返回它所有的子数组(子数组非降序)//
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//深搜
class Solution{
public:
	vector<vector<int>> subsets(vector<int>& nums){
		set<vector<int>> result;
		vector<int> cur;
		subsets(nums,cur,result,0);
		vector<vector<int>> real_result;
		copy(result.begin(),result.end(),back_inserter(real_result));
		return real_result;
	}
	void subsets(vector<int>& nums,vector<int>& cur,set<vector<int>>& result,int step){
		if(step==nums.size()){
			result.insert(cur);
			return;
		}
		subsets(nums,cur,result,step+1);
		cur.push_back(nums[step]);
		subsets(nums,cur,result,step+1);
		cur.pop_back();
	}
};



int main(){
	Solution s;
	vector<int> nums={1,2,2,3};
	auto result=s.subsets(nums);
	for(auto i:result){
		for(auto j:i)
			cout<<j<<' ';
		cout<<endl;
	}
}


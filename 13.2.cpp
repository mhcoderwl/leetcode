//最大连续子序列和
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
	int max_subsequence(vector<int>& nums){
		int sum=0;
		int result=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			result=max(result,sum);
			if(sum<0)
				sum=0;

		}
		return result;
	}
};
int main(){
	Solution s;
	vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
	cout<<s.max_subsequence(nums)<<endl;
}

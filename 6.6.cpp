//找到数组第一个丢失的正整数//
//思路:每个数回到自己对应的位置,相当于(极限情况的桶排序),终止条件无法交换
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int firstmissingpositive(vector<int>& nums){
		bucket_sort(nums);
		for(int i=0;i<nums.size();i++)
			if(nums[i]!=i+1)
				return i+1;
		return nums.size()+1;
	}
	void bucket_sort(vector<int>& nums){
		int n=nums.size();
		for(int i=0;i<n;i++)
			while(nums[i]!=i+1){
				if(nums[i]<=0||nums[i]>n)
					break;
				swap(nums[i],nums[nums[i]-1]);
			}
	}
};

int main(){
	Solution s;
	vector<int> nums={1,3,-2,0,4};
	cout<<s.firstmissingpositive(nums)<<endl;
}


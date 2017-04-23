//给一个数组(有重复),求所有的子数组(不能重复)//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//迭代
class Solution{
	vector<vector<int>> subsetsWithDup(vector<int>& nums){
		sort(nums.begin(),nums.end());



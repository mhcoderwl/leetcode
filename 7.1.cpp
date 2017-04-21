//给一组有序数组,找到目标数的start和end位置
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
	vector<int> searchRange(vector<int>& nums,int target){
	const int l=distance(nums.begin(),lower_bound(nums.begin(),nums.end(),target));
	const int u=distance(nums.begin(),prev(upper_bound(nums.begin(),nums.end(),target)));
	if(nums[l]!=target)
		return vector<int>{-1,-1};
	else return vector<int>{l,u};
	}

template<typename Iterator,typename T>
	Iterator upper_bound( Iterator first,Iterator last,T target){
		while(first!=last){
			auto mid=next(first,distance(first,last)/2);
			if(target>=*mid)first=next(mid);
			else last=mid;
		}
		return first;
	}
template<typename Iterator,typename T>
	Iterator lower_bound(Iterator first,Iterator last,T target){
		while(first!=last){
			auto mid=next(first,distance(first,last)/2);
			if(target>*mid)first=next(mid);
			else last=mid;
		}
		return first;
	}


};
int main(){
	Solution s;
	vector<int> nums={1,2,2,3};
	auto result=s.searchRange(nums,2);
	for(auto i:result)
	cout<<i<<' ';
	cout<<endl;
}	





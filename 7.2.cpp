//找到给定值在有序数组的位置,如果没有则返回插入的位置//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	int Inserpos(vector<int>& nums,int target){
		auto first=nums.begin();
		auto last=nums.end();
		while(first!=last){
			auto mid=next(first,distance(first,last)/2);
			if(target>*mid)first=next(mid);
			else if(target<*mid)last=mid;
			else return distance(nums.begin(),mid);
		}
		return distance(nums.begin(),first);
	}
};

int main(){
	Solution s;
	vector<int> nums={1,3,5};
	auto pos=s.Inserpos(nums,2);
	cout<<pos<<endl;
}

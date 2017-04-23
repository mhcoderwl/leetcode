//给一个数组,返回所有序列//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<vector<int>> permutation(vector<int>& nums){
		sort(nums.begin(),nums.end());
		vector<vector<int>> result;
		do{
			result.push_back(nums);
		}while(next_permutation(nums.begin(),nums.end()));
		return result;
	}
	
template<typename Iterator>
	bool next_permutation(Iterator first,Iterator last){
		auto rfirst=reverse_iterator<Iterator>(last);
		auto rlast=reverse_iterator<Iterator>(first);
		auto cur=next(rfirst);
		while(*cur>*prev(cur)&&cur!=rlast)cur=next(cur);
		if(cur==rlast)return false;
		auto change=find_if(rfirst,cur,bind1st(less<int>(),*cur));
		swap(*change,*cur);
		reverse(rfirst,cur);
		return true;
	}
};

int main(){
	Solution s;
	vector<int> nums={1,2,3,4};
	auto result=s.permutation(nums);
	for(auto i:result){
		for(auto j:i)
			cout<<j<<' ';
		cout<<endl;
	}
}



		
		

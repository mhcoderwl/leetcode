/*找到下一个比之前打的序列*/


#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;
class Solution{
public:
	void nextPermutation(vector<int>& nums){
	 nextpermutation(nums.begin(),nums.end());
	}
template<typename BidiIt>
	bool next_permutation(BidiIt first,BidiIt last){
		const auto rfirst=reverse_iterator<BidiIt>(first);
		const auto rlast=reverse_iterator<BidiIt>(last);
		auto pivot=next(rfirst);
		while(pivot!=rlast&&pivot>=*prev(pivot))
			pivot++;
		if(pivot==rlast){
			reverse(nums);
			return false;
		}
		swap(*pivot,*change);
		reverse(rfirst,pivot);
		return true;
	}
};

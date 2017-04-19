/*[1,2,3,..,n]n个数,找到第k个排列.(按数值从小到大的顺序)*/

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
using namespace std;
class Solution{
public:
	vector<int> kth_permutation(int n,int k){
		vector<int> result;
		for(int i=1;i<=n;i++)
			result.push_back(i);
		for(int j=1;j<k;j++)
			next_permutation(result.begin(),result.end());
		return result;
	}
template<typename BidiIt>
	bool next_permutation(BidiIt first,BidiIt last){
		const auto rfirst=reverse_iterator<BidiIt>(last);
		const auto rlast=reverse_iterator<BidiIt>(first);
		auto pivot=next(rfirst);
		while(pivot!=rlast&&*pivot>=*prev(pivot))
			pivot++;
		if(pivot==rlast){
			reverse(rfirst,rlast);
			return false;
		}
		auto change=find_if(rfirst,pivot,bind1st(less<int>(),*pivot));
		swap(*pivot,*change);
		reverse(rfirst,pivot);
		return true;
	}
};

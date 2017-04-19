//给定一组数值,找到其中三个数,和为0,按顺序排列并且不能重复出现.
//先排序,然后左右夹逼,时间复杂度O(n^2).
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class solution{
public:
vector< vector<int> > threeSum(vector<int>& nums,int target){
	vector< vector<int> > result;
	if(nums.size()<3)return result;
	vector<int>::iterator last=nums.end();
	vector<int>::iterator first=nums.begin();
	for(vector<int>::iterator i=first;i<last-2;i++){
		vector<int>::iterator j=i+1;
		vector<int>::iterator k=last-1;
		while(j<k){
			if(*i+*j+*k<target){
				j++;
				//while(*j==*(j-1)&&j<k)j++;
			}else if(*i+*j+*k>target){
				k--;
				//while(*k==*(k+1)&&j<k)k--;
			}else{
				vector<int> list;
				list.push_back(*i);
				list.push_back(*j);
				list.push_back(*k);
				result.push_back(list);
				j++;
				k--;
				//while(*j==*(j-1)&&*k==*(k+1)&&j<k)j++;
			}
		}
	}
	sort(first,last);
	result.erase(unique(result.begin(),result.end()),result.end());
	return result;
}
};




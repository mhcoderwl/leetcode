#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	void plus_one(vector<int>& nums){
		auto bits=nums.rbegin();
		while(bits!=nums.rend() && (*bits)==9){
			*bits=0;
			bits++;
		}
		if(bits==nums.rend()){
			nums.insert(bits.base(),1);
		}else (*bits)++;
	}
};
int main(){
	vector<int> a={9,9};
	Solution s;
	s.plus_one(a);
	for(auto num:a)
		cout<<num;
	cout<<endl;
}



/*N个加油站组成一个圈,返回能走一圈的加油站序号,输入耗油数组和加油数组.
 * 时间复杂度O(N)*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int cancomplete(vector<int>& gas,vector<int>& cost,int n){
		int sum=0;
		int total=0;
		int index=0;
		for(int i=0;i<n;i++){
			sum+=gas[i]-cost[i];
			total+=gas[i]-cost[i];
			if(sum<0){
				index=i;
				sum=0;
			}
		}
		return total>=0?index:-1;
	}
};


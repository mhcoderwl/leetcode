//一个数组只含0,1,2,排序
//思路:1.计数排序2.partition思想
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
	void sortColors(vector<int>& Colors){
		int count[3]={0};
		for(int i=0;i<Colors.size();i++)
			count[Colors[i]]++;
		for(int i=0,index=0;i<3;i++)
			for(int j=0;j<count[i];j++)
				Colors[index++]=i;
	}
};
			

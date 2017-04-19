/* 给一列数和一个指定的值,除去给定的数值然后返回新的长度
 * 算法复杂度O(n)
*/
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution{
public:
	int remove(vector<int>& input,int n){
		int index=0;
		for(auto i:input)
			if(i!=n)
				input[index++]=i;
	return index;
	}
};

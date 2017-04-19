/*一组整数每个数都出现三次除了莫一个数,找到这个数,要求原址,时间复杂度O(n)
 * 思路:每个数都出现三次,说明该数二进制每位的1的出现次数是3的整数倍,所以如果某一位的1的出现次数不为3的整数位,说明该位是那个数为1的部分.
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int single_number(vector<int>& nums){
		int bits=sizeof(int)*8;
		int result=0;
		vector<int> counts(bits,0);
		for(auto i:nums){
			for(int j=0;j<bits;j++){
				if((i>>j)%2!=0)
					counts[j]++;
			}
		}
		for(int i=0;i<bits;i++){
			if(counts[i]%3!=0)
			result+=(1<<i);
		}
		return result;
	}
};
int main(){
	Solution s;
	vector<int> a={3,3,3,4,5,4,4};
	cout<<s.single_number(a)<<endl;
}

/*给定一个柱状图,计算这些柱子之间的空隙的面积.柱子的宽度为1.
  例如:输入{0,1,0,2,1,0,1},返回2.   
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int trap(const vector<int>& elevation){
		const int n=elevation.size();
		vector<int> max_left(n,0);
		vector<int> max_right(n,0);
		for(int i=1;i<n;i++){
			max_left[i]=max(max_left[i-1],elevation[i-1]);
			max_right[n-1-i]=max(max_right[n-i],elevation[n-i]);
		}
		int sum=0;
		for(int i=1;i<n;i++){
			int height=min(max_left[i],max_right[i]);
			if(height>elevation[i])
				sum+=height-elevation[i];
		}
		return sum;
	}
};
int main(){
	vector<int> a={0,1,0,2,1,0,1};
	Solution s;
	cout<<s.trap(a)<<endl;
}


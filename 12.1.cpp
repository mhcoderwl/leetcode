//给一个数组,每个数字代表能跳的最长距离,返回是否能跳到最后的位置
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int minSteps(vector<int> steps){
		const int len=steps.size();
		int min_step=0;
		for(int i=0;i<len-1;){
			int max_len=0;
			int next=0;
			for(int j=1;j<=steps[i];j++){
				int max_steps=j+steps[i+j];
				if(max_len<max_steps){
					max_len=max_steps;
					next=j;
				}
			}
			if(next==0)
				return -1;
			i+=next;
			min_step++;
			
		}
		return min_step;
	}
};
int main(){
	Solution s;
	vector<int> steps={2,3,1,1,4};
	cout<<s.minSteps(steps)<<endl;
}	

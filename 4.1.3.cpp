/*给一个数组代表一个直方图,找到最大面积的矩形
 * 思路:用一个栈,如果当前高度小于栈顶,则处理掉所有比他大的元素然后入栈*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int LargestRectangleArea(vector<int>& height){
		stack<int> s;
		height.push_back(0);
		int result=0;
		for(int i=0;i<height.size();){
			if(s.empty()||height[s.top()]<height[i])
				s.push(i++);
			else{
				int tmp=s.top();
				s.pop();
				result=max(result,height[tmp]*(s.empty()?i:i-s.top()-1));
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	vector<int> height={2,1,5,6,2,3};
	cout<<s.LargestRectangleArea(height);
	cout<<endl;
	}

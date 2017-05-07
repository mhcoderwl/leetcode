//实现平方根函数sqrt(int x)//
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
	double mySqrt(int x){
		if(x<0)
			return -1;
		double start=1;
		double end=x;
		while(start!=end){
			double mid=start+(end-start)/2;
			if(abs(x/mid-mid)<0.00001)
				return mid;
			else if(x/mid>mid)
				start=mid;
			else end=mid;
		}
	}
};

int main(){
	Solution s;
	cout<<s.mySqrt(5)<<endl;
}

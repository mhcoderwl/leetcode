//实现pow(x,n)
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution{
public:
	double myPow(double x,int n){
		if(n<0)
			return 1/Power(x,-n);
		else return Power(x,n);
	}
	double Power(double x,int n){
		if(n==0)return 1;
		double v=Power(x,n/2);
		if(n%2==0)return v*v;
		else return v*v*x;
	}
};
int main(){
	Solution s;
	cout<<s.myPow(3,-3)<<endl;
	cout<<pow(3,-3)<<endl;
}

//最多买卖两次,问最大利润//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
	int MaxProfit(vector<int>& prices){
		const int n=prices.size();
		int f[n];
		int g[n];
		int result=0;
		for(int i=1,valley=prices[0];i<n;i++){
			valley=min(valley,prices[i]);
			f[i]=max(f[i-1],prices[i]-valley);
		}
		for(int i=n-2,valley=prices[n-1];i>=0;i--){
			valley=max(valley,prices[i]);
			g[i]=max(valley-prices[i],g[i+1]);
		}
		for(int i=0;i<n;i++)
			result=max(result,f[i]+g[i]);
		return result;
	}
};
int main(){}

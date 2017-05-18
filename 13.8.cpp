//给一个m*n的数组,从左上到右下一条路径所有数的和最小//
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
	int minPathSum(vector<vector<int> >& grids){
		if(grids.empty())return 0;
		const int m=girds.size();
		const int n=grids[0].size();
		vector<int> f(n+1,INT_MAX);
		f[0]=0;
		for(int i=0;i<m;i++)
			for(int j=1;j<=n;j++)
				f[j]=min(f[j-1],f[j])+grids[i][j-1];
		return f[n];
	}
};



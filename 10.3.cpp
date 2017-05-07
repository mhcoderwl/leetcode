//给一个二维数组,从左上角到右下有多少种走法,中间为1的为路障不能走//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//DP
class Solution{
public:
	int uniquePaths(vector<vector<int>> obstacle){
		const int m=obstacle.size();
		const int n=obstacle[0].size();
		vector<vector<int>> result(m+1,vector<int>(n+1,0));
		for(int i=1;i<m+1;i++)
			for(int j=1;j<n+1;j++){
				if(obstacle[i-1][j-1]==1){
					result[i][j]=0;
				}else if(j==1&&i==1)
					result[i][j]=1;
				else
				result[i][j]=result[i-1][j]+result[i][j-1];
			}
		return result[m][n];
	}
};

int main(){
	Solution s;
	vector<vector<int>> result(3,vector<int>(3,0));
	result[1][1]=1;
	cout<<s.uniquePaths(result)<<endl;
}
		

//从一个m*n的数组左上角走到右下角有多少种走法//
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
//深搜
class Solution1{
	int uniquePaths(int m,int n){
		if(m<0||n<0)return 0;
		if(m==1||n==1)return 1;
		return uniquePaths(m-1,n)+uniquePaths(m,n-1);
	}
};

//深搜,加备忘录可以加速
class Solution2{
	int uniquePaths(int m,int n){
		vector<vector<int>> buffer(m,vector<int>(n,0));
		buffer[0][0]=1;
		return dfs(m-1,n-1,buffer);
	}
	int dfs(int x,int y,vector<vector<int>>& buffer){
		if(x<0||y<0)return 0;
		if(buffer[x][y]>0){
			return buffer[x][y];
		}else {
			return buffer[x][y]=(dfs(x-1,y,buffer)+dfs(x,y-1,buffer));
		}
	}
};
//DP
class Solution3{
public:
	int uniquePaths(int m,int n){
		vector<vector<int>> result(m+1,vector<int>(n+1,0));
		for(int i=1;i<m+1;i++)
			for(int j=1;j<n+1;j++){
				if(j==1&&i==1)
					result[i][j]=1;
				else
				result[i][j]=result[i-1][j]+result[i][j-1];

			}
		return result[m][n];
	}
};
int main(){
	Solution3 s;
	cout<<s.uniquePaths(2,2)<<endl;
}

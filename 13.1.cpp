//给一个三角形阵列,找到一条路从顶到底,并且和最小//
//例如:			2
//		       3 4
//		      6 5 7
//		     4 1 8 3
// 返回 11.(2+3+5+1=11)
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution{
public:
	int MinPath(vector<vector<int>>& triangle){
		const int n=triangle.size();
		int Min[n+1][n+1];
		fill_n(&Min[0][0],(n+1)*(n+1),0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
				if(j==1)
					Min[i][j]=Min[i-1][j]+triangle[i-1][j-1];
				else if(j==i)
					Min[i][j]=Min[i-1][j-1]+triangle[i-1][j-1];
				else
					Min[i][j]=min(Min[i-1][j-1],Min[i-1][j])+triangle[i-1][j-1];
		}
		int Min_path=INT_MAX;
		for(int i=1;i<n+1;i++){
			if(Min_path>Min[n][i])
				Min_path=Min[n][i];
		}
		return Min_path;
	}
};

int main(){
	Solution s;
	vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
	cout<<s.MinPath(triangle)<<endl;
}


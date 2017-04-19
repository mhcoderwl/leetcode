/*给一个矩阵,将每个值为零的元素的行和列上元素设0,最好空间复杂度O(1).
 * 我的想法是维护两个数组用来存放需要设为0的行和列.空间复杂度O(m+n).
 * O(1)需要复用第一行和第一列.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	void setzeroes(vector<vector<int> >& matrix){
		int m=matrix.size();
		int n=matrix[0].size();
		bool rows_zero=false;
		bool cols_zero=false;
		for(int i=0;i<m;i++)
			if(matrix[i][0]==0){
				rows_zero=true;
				break;
			}
		for(int i=0;i<n;i++)
			if(matrix[0][i]==0){
				cols_zero=true;
				break;
			}
		for(int i=1;i<m;i++)
			for(int j=1;j<n;j++)
				if(matrix[i][j]==0){
					matrix[0][j]=0;
					matrix[i][0]=0;
				}
		for(int i=1;i<m;i++)
			if(matrix[i][0]==0)
				fill(matrix[i].begin(),matrix[i].end(),0);
		for(int j=1;j<n;j++)
			if(matrix[0][j]==0)
				for(int i=0;i<m;i++)
					matrix[i][j]=0;
		if(rows_zero==true)
			for(int i=0;i<m;i++)
				matrix[i][0]=0;
		if(cols_zero==true)
			fill(matrix[0].begin(),matrix[0].end(),0);
	}
};

int main(){
	vector<vector<int> > a={{1,0,1},{2,3,4},{4,5,0}};
	Solution s;
	s.setzeroes(a);
	for(auto i:a){
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
}
	


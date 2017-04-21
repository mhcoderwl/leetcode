//给一个m*n矩阵,矩阵的值已经排序,返回是否有目标值
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	bool HasValue(vector<vector<int> > matrix,int target){
		int m=matrix.size();
		int n=matrix[0].size();
		int first=0;
		int last=m*n;
		while(first!=last){
			int mid=first+(last-first)/2;
			if(matrix[mid/m][mid%m]==target)
				return true;
			else if(matrix[mid/m][mid%m]<target){
				first=mid+1;
			}else last=mid;
		}
		return false;
	}
};
				
int main(){
	Solution s;
	vector<vector<int>> a={{1,3},{5,7},{9,10}};
	if(s.HasValue(a,4))	
		cout<<"true"<<endl;
	else cout<<"false"<<endl;
}





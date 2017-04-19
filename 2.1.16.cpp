/*给定一个n*n的矩阵,求矩阵旋转90度后的矩阵.要求原址.
  思路:中线折叠一次,然后对角线折叠.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<vector<int> > matrix;
class Solution{
public:
	matrix& rotation(matrix& image){
		int rows=image.size();
		int cols=image[0].size();
		for(int i=0;i<rows/2;i++)
			for(int j=0;j<cols;j++){
				swap(image[i][j],image[rows-1-i][j]);
			}
		for(int i=0;i<rows;i++)
			for(int j=i+1;j<cols;j++){
				swap(image[i][j],image[j][i]);
			}
		return image;
	}
};

int main(){
	matrix a={{1,2,3},{4,5,6},{7,8,9}};
	Solution s;
	s.rotation(a);
	for(auto i:a){
		for(auto j:i)
			cout<<j<<",";
		cout<<endl;
	}
}
	

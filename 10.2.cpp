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


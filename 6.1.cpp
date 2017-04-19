//给两个已经排序的数组,归并//
#include<iostream>
#include<vector>
using namespace std;

class Solution{
	void merge(vector<int>& A,vector<int>& B,int m,int n){
		int ia=m-1,ib=n-1,icur=m+n-1;
		while(ia>=0&&ib>=0)
			A[icur--]=A[ia]>B[ib]?A[ia--]:B[ib--];
		while(ib>=0)
			A[icur--]=B[ib--];
	}
};





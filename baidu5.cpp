#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int all_array(int n,int k){
	vector<vector<int>> count(n,vector<int>(n+1,0));
	for(int i=1;i<n+1;i++)
	count[0][i]=1;
	for(int i=1;i<k+1;i++){
		for(int j=i+1;j<n+1;j++){
			count[i][j]=(count[i][j-1]*(i+1)+count[i-1][j-1]*(j-i))%2017;
		}
	}
	return count[k][n];
}
int main(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	cout<<all_array(n,k);
}

		


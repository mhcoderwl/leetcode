#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int climbstairs(int n){
		int s1=1,s2=2,s3=0;
		for(int i=2;i<n;i++){
			 s3=s1+s2;
			 s1=s2;
			 s2=s3;
		}
		return s3;
	}
};

int main(){
	Solution s;
	cout<<s.climbstairs(5);
	cout<<endl;
}
	



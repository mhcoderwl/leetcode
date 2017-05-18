//给两个字符串,求从第一个变换到第二个的最小步骤
//3种支持的步骤:增删改一个字母
#include<iostream>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;
class Solution{
public:
	int stepsTransform(string& s1,string& s2){
		const int m=s1.length();
		const int n=s2.length();
		int upper_left=0;
		vector<int> f(n+1,INT_MAX);
		for(int i=0;i<m;i++){
			if(s1[0]==s2[0])
				f[0]=i;
			else f[0]=i+1;
			for(int j=1;j<n;j++){
				int temp=f[j];
				if(s1[i]==s2[j])
					f[j]=upper_left;
				else
					f[j]=min(f[j-1],f[j])+1;
				upper_left=temp;
			}
		}
		return f[n-1];
	}
};

int main(){
	Solution s;
	string s1="abc";
	string s2="adbc";
	cout<<s.stepsTransform(s1,s2)<<endl;
}

					

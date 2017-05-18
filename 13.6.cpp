//给三个字符串s1,s2,s3,判断s3是否由s1,s2,交叉构成.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
	bool InterleavingString(const string& s1,const string& s2,const string& s3){
		if(s3.length()!=s1.length()+s2.length())return false;
		const int m=s1.length();
		const int n=s2.length();
		bool result[m+1][n+1];
		fill_n(&result[0][0],(m+1)*(n+1),true);
		for(int i=1;i<m+1;i++)
			result[i][0]=result[i-1][0]&&s1[i]==s3[i];
		for(int i=1;i<n+1;i++)
			result[0][i]=result[0][i-1]&&s2[i]==s3[i];
		for(int i=1;i<m+1;i++)
			for(int j=1;j<n+1;j++)
				result[i][j]=(result[i][j-1]&&s2[j-1]==s3[i+j-1])||
					     (result[i-1][j]&&s1[i-1]==s3[i+j-1]);
		return result[m][n];
	}
};

int main(){
	Solution s;
	string s1="aabcc";
	string s2="dbbca";
	string s3="aadbbbaccc";
	if(s.InterleavingString(s1,s2,s3))
		cout<<"true"<<endl;
	else cout<<"false"<<endl;
}

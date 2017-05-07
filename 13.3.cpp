//给一个字符串,需要分割成子串,子串都为回文,求最小分割次数.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
	int minCut(string& s){
		const int n=s.length();
		bool p[n][n];
		int f[n+1];
		fill_n(&p[0][0],n*n,false);
		for(int i=0;i<n+1;i++)
			f[n]=n-1-i;
		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++){
				if(s[i]==s[j]&&(j-i<2||p[i+1][j-1])){
					p[i][j]=true;
					f[i]=min(f[i],f[j+1]+1);
				}
			}
		return f[0];
	}
};
				

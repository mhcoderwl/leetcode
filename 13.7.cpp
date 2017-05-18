//给两个字符串,判断是否为scramble string
//思路:判断某两个字符串,只要再每个中间部分切开交叉判断子部分是否为scramble.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	bool IsScramble(const string& s1,const string& s2){
		const int m=s1.length();
		const int n=s2.length();
		if(m!=n)return false;
		bool result[m+1][m][m];
		fill_n(&result[0][0][0],(m+1)*m*m,false);
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				result[1][i][j]=(s1[i]==s2[j]);
		for(int l=2;l<m+1;l++)
			for(int i=0;i<=m-l;i++)
				for(int j=0;j<=m-l;j++)
					for(int k=1;k<l;k++)
						if((result[k][i][j]&&result[l-k][i+k][j+k])||
						   (result[k][i][j+l-k]&&result[l-k][i+k][j])){
							result[l][i][j]=true;
							break;
						}
		return result[m][0][0];
	}
};

int main(){
	Solution s;
	string s1="great";
	string s2="rgtae";
	if(s.IsScramble(s1,s2))
		cout<<"true"<<endl;
	else cout<<"false"<<endl;
}


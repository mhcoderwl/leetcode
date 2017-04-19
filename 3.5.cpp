/*最长回文子串*/
#include<iostream>
#include<string>
using namespace std;

//第一种动态规划:时间复杂度O(n^2),空间复杂度O(n^2)
class Solution{
	string LongestPalindrome(const string& s){
		const int n=s.length();
		bool f[n][n];
		fill_n(f,n*n,false);
		int max_len=0,start=0;
		for(int i=0;i<n;i++){
			f[i][i]=true;
			for(int j=0;j<i;j++){
				f[j][i]=(s[i]=s[j]&&((i-j<2)||f[j+1][i-1]));
				if(f[j][i]&&max_len<i-j+1){
					max_len=i-j+1;
					start=j;
				}
			}
		}
		return s.substr(start,max_len);
	}
};

//第二种manacher's 算法
class Solution{
public:
//预处理,将字符串奇偶归一到奇数
	string PreProcess(const string& s){
		int n=s.length();
		if(n==0)return "^$";
		string ret="^";
		for(int i=0;i<n;i++){
			ret+="#"+s.substr(i,1);
		}ret+="#$";
		return ret;
	}

	string LongestPalindrome(string s){
		string T=PreProcess(s);
		const int n=T.length();
		int P[n];
		int C=0,R=0;//C是最右边回文串的中心位置,R是回文最右边的位置
		for(int i=1;i<n-1;i++){
			int i_mirror=2*C-i;
			P[i]=(R>i)?min(R-i,P[i_mirror]):0;
			while(T[P[i]+i+1]==T[i-P[i]-1])P[i]++;
			if(R<i+P[i]){
				C=i;
				R=i+P[i];
			}
		}
		int max_len=0;
		int center_index=0;
		for(int i=1;i<n-1;i++){
			if(P[i]>max_len){
				center_index=i;
				max_len=P[i];
			}
		}
		return s.substr((center_index-max_len-1)/2,max_len);
	}
};

int main(){
	string s1="abcbads";
	Solution s;
	string s2=s.LongestPalindrome(s1);
	cout<<s2<<endl;
}

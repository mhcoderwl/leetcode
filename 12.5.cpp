//在一个字符串里找到最长不含重复字母的子串//
//思路:从左往右扫描,遇到重复起始位置直接跳到重复的下一个字符//
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	int longestSubstring(string s){
		int max_len=0;
		int start=0;
		int last[255];
		fill_n(last,255,-1);
		for(int i=0;i<s.length();i++){
			if(last[s[i]]>=start){
				max_len=max(max_len,i-start);
				start=last[s[i]]+1;

			}
				last[s[i]]=i;
		
		}
		return max((int)s.size()-start,max_len);
	}
};
int main(){
	Solution s;
	string str="abbdd";
	cout<<s.longestSubstring(str)<<endl;
}

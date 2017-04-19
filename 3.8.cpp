/*给一列字符串,找到最大长度公共前缀*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
public:
	string LongestCommonPrefix(vector<string>& strs){
		string result=strs[0];
		for(auto begin=next(strs.begin());begin!=strs.end();begin++){
			string s=LongestCommonPrefix(strs[0],*begin);
			if(s.length()<result.length())
				result=s;
		}
		return result;
	}
	string LongestCommonPrefix(string s1,string s2){
		int len=0;
		for(int i=0;i<(s1.length()>s2.length()?s2.length():s1.length());i++){
			if(s1[i]!=s2[i])
				break;
			len++;
			
		}
		return s1.substr(0,len);
	}
};

int main(){
	Solution s;
	vector<string> strs={"abcde","abcd","abc"};
	cout<<s.LongestCommonPrefix(strs)<<endl;
}


/*给一个字符串只包含'('和')',返回有效子串的最大长度.例如"(()()))"返回"(()())"的长度6*/
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	int LongestValidParentheses(const string& s){
		stack<int> stk;
		int max_len=0;
		int last=-1;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(')
				stk.push(i);
			else if(!stk.empty()){
				stk.pop();
				if(stk.empty())
					max_len=max(max_len,i-last);
				else
				max_len=max(max_len,i-stk.top());
			}  else last=i;
		}
		return max_len;
	}
};

int main(){
	Solution s;
	string str("(()()()(()");
	cout<<s.LongestValidParentheses(str);
	cout<<endl;
}

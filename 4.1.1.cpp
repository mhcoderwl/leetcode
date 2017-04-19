/*给一个字符串,只包含'(','{','['和对应的右边括号,判断字符串是否合法.*/
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<stack>
using namespace std;
class Solution{
	bool IsValid(const string& input){
		string left="([{";
		string right=")]}";
		stack<char> stk;
		for(auto s:input){
			if(left.find(s)!=string::npos)
				stk.push(s);
			else{
				if(stk.empty()||stk.top()!=left[right.find(s)])
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
	}
};

int main(){
}

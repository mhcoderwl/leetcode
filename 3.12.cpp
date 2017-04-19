/*数数.比如12  读作一个2一个1记为1211
 *     1211一个1,一个2,两个1记为111221*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution{
	string CountAndSay(int n){
		string s("1");
		while(--n)
			s=getnext(s);
		return s;
	}
	string getnext(const string& s){
		stringstream ss;
		for(auto i=s.begin();i!=s.end();i++){
			auto j=find_if(i,s.end(),bind1st(not_equal_to<char>(),*i));
			ss<<distance(i,j)<<*i;
			i=j;
		}
	}
};

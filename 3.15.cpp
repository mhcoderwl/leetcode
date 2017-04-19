/*给一个字符串,里面还有大小写字母,和空格,返回最后一个单词的长度*/
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
	int LastWordLength(const string& str){
		int len=0;
		auto begin=str.rbegin();
		for(;begin!=str.rend();begin++)
			if(isalpha(*begin))
				break;
		while(begin!=str.rend()&&isalpha(*begin)){
			len++;
			begin++;
		}
		return len;
	}
};
int main(){
	Solution s;
	string str=" Hello wor Ld ";
	cout<<s.LastWordLength(str)<<endl;
}


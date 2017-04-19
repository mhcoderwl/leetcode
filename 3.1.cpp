/*给一字符串,判断是否是回文,只考虑字符不考虑其他符号.另外空字符串也算回文*/
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
class Solution{
public:
	bool isPalindrome(string s){
		if(s.empty())return true;
		transform(s.begin(),s.end(),s.begin(),(int(*)(int))tolower);
		auto left=s.begin();
		auto right=prev(s.end());
		while(left<right){
			if(!isalnum(*left))left++;
			else if(!isalnum(*right))right--;
			else if(*left!=*right)
				return false;
			else {
				left++;
				right--;
			}
		}
		return true;
	}
};
int main(){
	string s="ab: b :cba";
	Solution s1;
	if(s1.isPalindrome(s)){
		cout<<"true"<<endl;
	}
}

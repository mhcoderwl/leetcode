/*完成函数int strStr(const string& str1,const string str2)功能,找到str1中子串str2的首字符出现的位置,如果没有则返回0
 * 暴力解法O(m*n),也可以利用高效的字符串匹配算法例如KMP算法.*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
public:
	int strStr(const string& haystack,const string& needle){
		if(needle.empty())return 0;
		auto pos=haystack.begin();
		const int N=haystack.size()-needle.size()+1; 
		for(int i=0;i<N;i++){
			int j=i;
			int k=0;
			while(j<haystack.size()&&k<needle.size()&&haystack[j]==needle[k]){
				k++;
				j++;
			}
			if(k==needle.size())
				return i;
		}
		return -1;
	}
};

/*KMP算法.时间复杂度O(M+N),空间复杂度O(M)*/
/*
class Solution{
public:
	//KMP主程序,用预处理过的next数组来控制每次不匹配的偏移量,如果莫一个字符不匹配,那么直接找到needle中某一个字符和haystack的下一个字符匹配,这样永远不会回头,总匹配次数最多为字符串长度.
	int strStr(const string& haystack,const string& needle){
		if(needle.size()==0)return 0;
		vector<int> next=compute_next(needle);
		int q=-1;
		for(int i=0;i<haystack.size();i++){
			while(q>-1&&haystack[i]!=needle[q+1])
				q=next[q];
			
			if(haystack[i]==needle[q+1])
				q++;
			if(q==(needle.size()-1))
				return i-q;
		}return -1;
	}
//用来计算next数组的算法.具体原理参照算法导论32章.
	static vector<int> compute_next(const string& s){
		vector<int> next(s.size(),-1);
		if(s.size()==0)return next;
		int q=-1;
		for(int i=1;i<s.size();i++){
			while(q>-1&&s[i]!=s[q+1])//不匹配时要返回的位置
				q=next[q];
			if(s[i]==s[q+1])//如果下个字符匹配,那么直接继承之前的已匹配区域.
				q++;
			next[i]=q;
		}
		return next;
	}
};

*/
int main(){
	string s1="ababcd";
	string needle="abc";
	Solution s;
	cout<<s.strStr(s1,needle)<<endl;
}



		

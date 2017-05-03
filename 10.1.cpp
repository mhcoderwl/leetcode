//给一个字符串,分割使得分割后的所有子串都为回文//
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//深搜
class Solution{
public:
	vector<vector<string>> partition(string s){
		vector<vector<string>> result;
		vector<string> cur;
		dfs(s,result,cur,0,1);
		return result;
	}
	void dfs(string& s,vector<vector<string>>& result,vector<string>& cur,int prev,int start){
		auto isPalindrome=[](const string& s){
			auto begin=s.begin();
			auto end=std::prev(s.end());
			while(begin<=end){
				if(*begin!=*end)
					return false;
				begin++;
				end--;
			}
			return true;
		};	
		if(start==s.size()){
			if(isPalindrome(s.substr(prev,start-prev))){
				cur.push_back(s.substr(prev,start-prev));
				result.push_back(cur);
				cur.pop_back();
			}
		return;
		}
		dfs(s,result,cur,prev,start+1);
		if(isPalindrome(s.substr(prev,start-prev))){
			cur.push_back(s.substr(prev,start-prev));
			dfs(s,result,cur,start,start+1);
			cur.pop_back();
		}
	}
};
//DP
class Solution1{
public:
	vector<vector<string>> partition(string s){
		const int n=s.size();
		bool p[n][n];
		fill_n(&p[0][0],n*n,0);
		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++)
				p[i][j]=s[i]==s[j]&&(j-i<2||p[i+1][j-1]);
		vector<vector<string>> result[n];
		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++)
				 if(p[i][j]){
					 if(j<n-1){
					 	for(auto str:result[j+1]){
					 	str.insert(str.begin(),s.substr(i,j-i+1));
						result[i].push_back(str);
						}
					 }else{
						result[i].push_back(vector<string>{s.substr(i,j-i+1)});
					}
				 }
		return result[0];
	}
};

					 
















int main(){
	Solution s;
	string str="aab";
	auto result=s.partition(str);
	for(auto i:result){
		for(auto j:i)
			cout<<j<<' ';
		cout<<endl;
	}
};




	

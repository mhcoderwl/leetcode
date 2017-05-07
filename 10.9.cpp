//给n对括号,组成有效括号串
//例如:n=2,返回"()()""(())"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<string> generateParenthesis(int n){
		vector<string> result;
		string cur;
		dfs(result,cur,n,n);
		return result;
	}

	void dfs(vector<string>& result,string& cur,int left_gap,int right_gap){
		if(left_gap>right_gap||left_gap<0||right_gap<0)
			return;
		if(left_gap==0){
			string s(cur);
			result.push_back(s.append(right_gap,')'));
			return;
		}
		cur.push_back('(');
		dfs(result,cur,left_gap-1,right_gap);
		cur.pop_back();
		cur.push_back(')');
		dfs(result,cur,left_gap,right_gap-1);
		cur.pop_back();
	}
};

int main(){
	Solution s;
	auto result=s.generateParenthesis(3);
	for(auto i:result)
		cout<<i<<endl;
}
		




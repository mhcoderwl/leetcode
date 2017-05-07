//给一个字符串包含若干数字,返回所有有效的IP组合,例如:"25525511135"返回"255.255.11.135""255.255.111.35"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
	vector<string> ValidIP(const string& s){
		vector<string>result;
		vector<string>cur;
		dfs(s,result,cur,0);
		return result;
	}

	void dfs(string s,vector<string>& result,vector<string> &cur,int start){
		if(start==s.size()){
			result.push_back(cur[0]+"."+cur[1]+"."+cur[2]+"."+cur[3]+".");
			return;
		}
		if((4-cur.size())*3<(s.size()-start))
			return;
		if((4-cur.size())>(s.size()-start))
			return;
		int num=0;
		for(int i=0;i<3;i++){
			num=num*10+(s[i+start]-'0');
			if(num<0||num>255)continue;
			cur.push_back(s.substr(start,i+1));
			dfs(s,result,cur,start+i+1);
			cur.pop_back();
			if(num==0)break;
		}
	}
};

int main(){}

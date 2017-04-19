/*给一组字符串,返回所有为回文构词法组的字符串.
 * 例如 "ate","eat","tea","option"
 * return "ate","eat","tea"*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
usng namespace std;
class Solution{
	vector<string> anagrams(vector<string> &strs){
		unordered_map<string,vector<string> > group;
		for(s:strs){
			string key=s;
			sort(key.begin(),key.end());
			group[key].push_back(s);
		}
		vector<string> result;
		for(auto i=group.cbeign();it!=group.cend();it++){
			if(i->second.size()>1)
				result.insert(result.end(),it->second.begin(),it->second.end());
		}
		return result;
	}
};

/*给一个绝对路径,简化它.
 * 比如:path="/home/", ->"/home"
 * path="/a/./b/../../c/", ->"/c" */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	string SimplifyPath(const string& path){
		vector<string> dirs;
		for(auto i=path.begin();i!=path.end();i++){
			auto j=find(i,path.end(),'/');
			string str=string(i,j);
			if(str!="."&&!str.empty()){
				if(str==".."){
					if(!dirs.empty())
						dirs.pop_back();
				}else dirs.push_back(str);
			}i=j;
		}
		string result;
		if(dirs.empty())
			result+="/";
		else {
			for(auto s:dirs){
				result+="/"+s;
			}
		}
		return result;
	}
};
int main(){
	Solution s;
	string path="//home/../../home/./wangliang//Blog/";
	cout<<s.SimplifyPath(path)<<endl;
}





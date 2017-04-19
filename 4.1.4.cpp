#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution{
public:
	int evalRPN(vector<string>& tokens){
		stack<int> stk;
		for(auto token:tokens){
			if(!is_operator(token)){
				stk.push(stoi(token));
			}else{
				int y=stk.top();
				stk.pop();
				int x=stk.top();
				stk.pop();
				if(token=="+")
					x+=y;
				else if(token=="-")
					x-=y;
				else if(token=="*")
					x*=y;
				else x/=y;
				stk.push(x);
			}
		}
			return stk.top();
		
	}
	bool is_operator(const string& op){
		string s="+-*/";
		return op.length()==1&&s.find(op)!=string::npos;
	}
};

int main(){
	Solution s;
	vector<string> expression={"2","1","+","3","*"};
	cout<<s.evalRPN(expression);
	cout<<endl;
}


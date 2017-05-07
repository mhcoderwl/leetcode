//给一个2维字母表,给定一个单词返回在表中是否能找到//
//例如:ABCE
//     SFCS
//     ADEE
//    word="ABCCED" return true.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	bool exist_word(vector<vector<char>> &board,const string& target){
		const int N=board.size();
		const int M=board[0].size();
		vector<vector<bool>> visited(N,vector<bool>(M,false));
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(dfs(board,i,j,target,0,visited))
					return true;
		return false;
	}

	bool dfs(vector<vector<char>>& board,int i,int j,const string& target,int step,vector<vector<bool>>& visited){
		if(step==target.length())
			return true;
		if(visited[i][j]==true)
			return false;
		if(i<0||j<0||i>=board.size()||j>=board[0].size())
			return false;
		if(board[i][j]!=target[step])
			return false;
		visited[i][j]=true;
		bool result=dfs(board,i+1,j,target,step+1,visited)||
				dfs(board,i,j+1,target,step+1,visited)||
				dfs(board,i,j-1,target,step+1,visited)||
				dfs(board,i-1,j,target,step+1,visited);
		visited[i][j]=false;
		return result;
	}
};
int main(){}
		
		

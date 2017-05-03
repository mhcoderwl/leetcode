//一个2维数组只有"X"和'O',如果'O'区域被x包围则需要被改成'+'
//思路:用广搜,起点为边上元素向内部搜索
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution{
public:
	void solve(vector<vector<char>> &board){
		if(board.empty())return;
		int m=board.size();
		int n=board[0].size();
		for(int i=0;i<n;i++){
			bfs(board,0,i);
			bfs(board,m-1,i);
		}
		for(int i=1;i<m-1;i++){
			bfs(board,i,0);
			bfs(board,i,n-1);
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]=='O')
					board[i][j]=='X';
				else if(board[i][j]=='+')
					board[i][j]=='O';
			}
		}
	}

	void bfs(vector<vector<char>> &board,int i,int j){
	typedef pair<int,int> state_t;
	queue<state_t>q;
	const int m=board.size();
	const int n=board[0].size();
	auto state_is_valid=[&](const state_t& s){
		const int x=s.first;
		const int y=s.second;
		if(0<=x<=m-1&&0<=y<=n-1&&board[x][y]=='O')
			return true;
		else return false;
	};
	auto state_extend=[&](const state_t& s){
		vector<state_t> new_state_ts={state_t(s.first-1,s.second),
						state_t(s.first,s.second-1),
						state_t(s.first+1,s.second),
						state_t(s.first,s.second+1)};
		vector<state_t>result;
		for(int i=0;i<new_state_ts.size();i++)
			if(state_is_valid(new_state_ts[i])){
				board[new_state_ts[i].first][new_state_ts[i].second]=='+';
				result.push_back(new_state_ts[i]);
			}
		return result;
	};
	state_t start(i,j);
	if(state_is_valid(start)){
		board[i][j]=='+';
		q.push(start);
	}
	while(!q.empty()){
		const auto p=q.front();
		q.pop();
	for(auto next_state_t:state_extend(p))
		q.push(next_state_t);
	}
	}


	

};
int main(){}

//给两个单词和一个字典,找到最短变换距离.每次只能变一个字母,必须按照字典中的路径走
#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_set>
using namespace std;
struct state_t{
	string word;
	int level;
	state_t(){word="";level=0;}
	state_t(const string& word,int level){
		this->word=word;
		this->level=level;
	}
	bool operator==(const state_t &other)const{
		return this->word==other.word;
	}
};

namespace std{
template<> struct hash<state_t>{
	public:
		size_t operator()(const state_t& s)const {
			return str_hash(s.word);
		}
	private:
		hash<string>str_hash;
	};
}


class Solution{
public:
	int ladderLength(const string& start,const string& end,const unordered_set<string>&dict){
		queue<state_t> q;
		unordered_set<state_t> visited;//用于判重
		auto state_is_valid=[&](const state_t& s){
			return dict.find(s.word)!=dict.end()||s.word==end;
		};
		auto state_is_target=[&](const state_t &s){return s.word==end;};
		auto state_extend=[&](const state_t& s){
			unordered_set<state_t> result;
			for(int i=0;i<s.word.size();i++){
				state_t new_state(s.word,s.level+1);
				for(char c='a';c<='z';c++){
					if(c==new_state.word[i])continue;
					swap(c,new_state.word[i]);
					if(state_is_valid(new_state)&&visited.find(new_state)==visited.end())
						result.insert(new_state);
					swap(c,new_state.word[i]);
				}
			}
			return result;
		};
		state_t start_state(start,0);
		q.push(start_state);
		visited.insert(start_state);
		while(!q.empty()){
			const auto state=q.front();
			q.pop();
			if(state_is_target(state))
				return state.level+1;
			const auto& next_states=state_extend(state);
			for(const auto& new_state:next_states){
				q.push(new_state);
				visited.insert(new_state);
			}
			return 0;
		}
	}
};
int main(){
}





		


#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include"2.1.13.cpp"
using namespace std;

int main(int argc, char** argv){
	vector<int> a;
	a.push_back(10);
	a.push_back(5);
	a.push_back(3);
	a.push_back(5);
	Solution s;
	for(auto i:s.kth_permutation(5,50))
		cout<<i<<",";
	cout<<endl;
	return 0;
}


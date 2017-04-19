#include<iostream>
#include<vector>
using namespace std;
void hist(vector<int>& num,vector<int>& result){
	for(int i=0;i<num.size();i++)
		result[num[i]]++;
}
int main(){
	vector<int> result(1001,0);
	int size=0;
	cin>>size;
	vector<int> num;
	for(int i=0,a=0;i<size;i++){
		cin>>a;
		num.push_back(a);
	}
	hist(num,result);
	for(int i=0;i<result.size();i++){
		int left=0,right=0;
		for(int j=0;j<i;j++)
			left+=result[j];
		for(int k=i+1;k<result.size();k++)
			right+=result[k];
		if(left==right){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
	


/*给两个二进制的字符串,返回他们的和(依旧是二进制字符串)*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	string addBinary(string a,string b){
		string result;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int n=a.length()>b.length()?a.length():b.length();
		int carry=0;
		for(int i=0;i<n;i++){
			const int ai=i<a.length() ? (a[i]-'0'):0;
			const int bi=i<b.length() ? (b[i]-'0'):0;
			int val=(ai+bi+carry)%2;
			carry=(ai+bi+carry)/2;
			result.insert(result.begin(),val+'0');
		}if(carry==1)
			result.insert(result.begin(),'1');
		return result;
	}
};

int main(){
	Solution s;
	cout<<s.addBinary("101","11")<<endl;
}

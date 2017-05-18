#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
	int waysTransform(int num){
		vector<int> bits;
		while(num!=0){
			bits.push_back(num%10);
			num/=10;
		}
		const int m=bits.size();
		int f1=1;
		int f2=1,temp;
		for(int i=m-2;i>=0;i--){
			temp=f2;
			if(bits[i]==0){
				if (bits[i+1]>2)
					return -1;
				f2=f1;
			}
			else{
			if(bits[i+1]*10+bits[i]<=26)
				f2=f2+f1;
			}
			f1=temp;
		}
		return f2;
		
	}
};

int main(){
	Solution s;
	cout<<s.waysTransform(1233)<<endl;
}
	



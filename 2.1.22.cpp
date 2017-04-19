/*给N个孩子发糖,每个孩子都有一个比值,比值比邻居高的孩子要比那个孩子糖多,每个孩子至少一个,最少要发多少个糖*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//从左到右扫一遍,每个比之前大的多,然后从右到左扫一遍,保证每个比之前大的多.
class Solution{
public:
	int send_candy(vector<int>& child){
		size_t n=child.size();
		vector<int> num(n,0);
		for(int i=1;i<n;i++)
			if(child[i]>child[i-1])
				num[i]=num[i-1]+1;
		for(int i=n-2;i>=0;i--)
			if(child[i]>child[i+1])
				num[i]=max(num[i],num[i+1]+1);
		return accumulate(num.begin(),num.end(),n);
	}
};


int main(){
	vector<int> a={1,6,6,4,3,8,2,6,5};
	Solution s;
	cout<<s.send_candy(a)<<endl;
}


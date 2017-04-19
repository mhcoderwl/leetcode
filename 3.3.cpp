/*将一个字符串转换成一个整数
 * 思路:先除去第一个非空格字符前的空格,然后将数字字符翻译成数字.
 * 首先判断正负,然后先判断字符是否是数字,再判断加上这个数会不会超过最大int的限制,最后再累加上*/
#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
class Solution{
public:
	int Myatoi(const string& str){
		int num=0;
		int sign=1;
		const int n=str.length();
		int i=0;
		while(str[i]==' '&&i<n)i++;
		if(str[i]=='-'){
			i++;
			sign=-1;
		}else if(str[i]=='+')
			i++;
		for(;i<n;i++){
			if(str[i]<'0'||str[i]>'9')
				break;
			if(num>INT_MAX/10||(num==INT_MAX/10&&(str[i]-'0')>INT_MAX%10))
				return sign==-1?INT_MIN:INT_MAX;
			num=num*10+str[i]-'0';
		}
		return num*sign;
	}
};

int main(int argc,char** argv){
	Solution s;
	string str=argv[1];
	cout<<INT_MAX;
	int i=s.Myatoi(str);
	cout<<i<<endl;
}
	
		
		


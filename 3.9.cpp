/*给一个字符串,如果为数值的则返回true
 * 思路:利用标准库strtod()*/
#include<iostream>
#include<stdlib.h>
class Solution{
	bool IsNumber(const string& s){
		return IsNumber(s.c_str());
	}
	bool IsNumber(const char* s){
		char* endptr;
		strtod(s,&endptr);
		if(endptr==NULL)
			return false;
		for(;*endptr;endptr++)
			if(!isspace(*endptr))return false;
		return true;
	}
};



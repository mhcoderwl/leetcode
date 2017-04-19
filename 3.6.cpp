/*.代表单个任意字符,*代表若干个之前的字符*/
#include<iostream>
#include<<string>
class Solution{
public:
	bool IsMatch(const string& s,const string& p){
		return IsMatch(s.c_str(),p.c_str());
	}

private:
	bool IsMatch(const char* s,const char* p){
		if(*p=='\0')return *s=='\0';
		if(*(p+1)!='*'){
			if(*s==*p||(*p=='.'&&*s!='\0'))
				return IsMatch(s+1,p+1);
			else
				return false;
		}else{
		       while(*s==*p||(*p=='.'||*s!='\0')){
			       if(IsMatch(s,p+2))
				       return true;
			       s++;
		       }
		       return IsMatch(s,p+2);
		}
	}
};


				       
	

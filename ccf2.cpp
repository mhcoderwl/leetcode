#include<iostream>
#include<vector>
using namespace std;

int main(){
	double bit[10];
	bit[0]=0.03;
	bit[1]=0.1;
	bit[2]=0.2;
	bit[3]=0.25;
	bit[4]=0.3;
	bit[5]=0.35;
	bit[6]=0.45;
	int change[10];
	int count[10];
	count[0]=3500;
	count[1]=5000;
	count[2]=8000;
	count[3]=12500;
	count[4]=38500;
	count[5]=58500;
	count[6]=83500;
	change[0]=3500;
	change[1]=change[0]+1500*(1-bit[0]);
	change[2]=change[1]+3000*(1-bit[1]);
	change[3]=change[2]+4500*(1-bit[2]);
	change[4]=change[3]+26000*(1-bit[3]);
	change[5]=change[4]+20000*(1-bit[4]);
	change[6]=change[5]+25000*(1-bit[5]);
	int wage=0;
	cin>>wage;
	int level=0;
	while(wage>change[level]&&level<7)
		level++;
	level--;
	if(level<0)
		cout<<wage;
	else
		cout<<(count[level]+(wage-change[level])/(1-bit[level]));

	return 0;
}
		
	
	
	 

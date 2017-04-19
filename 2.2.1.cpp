/*用链表表示两个数,每个值代表数的一位,求两个数相加后的链表*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* AddTwoNumbers(ListNode* a,ListNode* b){
		ListNode result(-1);
		ListNode* s1=a;
		ListNode* s2=b;
		ListNode* s3=&result;
		int nums1=0,nums2=0,count=0;
		while(s1!=NULL||s2!=NULL){
			if(s1==NULL)
				nums1=0;
			else nums1=s1->val;
			if(s2==NULL)
				nums2=0;
			else nums2=s2->val;
			int sum=nums1+nums2+count;
			int add=0;
			count=sum/10;
			add=sum%10;
			s3->next=new ListNode(add);
			s3=s3->next;
			if(s1!=NULL)
			s1=s1->next;
			if(s2!=NULL)
			s2=s2->next;
		}
		if(count!=0){
			s3->next=new ListNode(count);
		}
		return result.next;
	}
};
int main(){
	ListNode s1(8);
	s1.next=new ListNode(3);
	ListNode s2(4);
	Solution s;
	ListNode* s3=s.AddTwoNumbers(&s1,&s2);
	while(s3!=NULL){
		cout<<s3->val<<' ';
		s3=s3->next;
	}
	cout<<endl;
}


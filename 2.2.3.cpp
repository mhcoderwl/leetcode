/*给一个链表和一个数,将链表分成两个部分,小于的在前,大于或等于的在后.
 * 思路:创两个链表,遍历一遍,然后再接上.*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* Partition(ListNode* head,int x){
		ListNode small_pummy(-1);
		ListNode large_pummy(-1);
		ListNode* small_cur=&small_pummy;
		ListNode* large_cur=&large_pummy;
		ListNode* cur;
		for(cur=head;cur!=NULL;cur=cur->next){
			if(cur->val<x){
				small_cur->next=cur;
				small_cur=cur;
			}else{
				large_cur->next=cur;
				large_cur=cur;
			}
		}
		small_cur->next=large_pummy.next;
		large_cur->next=NULL;
		return small_pummy.next;
	}
};
int main(){
	ListNode s1(3);
	ListNode s2(4);
	ListNode s3(2);
	s1.next=&s2;
	s2.next=&s3;
	Solution s;
	ListNode* s4=s.Partition(&s1,4);
	while(s4!=NULL){
		cout<<s4->val<<' ';
		s4=s4->next;
	}
	cout<<endl;
}

	

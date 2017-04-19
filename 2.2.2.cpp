/*反转链表的位置m-位置n,要求原址.
 * 思路:将后面要反转的数逐个往头插*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
	ListNode* ReverseBetween(ListNode* head,int m,int n){
		ListNode* dummy(-1);
		dummy.next=head;
		ListNode* prev=&dummy;
		for(int i=0;i<m-1;i++)
			prev=prev->next;
		ListNode* const head1=prev;
		prev=prev->next;
		ListNode* cur=prev->next;
		for(int i=m;i<n;i++){
			prev->next=cur->next;
			cur->next=head1->next;
			head1->next=cur;
			cur=prev->next;
		}
		return head;



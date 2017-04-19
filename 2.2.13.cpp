/*给一条链表,顺序:L1->L2->..->Ln,改成:L1->Ln->L2->Ln-1->...
 * 思路:如果不是原址,则可以用一个栈一个队列,然后两个分别弹出节点相连
 * 原址的话中间断开,反转后面链表,然后两个链表合并.*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
	ListNode* ReorderList(ListNode* head){
		if(head==NULL||head->next==NULL)return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode* head2;
		int len;
		for(ListNode* p=&dummy;p!=NULL;p=p->next)
			len++;
		head2=&dummy;
		for(int i=0;i<len/2;i++)
			head2=head2->next;
		head2->next=NULL;
		head2=reverse(head2);
		merge(head,head2);
		return head;
	}

};	

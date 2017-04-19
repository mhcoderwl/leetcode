//排序一个链表要求时间O(nlogn),空间O(1)
//思路:单链表用归并,双链表用快排.
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
//归并排序
class Solution{
public:
	ListNode* sortList(ListNode* head){
		if(head==NULL)return head;
		if(head->next==NULL)return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode* slow=&dummy;
		ListNode* fast=&dummy;
		while(fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		ListNode* mid=slow->next;
		slow->next=NULL;
		ListNode* l1=sortList(head);
		ListNode* l2=sortList(mid);
		return mergeList(l1,l2);
	}
	ListNode* mergeList(ListNode* head1,ListNode* head2){
		if(head1==NULL)return head2;
		if(head2==NULL)return head1;
		ListNode dummy(-1);
		ListNode* cur=&dummy;
		while(head1!=NULL&&head2!=NULL){
			if(head1->val<head2->val){
				cur->next=head1;
				head1=head1->next;
			}else{
				cur->next=head2;
				head2=head2->next;
			}
			cur=cur->next;
		}
		if(head1==NULL)cur->next=head2;
		else cur->next=head1;
	
		return dummy.next;
	}
};

int main(){
	Solution s;
	ListNode a1(3);
	ListNode a2(2);
	ListNode a3(1);
	a1.next=&a2;
	a2.next=&a3;
	auto p=s.sortList(&a1);	
	while(p!=NULL){
		cout<<p->val<<endl;
		p=p->next;
	}
}


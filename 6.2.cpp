//给两个有序链表,归并//
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* mergeTwoList(ListNode* head1,ListNode* head2){
		ListNode dummy(-1);
		ListNode* cur;
		ListNode* l1=head1;
		ListNode* l2=head2;
		for(cur=&dummy;l1!=NULL&&l2!=NULL;cur=cur->next){
			if(l1->val>l2->val){
			cur->next=l2;
			l2=l2->next;
			}else{
				cur->next=l1;
				l1=l1->next;
			}
		}if(l1!=NULL)cur->next=l1;
		else cur->next=l2;
		return dummy.next;
	}
};

int main(){
	Solution s;
	ListNode a1(1);
	ListNode b1(2);
	ListNode a2(3);
	ListNode b2(4);
	a1.next=&a2;
	b1.next=&b2;
	auto p=s.mergeTwoList(&a1,&b1);
	while(p!=NULL){
		cout<<p->val<<endl;
		p=p->next;
	}
}
			

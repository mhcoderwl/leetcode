/*给一个链表,交换两个相邻的节点*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* SwapPairs(ListNode* head){
		if(head==NULL)return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode* cur=&dummy;
		ListNode* prev=cur;
		cur=cur->next;
		while(cur!=NULL){
			if(cur->next!=NULL){
				ListNode* p=cur->next;
				prev->next=p;
				cur->next=p->next;
				p->next=cur;
				prev=cur;
				cur=cur->next;
			}else break;
		}
		return dummy.next;
	}
};

int main(){
	Solution s;
	ListNode s1(2);
	ListNode s2(3);
	ListNode s3(4);
	ListNode s4(5);
	ListNode s5(6);
	s1.next=&s2;
	s2.next=&s3;
	s3.next=&s4;
	s4.next=&s5;
	ListNode* p=s.SwapPairs(&s1);
	while(p!=NULL){
		cout<<p->val<<' ';
		p=p->next;
	}cout<<endl;
}

				


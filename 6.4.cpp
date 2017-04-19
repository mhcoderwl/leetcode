//用插入排序 排序一个链表
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* sortList(ListNode* head){
		if(head==NULL)return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode* cur=&dummy;
		while(cur->next!=NULL){
			ListNode* p=&dummy;
			while(p->next->val<cur->next->val&&p->next!=cur->next)
				p=p->next;
			if(p==cur){
				cur=cur->next;
				continue;
			}
			//insert
			ListNode* temp1=p->next;
			p->next=cur->next;
			cur->next=cur->next->next;
			p->next->next=temp1;
		}
		return dummy.next;
	}
};
class Solution1{
public:
ListNode* sortList(ListNode* head){
	ListNode dummy(INT_MIN);
	//dummy.next=head;
	for(ListNode* cur=head;cur!=NULL;){
		auto pos=findInsertPos(&dummy,cur->val);
		ListNode* tmp=cur->next;
		cur->next=pos->next;
		pos->next=cur;
		cur=tmp;
	}
	return dummy.next;
	}
	ListNode* findInsertPos(ListNode* head,int x){
		ListNode* pre=NULL;
		for(ListNode* cur=head;cur!=NULL&&cur->val<=x;pre=cur,cur=cur->next);
		return pre;
	}
};
	


int main(){
	Solution s;
	ListNode a1(4);
	ListNode a2(3);
	ListNode a3(2);
	a1.next=&a2;
	a2.next=&a3;
	auto p=s.sortList(&a1);
	while(p!=NULL){
		cout<<p->val<<endl;
		p=p->next;}

		
}

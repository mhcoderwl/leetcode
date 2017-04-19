/*给一个链表,在指定的地方断开,然后将后面的部分接到头上.
 * */
#include<iostream>
using namespace  std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* RotateList(ListNode* head,int k){
		if(head==NULL)return head;
		ListNode dummy(-1);
		ListNode* cur=&dummy;
		cur->next=head;
		int len=0;
		ListNode* p;
		for(p=cur;p->next!=NULL;p=p->next)
		len++;
		p->next=cur->next;
		for(int i=0;i<len-k;i++)
			cur=cur->next;
		ListNode* newhead=cur->next;
		cur->next=NULL;
		return newhead;
	}
};

int main(){
	Solution s;
	ListNode s1(1);
	ListNode s2(2);
	ListNode s3(3);
	s1.next=&s2;
	s2.next=&s3;
	ListNode* p=s.RotateList(&s1,1);
	while(p!=NULL){
		cout<<p->val<<' ';
		p=p->next;
	}
	cout<<endl;
}




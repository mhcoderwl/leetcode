/*给一个链表,删除倒数第N个节点.
 */
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* RmNthfromEnd(ListNode* head,int n){
		if(head==NULL)return head;
		ListNode dummy(-1);
		ListNode* cur=&dummy;
		cur->next=head;
		ListNode* p;
		int len=0;
		for(p=cur;p->next!=NULL;p=p->next)
			len++;
		for(int i=0;i<len-n;i++)
			cur=cur->next;
		p=cur->next;
		cur->next=p->next;
		delete p;
		return head;
	}
};

int main(){
	Solution s;
	ListNode* s1=new ListNode(1);
	s1->next=new ListNode(2);
	s1->next->next=new ListNode(3);
	ListNode* p=s.RmNthfromEnd(s1,2);
	while(p!=NULL){
		cout<<p->val<<' ';
		p=p->next;
	}
	cout<<endl;
}
